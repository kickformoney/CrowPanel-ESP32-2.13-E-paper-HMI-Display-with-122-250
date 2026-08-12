#pragma once

// The set of weather graphics to display.  OpenWeatherMap's "condition id" 
// (see fetchWeather()/ReadWeather()) is mapped down to one of these via 
// WeatherIconFromConditionCode()
enum class WeatherIcon
{
    Clear,
    Clouds,
    Drizzle,
    Mist,
    Rain,
    Snow,
    Thunder,
};

// Maps an OpenWeatherMap condition code (the "id" field of the first
// "weather" array entry, see ReadWeather() in weather/Weather.cpp) to the
// icon that should be shown for it. Unrecognized codes fall back to
// WeatherIcon::Clear
WeatherIcon WeatherIconFromConditionCode(int conditionId);

// Returns the raw 1bpp bitmap (see graphics/Photos.h) for the given icon,
// drawn to the display via EPD_ShowPicture()
const unsigned char* WeatherIconBitmap(WeatherIcon icon);
