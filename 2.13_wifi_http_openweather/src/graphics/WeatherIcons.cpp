#include "WeatherIcons.h"
#include "Graphics.h"

// Ranges match OpenWeatherMap's condition code groups:
// https://openweathermap.org/weather-conditions
WeatherIcon WeatherIconFromConditionCode(int conditionId)
{
    if (conditionId >= 200 && conditionId < 300)
        return WeatherIcon::Thunder;

    if (conditionId >= 300 && conditionId < 322)
        return WeatherIcon::Drizzle;

    if (conditionId >= 322 && conditionId < 600)
        return WeatherIcon::Rain;

    if (conditionId >= 600 && conditionId < 700)
        return WeatherIcon::Snow;

    if (conditionId >= 700 && conditionId < 800)
        return WeatherIcon::Mist;

    if (conditionId == 800)
        return WeatherIcon::Clear;

    if (conditionId > 800)
        return WeatherIcon::Clouds;

    // Unrecognized/negative code, fall back to "Clear"
    return WeatherIcon::Clear;
}

const unsigned char* WeatherIconBitmap(WeatherIcon icon)
{
    static const unsigned char* const bitmaps[] =
    {
        gImage_clearsky, // Clear
        gImage_clouds,   // Cloudy
        gImage_drizzle,  // Drizzle
        gImage_mist,     // Mist/Fog
        gImage_rain,     // Rain
        gImage_snow,     // Snow
        gImage_thunder,  // Thunder
    };

    return bitmaps[static_cast<int>(icon)];
}
