#pragma once

#include "../../config.h"
#include "DisplaySettings.h"

// Every available screen element's position, in one place
struct Layout
{
    Anchor weatherIcon;
    Anchor city;
    Anchor description;
    Anchor currentTemperature;
    Anchor feelsLike;
    Anchor humidity;
    Anchor wind;
    Anchor date;
    Anchor time;
};

constexpr Layout Layout
{
    .weatherIcon         = { 10,   1},
    .city                = {178,  22},
    .description         = {  0,   0, TextAlignment::Center},
    .currentTemperature  = { 90, 110},
    .feelsLike           = {180, 110},
    .humidity            = {178,  62},
    .wind                = { 20, 110},
    .date                = {  0,   0, TextAlignment::Right},
    .time                = {250,   5, TextAlignment::Right},
};