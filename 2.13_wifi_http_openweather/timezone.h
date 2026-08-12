#pragma once

// This file is a reference list of #defines - a name you can look
// up and copy into LOCAL_TIME_ZONE in config.h
//
// NAMING: constants below are named after the IANA tz database region
// they correspond to (e.g. TZ_AMERICA_NEW_YORK for "America/New_York"),
// Search this file for your city or region; if it's not listed, find 
// your IANA zone name online:
// https://en.wikipedia.org/wiki/List_of_tz_database_time_zones
// and see "ADDING A ZONE NOT LISTED HERE" at the bottom of this file
//
// Note: Entries were retrieved by Claude, but appear accurate
// If your timezone doesn't work, you can look it up using the link above

// ===================== United States =====================
#define TZ_AMERICA_NEW_YORK      "EST5EDT,M3.2.0,M11.1.0"   		// Eastern - most of the US East Coast
#define TZ_AMERICA_CHICAGO       "CST6CDT,M3.2.0,M11.1.0"   		// Central
#define TZ_AMERICA_DENVER        "MST7MDT,M3.2.0,M11.1.0"   		// Mountain (observes DST)
#define TZ_AMERICA_PHOENIX       "MST7"                     		// Mountain, Arizona (NO DST - stays on standard time year-round)
#define TZ_AMERICA_LOS_ANGELES   "PST8PDT,M3.2.0,M11.1.0"   		// Pacific
#define TZ_AMERICA_ANCHORAGE     "AKST9AKDT,M3.2.0,M11.1.0" 		// Alaska
#define TZ_AMERICA_ADAK          "HST10HDT,M3.2.0,M11.1.0"  		// Hawaii-Aleutian, western Aleutian Islands only (observes DST, unlike Hawaii)
#define TZ_PACIFIC_HONOLULU      "HST10"                    		// Hawaii (NO DST)
#define TZ_AMERICA_INDIANA_INDIANAPOLIS "EST5EDT,M3.2.0,M11.1.0" 	// Most of Indiana
#define TZ_AMERICA_INDIANA_KNOX  "CST6CDT,M3.2.0,M11.1.0"  			// Starke County, IN (Central instead of Eastern)

// ===================== Canada =====================
#define TZ_AMERICA_ST_JOHNS      "NST3:30NDT,M3.2.0,M11.1.0" 		// Newfoundland (half-hour offset)
#define TZ_AMERICA_HALIFAX       "AST4ADT,M3.2.0,M11.1.0"   		// Atlantic - Nova Scotia, New Brunswick, PEI
#define TZ_AMERICA_TORONTO       "EST5EDT,M3.2.0,M11.1.0"   		// Eastern - Ontario, Quebec
#define TZ_AMERICA_WINNIPEG      "CST6CDT,M3.2.0,M11.1.0"   		// Central - Manitoba
#define TZ_AMERICA_REGINA        "CST6"                     		// Central, Saskatchewan (NO DST)
#define TZ_AMERICA_EDMONTON      "MST7MDT,M3.2.0,M11.1.0"   		// Mountain - Alberta
#define TZ_AMERICA_VANCOUVER     "PST8PDT,M3.2.0,M11.1.0"   		// Pacific - British Columbia
#define TZ_AMERICA_WHITEHORSE    "PST8PDT,M3.2.0,M11.1.0"   		// Yukon

// ===================== Mexico / Central America / Caribbean =====================
#define TZ_AMERICA_MEXICO_CITY   "CST6"                     		// Central Mexico (Mexico dropped DST in most regions in 2022)
#define TZ_AMERICA_TIJUANA       "PST8PDT,M3.2.0,M11.1.0"   		// Baja California (follows US DST rules)
#define TZ_AMERICA_HERMOSILLO    "MST7"                     		// Sonora (NO DST)
#define TZ_AMERICA_HAVANA        "CST5CDT,M3.2.0/0,M11.1.0/1" 		// Cuba
#define TZ_AMERICA_PUERTO_RICO   "AST4"                     		// Puerto Rico (NO DST)
#define TZ_AMERICA_GUATEMALA     "CST6"                     		// Guatemala (NO DST)
#define TZ_AMERICA_COSTA_RICA    "CST6"                     		// Costa Rica (NO DST)
#define TZ_AMERICA_PANAMA        "EST5"                     		// Panama (NO DST)

