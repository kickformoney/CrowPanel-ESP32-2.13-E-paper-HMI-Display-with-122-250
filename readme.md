# CrowPanel 2.13" OpenWeather Display

An enhanced OpenWeather weather station for the **Elecrow CrowPanel 2.13" ESP32-S3 E-paper Display**.

This project began as Elecrow's OpenWeather demonstration and has been extensively reorganized and improved to provide a cleaner project structure, easier configuration, selectable fonts, and more maintainable source code.

---

## Features

* Displays current weather from OpenWeatherMap
* Supports both Imperial and Metric units
* Compile-time font selection
* Black & white display optimized
* Partial e-paper refreshes to reduce power consumption
* Simple configuration through a single `config.h`
* Cleaner, modular source layout
* Well-commented and refactored code
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
* Font selection

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

Two fonts are included.

* Noto Sans
* Nirmala Text

Switch between them by selecting the desired option in `config.h`.

Additional fonts can be generated using The Dot Factory and added with minimal changes.

---

# Project Layout

```text
example/
│
├── display/
├── fonts/
├── photos/
├── weather/
├── config.example.h
├── config.h
└── 2.13_wifi_http_openweather.ino
```

The project has been reorganized from the original demonstration to improve readability and make future development easier.

---

# Power Saving

The display uses partial refreshes whenever possible to reduce flashing and improve battery life.

Wi-Fi usage has also been structured to minimize unnecessary network activity.

---

# Troubleshooting

## `config.h` missing

Copy `config.example.h` to `config.h`.

---

## 401 Unauthorized

Your OpenWeatherMap API key is invalid or has not yet activated.

---

## Wi-Fi will not connect

Verify:

* SSID
* Password
* Wi-Fi channel (if configured)
* Optional BSSID settings

---

## Blank display

Verify:

* Correct board selected
* Correct USB port
* Required libraries installed

---

# Future Ideas

* Battery indicator
* Multiple weather pages
* Weather forecast
* Moon phase
* Sunrise and sunset
* Indoor temperature support
* OTA firmware updates

---

# Contributing

Issues, suggestions, and pull requests are welcome.

If you build something interesting using this project, I'd love to see it.

---

# Credits

This project is based on Elecrow's original OpenWeather demonstration for the CrowPanel 2.13" E-paper display.

The original code has been substantially reorganized and extended with additional features, configuration options, code cleanup, and documentation improvements.

Special thanks to:

* Elecrow for the original hardware and demonstration project.
* OpenWeatherMap for providing weather data.
* The Arduino and ESP32 communities for their excellent libraries and documentation.

---

# Original Hardware Documentation

The following hardware information has been retained from Elecrow's original documentation for reference.

*(Insert the manufacturer's hardware information here.)*
