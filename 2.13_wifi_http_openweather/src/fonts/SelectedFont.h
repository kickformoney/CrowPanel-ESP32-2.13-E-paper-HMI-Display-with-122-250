#pragma once

#include "FontTypes.h"

struct ActiveFont
{
    const FONT_INFO* info;
    const FONT_CHAR_INFO* descriptors;
    const uint8_t* bitmaps;
};

extern const ActiveFont CurrentFont;