// ===================== South America =====================
#define TZ_AMERICA_BOGOTA        "<-05>5"                   		// Colombia (NO DST)
#define TZ_AMERICA_LIMA          "<-05>5"                   		// Peru (NO DST)
#define TZ_AMERICA_CARACAS       "<-04>4"                   		// Venezuela (NO DST)
#define TZ_AMERICA_SANTIAGO      "<-04>4<-03>,M9.1.6/24,M4.1.6/24" 	// Chile (observes DST)
#define TZ_AMERICA_SAO_PAULO     "<-03>3"                   		// Brazil, most populated region (Brazil dropped DST in 2019)
#define TZ_AMERICA_ARGENTINA_BUENOS_AIRES "<-03>3"          		// Argentina (NO DST)

// ===================== United Kingdom / Ireland =====================
#define TZ_EUROPE_LONDON         "GMT0BST,M3.5.0/1,M10.5.0" 		// UK
#define TZ_EUROPE_DUBLIN         "IST-1GMT0,M10.5.0,M3.5.0/1" 		// Ireland (POSIX encodes this "backwards" - Ireland's standard time is DST-like)

// ===================== Western/Central Europe (all observe the same EU-wide DST rules) =====================
#define TZ_EUROPE_PARIS          "CET-1CEST,M3.5.0,M10.5.0" 		// France
#define TZ_EUROPE_BERLIN         "CET-1CEST,M3.5.0,M10.5.0" 		// Germany
#define TZ_EUROPE_MADRID         "CET-1CEST,M3.5.0,M10.5.0" 		// Spain
#define TZ_EUROPE_ROME           "CET-1CEST,M3.5.0,M10.5.0" 		// Italy
#define TZ_EUROPE_AMSTERDAM      "CET-1CEST,M3.5.0,M10.5.0" 		// Netherlands
#define TZ_EUROPE_BRUSSELS       "CET-1CEST,M3.5.0,M10.5.0" 		// Belgium
#define TZ_EUROPE_ZURICH         "CET-1CEST,M3.5.0,M10.5.0" 		// Switzerland
#define TZ_EUROPE_STOCKHOLM      "CET-1CEST,M3.5.0,M10.5.0" 		// Sweden
#define TZ_EUROPE_WARSAW         "CET-1CEST,M3.5.0,M10.5.0" 		// Poland
#define TZ_EUROPE_VIENNA         "CET-1CEST,M3.5.0,M10.5.0" 		// Austria

// ===================== Eastern Europe =====================
#define TZ_EUROPE_HELSINKI       "EET-2EEST,M3.5.0,M10.5.0" 		// Finland
#define TZ_EUROPE_ATHENS         "EET-2EEST,M3.5.0,M10.5.0" 		// Greece
#define TZ_EUROPE_BUCHAREST      "EET-2EEST,M3.5.0,M10.5.0" 		// Romania
#define TZ_EUROPE_KYIV           "EET-2EEST,M3.5.0,M10.5.0" 		// Ukraine
#define TZ_EUROPE_MOSCOW         "MSK-3"                    		// Russia, Moscow (NO DST since 2014)
#define TZ_EUROPE_ISTANBUL       "<+03>-3"                  		// Turkey (NO DST since 2016, fixed UTC+3)

// ===================== Africa =====================
#define TZ_AFRICA_CAIRO          "EET-2EEST,M4.5.5/0,M10.5.4/24" 	// Egypt (irregular DST rule - last Thursday/Friday of the month)
#define TZ_AFRICA_JOHANNESBURG   "SAST-2"                   		// South Africa (NO DST)
#define TZ_AFRICA_LAGOS          "WAT-1"                    		// Nigeria (NO DST)
#define TZ_AFRICA_NAIROBI        "EAT-3"                    		// Kenya (NO DST)
#define TZ_AFRICA_CASABLANCA     "<+01>-1"                  		// Morocco (NO DST, but note: observes a Ramadan-related pause historically - simplified here)

// ===================== Middle East =====================
#define TZ_ASIA_JERUSALEM        "IST-2IDT,M3.4.4/26,M10.5.0" 		// Israel
#define TZ_ASIA_DUBAI            "<+04>-4"                  		// UAE (NO DST)
#define TZ_ASIA_RIYADH           "<+03>-3"                  		// Saudi Arabia (NO DST)
#define TZ_ASIA_TEHRAN           "<+0330>-3:30"             		// Iran (NO DST as of 2022; half-hour offset)

