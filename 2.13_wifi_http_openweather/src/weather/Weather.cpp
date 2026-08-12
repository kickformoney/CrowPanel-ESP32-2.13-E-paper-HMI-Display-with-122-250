#include "Weather.h"

#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

#include "../../config.h"
#include "../Debug.h"

namespace
{
    constexpr unsigned long WIFI_CONNECT_TIMEOUT_MS = 20000; // 20 seconds

    // Maximum number of times to retry a failed API request before giving
    // up for this cycle. Prevents the caller from hanging indefinitely on
    // spotty Wi-Fi, or a persistent API error
    constexpr int MAX_HTTP_RETRIES = 4;

    // The API is always queried in metric units; imperial values are then
    // computed locally via a conversion (see ReadWeather() below)
    constexpr char OWM_UNITS_PARAM[] = "metric";

    // Keeps track of the last HTTP status code seen, so httpGETRequest() 
	// can report it back to ReadWeather() without changing its return type
    int lastHttpResponseCode = 0;

    String BuildWeatherUrl()
    {
        if (USE_PRECISE_COORDINATES)
        {
            return "http://api.openweathermap.org/data/2.5/weather?lat=" + String(LATITUDE) +
                   "&lon=" + String(LONGITUDE) +
                   "&APPID=" + String(API_KEY) +
                   "&units=" + String(OWM_UNITS_PARAM);
        }

        return "http://api.openweathermap.org/data/2.5/weather?q=" + String(CITY_NAME) +
               "," + String(ZIP_CODE) +
               "&APPID=" + String(API_KEY) +
               "&units=" + String(OWM_UNITS_PARAM);
    }

    // Makes an HTTP GET request and returns the response body ("{}" if the
    // request failed outright).  Sets lastHttpResponseCode and, on failure,
    // errorMessage
    String httpGETRequest(const char *url, String &errorMessage)
    {
        WiFiClient client;
        HTTPClient http;

        http.begin(client, url);

        // If the server doesn't respond in 4 seconds, abort to conserve
        // battery power
        http.setTimeout(4000);

        // Drop the connection immediately after completion
        http.setReuse(false);

        lastHttpResponseCode = http.GET();
        String payload = "{}";

        if (lastHttpResponseCode > 0)
        {
            DEBUG_PRINT("HTTP Response code: ");
            DEBUG_PRINTLN(lastHttpResponseCode);

            payload = http.getString();

            if (lastHttpResponseCode != 200)
            {
                JSONVar errorObject = JSON.parse(payload);
                if (JSON.typeof(errorObject) != "undefined")
                {
                    String apiMessage = JSON.stringify(errorObject["message"]);
                    apiMessage.replace("\"", "");
                    DEBUG_PRINT("API Error: ");
                    DEBUG_PRINTLN(apiMessage);
                }
                errorMessage = "Err: " + String(lastHttpResponseCode);
            }
        }
        else
        {
            DEBUG_PRINT("Error code: ");
            DEBUG_PRINTLN(lastHttpResponseCode);
            errorMessage = "Err: " + String(lastHttpResponseCode);
        }

        http.end();
        return payload;
    }
}

void ConnectWiFi()
{
    // Don't persist Wi-Fi credentials to NVS flash on every begin() call.
    // The SSID/pass/BSSID are set in config.h, so there's nothing to
    // remember between boots
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);

    // Disable Wi-Fi modem power saving during the connect and fetch burst
    // to minimize wake time
    WiFi.setSleep(false);

    if (USE_WIFI_BSSID)
    {
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL, WIFI_BSSID);
    }
    else
    {
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    }

    DEBUG_PRINTLN("Connecting");

    unsigned long wifiStart = millis();
    while (WiFi.status() != WL_CONNECTED && (millis() - wifiStart) < WIFI_CONNECT_TIMEOUT_MS)
    {
        delay(250);
        DEBUG_PRINT(".");
    }
    DEBUG_PRINTLN("");

    if (WiFi.status() == WL_CONNECTED)
    {
        DEBUG_PRINT("Connected to Wi-Fi network with IP Address: ");
        DEBUG_PRINTLN(WiFi.localIP());
    }
    else
    {
        DEBUG_PRINTLN("Wi-Fi connect timed out for this cycle");
    }
}

bool ReadWeather(WeatherData &weatherData, String &errorMessage)
{
    errorMessage = "";

    if (WiFi.status() != WL_CONNECTED)
    {
        DEBUG_PRINTLN("Wi-Fi Disconnected");
        errorMessage = "Err: Wi-Fi";
        return false;
    }

    String weatherUrl = BuildWeatherUrl();
    DEBUG_PRINT("Target API Endpoint: ");
    DEBUG_PRINTLN(weatherUrl);

    lastHttpResponseCode = 0;
    String jsonBuffer;
    int retryCount = 0;

    while (lastHttpResponseCode != 200 && retryCount < MAX_HTTP_RETRIES)
    {
        jsonBuffer = httpGETRequest(weatherUrl.c_str(), errorMessage);

        if (lastHttpResponseCode == 200)
        {
            break;
        }

        retryCount++;
        if (retryCount < MAX_HTTP_RETRIES)
        {
            delay(500);
        }
    }

    if (lastHttpResponseCode != 200)
    {
        if (errorMessage.length() == 0)
        {
            errorMessage = "Failure: " + String(lastHttpResponseCode);
        }
        DEBUG_PRINTLN("Giving up on this fetch cycle");
        return false;
    }

    DEBUG_PRINTLN(jsonBuffer);
    JSONVar myObject = JSON.parse(jsonBuffer);

    if (JSON.typeof(myObject) == "undefined")
    {
        DEBUG_PRINTLN("Parsing input failed!");
        errorMessage = "JSON parse failed";
        return false;
    }

    int conditionId = (int)myObject["weather"][0]["id"];

    // City name is always taken from config.h rather than the API
    // response.  The API doesn't necessarily return the correct city
	// name when queried using GPS coordinates
    weatherData.city = CITY_NAME;

    weatherData.description = JSON.stringify(myObject["weather"][0]["main"]);
    weatherData.description.replace("\"", "");

    weatherData.timestamp = (time_t)(uint32_t)myObject["dt"];

    // The API was queried in metric units; both C and F are computed here, once
    weatherData.tempC = atof(JSON.stringify(myObject["main"]["temp"]).c_str());
    weatherData.tempF = (weatherData.tempC * 1.8f) + 32.0f;

    weatherData.feelsLikeC = atof(JSON.stringify(myObject["main"]["feels_like"]).c_str());
    weatherData.feelsLikeF = (weatherData.feelsLikeC * 1.8f) + 32.0f;

    weatherData.humidity = (int)myObject["main"]["humidity"];
    weatherData.windSpeed = atof(JSON.stringify(myObject["wind"]["speed"]).c_str());

    weatherData.icon = WeatherIconFromConditionCode(conditionId);

	// Print debugging info to the Serial Monitor window
    DEBUG_PRINT("weather: ");
    DEBUG_PRINTLN(weatherData.description);
    DEBUG_PRINT("tempC: ");
    DEBUG_PRINTLN(weatherData.tempC);
    DEBUG_PRINT("humidity: ");
    DEBUG_PRINTLN(weatherData.humidity);
    DEBUG_PRINT("feelsLikeC: ");
    DEBUG_PRINTLN(weatherData.feelsLikeC);
    DEBUG_PRINT("windSpeed: ");
    DEBUG_PRINTLN(weatherData.windSpeed);
    DEBUG_PRINT("timestamp: ");
    DEBUG_PRINTLN((uint32_t)weatherData.timestamp);

    return true;
}
