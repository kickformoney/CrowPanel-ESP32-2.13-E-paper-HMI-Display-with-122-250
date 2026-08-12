#pragma once

#include "src/display/DisplaySettings.h"
#include "timezone.h"

// Copy this file to config.h and populate the variables with your own values

// ============================================================================
// DEBUG / SERIAL LOGGING
// ============================================================================
 
// Set to 1 to enable serial debug output (115200 baud rate) to troubleshoot
// Wi-Fi or API issues. Leave at 0 for normal/battery deployment
#define DEBUG 1

// ============================================================================
// SYSTEM & POWER CONFIGURATION
// ============================================================================

// If true, the processor will be throttled to 80MHz to conserve battery power
constexpr bool BATTERY_POWERED = false;

// ============================================================================
// WI-FI NETWORK CONFIGURATION
// ============================================================================

constexpr char WIFI_SSID[] = "ssid";
constexpr char WIFI_PASSWORD[] = "password";

// (Optional) If running from a battery, configure the following to minimize radio usage
// and reduce power consumption
constexpr bool USE_WIFI_BSSID = false;
constexpr int WIFI_CHANNEL = 6;
constexpr uint8_t const WIFI_BSSID[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};

// ============================================================================
// WEATHER API & LOCATION SETTINGS
// ============================================================================

// OpenWeatherMap API key - https://openweathermap.org/api
constexpr char API_KEY[] = "apiKey";

// Note: The Weather API doesn't necessarily return the city name when using GPS coordinates
// The city name here will be shown on the display
constexpr char CITY_NAME[] = "MyCity";
constexpr char ZIP_CODE[] = "MyPostalCode";

// (Optional) GPS coordinates - https://gps-coordinates.org/
constexpr bool USE_PRECISE_COORDINATES = false;
constexpr char LATITUDE[] = "12.3456789";
constexpr char LONGITUDE[] = "-12.3456789";

// ============================================================================
// TIMEZONE & LOCALIZATION
// ============================================================================

// Local time zone, as a POSIX TZ string - this is what makes the on-screen
// clock show the correct local time.  Refer to timezone.h for a lookup table 
// of common regions.  Find your city or country in the list and paste its
// lookup or timezone string below
constexpr char LOCAL_TIME_ZONE[] = TZ_AMERICA_NEW_YORK; // or "EST5EDT,M3.2.0,M11.1.0"

// Display METRIC units, IMPERIAL units, or BOTH - default: DISPLAY_BOTH
constexpr UnitDisplayMode DISPLAY_UNITS = DISPLAY_BOTH;

// Display Imperial units first, instead of Metric, if using DISPLAY_BOTH
constexpr bool DisplayImperialFirst = false;

// ============================================================================
// DISPLAY TYPOGRAPHY (FONTS)
// ============================================================================

// Noto Sans is the default, as it's licensed for distribution
#define USE_FONT_NOTOSANS

// Nirmala Text (or any other custom font) requires additional processing with The Dot Factory, 
// refer to the ReadMe for details, uncomment after creating the necessary bitmaps
// #define USE_FONT_NIRMALATEXT