// ===================== South / Central Asia =====================
#define TZ_ASIA_KARACHI          "PKT-5"                    		// Pakistan (NO DST)
#define TZ_ASIA_KOLKATA          "IST-5:30"                 		// India (NO DST, half-hour offset)
#define TZ_ASIA_KATHMANDU        "NPT-5:45"                 		// Nepal (NO DST, 45-minute offset)
#define TZ_ASIA_DHAKA            "<+06>-6"                  		// Bangladesh (NO DST)

// ===================== East / Southeast Asia (none observe DST) =====================
#define TZ_ASIA_SHANGHAI         "CST-8"                    		// China (single time zone nationwide, NO DST)
#define TZ_ASIA_HONG_KONG        "HKT-8"                    		// Hong Kong (NO DST)
#define TZ_ASIA_TAIPEI           "CST-8"                    		// Taiwan (NO DST)
#define TZ_ASIA_TOKYO            "JST-9"                    		// Japan (NO DST)
#define TZ_ASIA_SEOUL            "KST-9"                    		// South Korea (NO DST)
#define TZ_ASIA_SINGAPORE        "<+08>-8"                  		// Singapore (NO DST)
#define TZ_ASIA_BANGKOK          "<+07>-7"                  		// Thailand (NO DST)
#define TZ_ASIA_JAKARTA          "WIB-7"                    		// Indonesia, western (NO DST)
#define TZ_ASIA_MANILA           "PST-8"                    		// Philippines (NO DST)

// ===================== Australia / New Zealand (DST is Southern Hemisphere =====================
// Starts in local spring/October, ends in local autumn/April - opposite of Northern Hemisphere zones)
#define TZ_AUSTRALIA_SYDNEY      "AEST-10AEDT,M10.1.0,M4.1.0/3" 	// NSW, Victoria, Tasmania, ACT
#define TZ_AUSTRALIA_BRISBANE    "AEST-10"                  		// Queensland (NO DST)
#define TZ_AUSTRALIA_ADELAIDE    "ACST-9:30ACDT,M10.1.0,M4.1.0/3" 	// South Australia (half-hour offset, observes DST)
#define TZ_AUSTRALIA_DARWIN      "ACST-9:30"                		// Northern Territory (NO DST, half-hour offset)
#define TZ_AUSTRALIA_PERTH       "AWST-8"                   		// Western Australia (NO DST)
#define TZ_PACIFIC_AUCKLAND      "NZST-12NZDT,M9.5.0,M4.1.0/3" 		// New Zealand

// ===================== Pacific Islands =====================
#define TZ_PACIFIC_GUAM          "ChST-10"                  		// Guam (NO DST)
#define TZ_PACIFIC_FIJI          "FJT-12FJST,M11.1.0,M1.2.4/3" 		// Fiji (observes DST)
#define TZ_PACIFIC_PAGO_PAGO     "SST11"                    		// American Samoa (NO DST)

// ===================== UTC =====================
#define TZ_UTC                   "UTC0"                     		// No offset, no DST - useful for testing or logging

// ---------------------------------------------------------------------
// ADDING A ZONE NOT LISTED HERE
// ---------------------------------------------------------------------
// 1. Find your IANA zone name (e.g. "Europe/Lisbon") at
//    https://en.wikipedia.org/wiki/List_of_tz_database_time_zones
// 2. Look up its POSIX TZ string. Two reliable ways:
//    a. If you have access to a Linux/Mac machine or an ESP32 already
//       running this project with internet access, you can often find
//       the POSIX equivalent by searching "<your IANA zone name> POSIX
//       TZ string" - many timezone reference sites list both side by
//       side.
//    b. The posix_tz_db project (https://github.com/nayarsystems/posix_tz_db)
//       publishes a machine-generated CSV/JSON mapping every IANA zone
//       to its POSIX string, regenerated from the current tz database.
// 3. Double check any zone you add if it observes DST: confirm the
//    month/week/day rule (M3.2.0 = 2nd Sunday of March, etc.) against a
//    second source, since a small error there means your clock will be
//    silently wrong for part of the year rather than failing loudly.
// 4. Add it here following the same #define TZ_<REGION>_<CITY> pattern,
//    then set LOCAL_TIME_ZONE in your config.h to that string (or the
//    #define name, if you #include "timezone.h" in config.h).
