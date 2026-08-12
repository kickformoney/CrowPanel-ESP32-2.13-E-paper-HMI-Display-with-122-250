# CrowPanel 2.13" OpenWeather Display

An enhanced OpenWeather weather station for the **Elecrow CrowPanel 2.13" ESP32-S3 E-paper Display**.

This project began as Elecrow's OpenWeather demonstration and has been extensively reorganized and improved to provide a cleaner project structure, easier configuration, selectable fonts, and more maintainable source code.

---

## Features

* Displays current weather from OpenWeatherMap
* Supports both Imperial and Metric units
* Custom font support
* Black & white display optimized
* Optimizations to reduce power consumption
* Simple configuration through a single `config.h`
* Cleaner, modular source layout
* Designed to be easy to customize and extend

---

## Gallery

*Screenshots coming soon.*

---

# Hardware

* Elecrow CrowPanel 2.13"
* ESP32-S3
* 122 × 250 E-paper display
* SSD1680Z / JD79661 display controller
* 8 MB Flash
* 8 MB PSRAM

---

# Quick Start

## 1. Clone the repository

```bash
git clone https://github.com/<your_username>/<repository>.git
```

---

## 2. Create your configuration file

Copy

```text
config.example.h
```

to

```text
config.h
```

---

## 3. Edit `config.h`

Fill in:

* Wi-Fi SSID
* Wi-Fi Password
* OpenWeatherMap API Key
* Desired location
* Units
* Font selection (Note: Nirmala requires additional configuration before using)

---

## 4. Install the required Arduino libraries

Install the required libraries through the Arduino Library Manager.

Required libraries include:

* WiFi
* HTTPClient
* Arduino_JSON
* Adafruit GFX
* EPD Library

---

## 5. Open the project

Open the `.ino` file in Arduino IDE.

Select:

* Board: ESP32-S3
* Correct COM Port

Compile and upload.

---

# Configuration

| Setting                | Description               |
| ---------------------- | ------------------------- |
| `WIFI_SSID`            | Wi-Fi network name        |
| `WIFI_PASSWORD`        | Wi-Fi password            |
| `API_KEY`              | OpenWeatherMap API key    |
| `CITY`                 | Weather location          |
| `COUNTRY_CODE`         | Country identifier        |
| `UNIT_TYPE`            | Imperial or Metric        |
| `USE_FONT_NOTOSANS`    | Compile with Noto Sans    |
| `USE_FONT_NIRMALATEXT` | Compile with Nirmala Text |

---

# Fonts

Two font engines are available, one to draw from AdaFruit_GFX library, and one for custom fonts

* Noto Sans
* Nirmala Text*

Switch between them by selecting the desired option in `config.h`

* Nirmala Text bitmaps must be generated using The Dot Factory before use.  Additional fonts can be added using Nirmala Text as a template

---

# Project Layout

```text
example/
│
├── src/
│   ├── display/
│   ├── fonts/
│   ├── graphics/
│   └── weather/
├── config.h
├── timezone.h
└── 2.13_wifi_http_openweather.ino
```

The project has been reorganized from the original demonstration to improve readability and make future development easier

---

# Power Saving

The CPU can be throttled to 80MHz to reduce power consumption

Wi-Fi usage has also been structured to minimize unnecessary network activity

---

# Troubleshooting

## `config.h` missing

Copy `config.example.h` to `config.h`

---

## 401 Unauthorized

Your OpenWeatherMap API key is invalid, or is not yet activated

---

## Wi-Fi will not connect

Verify:
* SSID
* Password
* Wi-Fi channel (if configured)
* BSSID (if configured)

---

## Blank display

Verify:
* Correct board selected (ESP32 S3 Dev Module)
* Correct serial port
* Required libraries installed

---

# Credits

This project is based on Elecrow's original OpenWeather demonstration for the CrowPanel 2.13" E-paper display:
https://github.com/Elecrow-RD/CrowPanel-ESP32-2.13-E-paper-HMI-Display-with-122-250/

The original code has been substantially reorganized and extended with additional features, configuration options, and code cleanup
