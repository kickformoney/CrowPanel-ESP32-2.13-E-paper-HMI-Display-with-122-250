#pragma once

#include <Arduino.h>

#include "../graphics/WeatherIcons.h"

struct WeatherData
{
    String city;

    float tempC;
    float tempF;

    float feelsLikeC;
    float feelsLikeF;

    int humidity;

    float windSpeed;

    WeatherIcon icon;

    String description;

    time_t timestamp;
};

// Connects to Wi-Fi using the credentials in config.h, waiting a few
// seconds before giving up for this cycle.  Safe to call, even if a
// connection attempt already timed out this cycle.  ReadWeather() will
// just fail with a Wi-Fi error message
void ConnectWiFi();

// Fetches the current weather from OpenWeatherMap and, on success, fills
// in weatherData and returns True.  On failure, weatherData is left
// unchanged and errorMessage is set to a short string suitable for
// on-screen display (e.g. "Err: Wi-Fi", "Err: 404")
bool ReadWeather(WeatherData &weatherData, String &errorMessage);
