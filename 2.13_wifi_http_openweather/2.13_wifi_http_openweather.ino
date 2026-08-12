#include <Adafruit_GFX.h>
#include <Fonts/Picopixel.h>
#include "config.h"
#include "src/Debug.h"
#include "src/display/EPD.h"
#include "src/display/Layout.h"
#include "src/graphics/graphics.h"
#include "src/weather/Weather.h"

// Define an array to store black and white image data for the e-paper display buffer
extern uint8_t ImageBW[ALLSCREEN_BYTES];

// GPIO that gates power to the e-paper display
const int EPD_POWER_PIN = 7;

WeatherData weatherData;

void drawPixel(int16_t x, int16_t y, uint16_t color)
{
    EPD_DrawPoint(x, y, color ? BLACK : WHITE);
}

// Formats the temperature text according to DISPLAY_UNITS
void FormatTemperature(char *buffer, size_t size, float celsius, float fahrenheit)
{
    switch (DISPLAY_UNITS)
    {
        case DISPLAY_METRIC:
            snprintf(buffer, size, "%.1f C", celsius);
            break;

        case DISPLAY_IMPERIAL:
            snprintf(buffer, size, "%.1f F", fahrenheit);
            break;

        case DISPLAY_BOTH:
        default:
            if (DisplayImperialFirst)
            {
                snprintf(buffer, size, "%.1f F / %.1f C", fahrenheit, celsius);
            }
            else
            {
                snprintf(buffer, size, "%.1f C / %.1f F", celsius, fahrenheit);
            }
            break;
    }
}

void DrawWeatherIcon(const WeatherData &weatherData)
{
    EPD_ShowPicture(Layout.weatherIcon.x, Layout.weatherIcon.y, 128, 80,
		WeatherIconBitmap(weatherData.icon), BLACK);
}

void DrawCity(const WeatherData &weatherData)
{
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "%s ", weatherData.city.c_str());
    EPD_ShowAnchoredDotFactoryString(Layout.city, buffer, BLACK);
}

void DrawTemperature(const WeatherData &weatherData)
{
    char buffer[40];
    FormatTemperature(buffer, sizeof(buffer), weatherData.tempC, weatherData.tempF);
    EPD_ShowAnchoredDotFactoryString(Layout.currentTemperature, buffer, BLACK);
}

void DrawFeelsLike(const WeatherData &weatherData)
{
    char buffer[40];
    FormatTemperature(buffer, sizeof(buffer), weatherData.feelsLikeC, weatherData.feelsLikeF);
    EPD_ShowAnchoredDotFactoryString(Layout.feelsLike, buffer, BLACK);
}

void DrawHumidity(const WeatherData &weatherData)
{
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "%d%%", weatherData.humidity);
    EPD_ShowAnchoredDotFactoryString(Layout.humidity, buffer, BLACK);
}

void DrawWind(const WeatherData &weatherData)
{
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "%.1f m/s", weatherData.windSpeed);
    EPD_ShowAnchoredDotFactoryString(Layout.wind, buffer, BLACK);
}

// Shows the time of the last successful weather refresh (the API
// response's "dt" field), not a live clock, as the device has no
// battery-backed RTC
void DrawClock()
{
    time_t rawTime = weatherData.timestamp;
    struct tm *timeInfo = localtime(&rawTime);

    char buffer[8];
    snprintf(buffer, sizeof(buffer), "%02d%02d", timeInfo->tm_hour, timeInfo->tm_min);

    EPD_ShowAnchoredGFXString(Layout.time, buffer, &Picopixel, BLACK);
}

void DrawWeatherScreen(const WeatherData &weatherData)
{
    unsigned long screenStartMs = millis();

    DEBUG_PRINTLN("DrawWeatherScreen: EPD_Init()...");
    EPD_Init();

    DEBUG_PRINTLN("DrawWeatherScreen: EPD_ALL_Fill(WHITE)...");
    EPD_ALL_Fill(WHITE);

    unsigned long clearActivateStartMs = millis();

    DEBUG_PRINTLN("DrawWeatherScreen: EPD_Update() (clear)...");
    EPD_Update();

    DEBUG_PRINT("DrawWeatherScreen: clear activate took ");
    DEBUG_PRINT(millis() - clearActivateStartMs);
    DEBUG_PRINTLN(" ms");

    DEBUG_PRINTLN("DrawWeatherScreen: EPD_Clear_R26H()...");
    EPD_Clear_R26H();

    DEBUG_PRINTLN("DrawWeatherScreen: drawing elements...");
    EPD_ShowPicture(0, 0, 248, 122, bg, BLACK);

    DrawWeatherIcon(weatherData);
    DrawCity(weatherData);
    DrawTemperature(weatherData);
    DrawFeelsLike(weatherData);
    DrawHumidity(weatherData);
    DrawWind(weatherData);
    DrawClock();

    DEBUG_PRINTLN("DrawWeatherScreen: EPD_DisplayImage()...");
    EPD_DisplayImage(ImageBW);

    unsigned long contentActivateStartMs = millis();

    EPD_PartUpdate();
    
    DEBUG_PRINT("DrawWeatherScreen: content activate took ");
    DEBUG_PRINT(millis() - contentActivateStartMs);
    DEBUG_PRINTLN(" ms");

    DEBUG_PRINTLN("DrawWeatherScreen: EPD_Sleep()...");
    EPD_Sleep();
    DEBUG_PRINT("DrawWeatherScreen: done, total ");
    DEBUG_PRINT(millis() - screenStartMs);
    DEBUG_PRINTLN(" ms");
}

void SleepUntilNextRefresh()
{
    // Cut power to the display before sleeping
    digitalWrite(EPD_POWER_PIN, LOW);

    // Wake up after 10 minutes
    esp_sleep_enable_timer_wakeup(600ULL * 1000000ULL);

    DEBUG_PRINTLN("Entering deep sleep mode...");

    // Shut down the CPU core, memory, and radio
    esp_deep_sleep_start();
}

void setup()
{
#if DEBUG
    Serial.begin(115200);
#endif

    // Drop CPU clock from the 240 MHz default. 80 MHz is the minimum
    // required for Wi-Fi to function on an ESP32-S3
    if (BATTERY_POWERED)
    {
        setCpuFrequencyMhz(80);
    }

    // Set time zone, used when formatting the last-refresh time
    setenv("TZ", LOCAL_TIME_ZONE, 1);
    tzset();

    // Set pin 7 as an output pin and power on the display
    pinMode(EPD_POWER_PIN, OUTPUT);
    digitalWrite(EPD_POWER_PIN, HIGH);
}

void loop()
{
    ConnectWiFi();

    String errorMessage;
    if (ReadWeather(weatherData, errorMessage))
    {
        DrawWeatherScreen(weatherData);
    }
    else
    {
        DEBUG_PRINT("Skipping screen update: ");
        DEBUG_PRINTLN(errorMessage);
    }

    SleepUntilNextRefresh();
}
