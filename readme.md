# CrowPanel 2.13" OpenWeather Display

An enhanced OpenWeather weather station for the **Elecrow CrowPanel 2.13" ESP32-S3 E-paper Display**.

This project began as Elecrow's OpenWeather demonstration and has been extensively reorganized and improved to provide a cleaner project structure, easier configuration, custom fonts, and more

---

## Features

* Displays current weather from OpenWeatherMap, along with the time of the latest refresh
* Supports both Imperial and Metric units
* Custom font support with text alignment options
* Deep-sleep support with GPIO state retention across sleep cycles
* Additional optimizations to reduce power consumption
* Simple configuration through a single `config.h`
* Cleaner, modular source layout
* Designed to be easy to customize and extend

---

## Gallery

#### Noto Sans (included):
<img width="800" height="387" alt="notosans-c-first" src="https://github.com/user-attachments/assets/626c7d2c-f275-42bb-a275-20196781a24f" />

<img width="800" height="389" alt="noto-sans-c-only" src="https://github.com/user-attachments/assets/f496681f-fd52-49d9-9d3a-a732aebbf147" />

#### Nirmala Text (requires bitmap generation)
<img width="800" height="390" alt="nirmala-f-first" src="https://github.com/user-attachments/assets/ed5ebbfc-59f2-40bc-ab0e-80fc6ebfd4ee" />

<img width="800" height="385" alt="nirmala-c-first" src="https://github.com/user-attachments/assets/5a6a255f-71d1-4ecd-9888-ee705bbba336" />

---

# Hardware

* Elecrow CrowPanel 2.13"
* ESP32-S3
* 122 × 250 E-paper display
* SSD1680Z / JD79661 display controller
* 8 MB Flash

---

# Prerequisites
Follow the Quick Start instructions [here](https://github.com/Elecrow-RD/CrowPanel-ESP32-2.13-E-paper-HMI-Display-with-122-250#5quick-start), if you have not already

Clone the original repository [here](https://github.com/Elecrow-RD/CrowPanel-ESP32-2.13-E-paper-HMI-Display-with-122-250/):

<img width="522" height="516" alt="image" src="https://github.com/user-attachments/assets/5a33a5f3-7a0f-485d-9612-f5be49dacd4f" />  

<br/><br/>
The required libraries can be found in this directory:
`CrowPanel-ESP32-2.13-E-paper-HMI-Display-with-122-250/example/arduino
/libraries/`

---

# Getting Started

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

## 3. Customize `config.h`

Fill in:
* Wi-Fi SSID
* Wi-Fi Password
* OpenWeatherMap API Key
* Desired location
* Units
* Font selection (Note: Nirmala requires additional configuration before using)

### Configuration

| Setting                   | Description               |
| ----------------------    | ------------------------- |
|DEBUG                      |Set to 1 for serial debug output (115200 baud), 0 for normal/battery deployment|
|BATTERY_POWERED            |If true, applies additional power-saving optimizations (e.g. CPU throttled to 80MHz)|
|WIFI_SSID                  |Wi-Fi network name|
|WIFI_PASSWORD              |Wi-Fi password|
|USE_WIFI_BSSID             |If true, connects using a specific WIFI_CHANNEL/WIFI_BSSID to speed up reconnects and conserve power|
|WIFI_CHANNEL               |Wi-Fi channel to use, if USE_WIFI_BSSID is true|
|WIFI_BSSID                 |Access point's MAC address, if USE_WIFI_BSSID is true|
|API_KEY                    |OpenWeatherMap API key|
|CITY_NAME                  |Name displayed under "City" header, since this can be inaccurate when using GPS coordinates|
|ZIP_CODE                   |ZIP/Postal code used to look up weather, if not using precise coordinates|
|USE_PRECISE_COORDINATES    |If true, looks up weather using LATITUDE/LONGITUDE instead of ZIP_CODE|
|LATITUDE                   |GPS latitude, if USE_PRECISE_COORDINATES is true|
|LONGITUDE                  |GPS longitude, if USE_PRECISE_COORDINATES is true|
|LOCAL_TIME_ZONE            |POSIX TZ string for local time zone/DST rules (refer to timezone.h for codes)|
|DISPLAY_UNITS              |DISPLAY_METRIC, DISPLAY_IMPERIAL, or DISPLAY_BOTH|
|DisplayImperialFirst       |If true and using DISPLAY_BOTH, displays Imperial units before Metric|
|USE_FONT_NOTOSANS          |Compile with Noto Sans (default, license-friendly for distribution)|
|USE_FONT_NIRMALATEXT       |Compile with Nirmala Text (requires Dot Factory bitmap generation first)|

---

## 4. Open the project

Open the `.ino` file in Arduino IDE

Select:
* Board: ESP32 S3 Dev Module
* Correct COM Port

Compile and upload

---

# Fonts

Two font engines are available, one to draw from AdaFruit_GFX library, and one for custom fonts

* Noto Sans
* Nirmala Text*

Switch between the two by selecting the desired option in `config.h`

Nirmala Text bitmaps must be generated using The Dot Factory before use.  Additional fonts can be added using Nirmala Text as a template*

### Using The Dot Factory to generate new fonts
Clone "The Dot Factory" and open the solution in Visual Studio.  Build the application and run it (or find an alternative download)

Generate all characters:

<img width="415" height="309" alt="TheDotFactory-generate-bitmaps" src="https://github.com/user-attachments/assets/481f591e-3439-46b1-a585-9224c576f202" />

<br/><br/>
Use the following settings when generating bitmaps:

<img width="850" height="594" alt="TheDotFactory-settings" src="https://github.com/user-attachments/assets/b48024fa-dfab-433d-9849-4261c2e34fbe" />

<br/><br/>
For any other configuration, use the existing fonts as examples

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

The CPU can be throttled to 80MHz to reduce power consumption in config.h

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

## Garbled Text

<img width="480" height="224" alt="garbled-text" src="https://github.com/user-attachments/assets/d9b96150-add7-4a22-a154-1d77793298e4" />

<br/><br/>
Validate that the font you are using has bitmaps included (in `FontName.cpp`)

Example bitmap:

```
  // @11 '!' (1 pixels wide)
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, // 
```

# Credits

This project is based on Elecrow's original OpenWeather demonstration for the CrowPanel 2.13" E-paper display

https://github.com/Elecrow-RD/CrowPanel-ESP32-2.13-E-paper-HMI-Display-with-122-250/

Font bitmaps were generated using The Dot Factory

https://github.com/pavius/the-dot-factory/
