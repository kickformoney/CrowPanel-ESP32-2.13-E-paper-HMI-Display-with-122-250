#ifndef FONT_TYPES_H
#define FONT_TYPES_H

#include <Arduino.h>

typedef struct
{
    uint8_t height;
    char startChar;
    char endChar;
    uint8_t spaceWidth;
    const void *charInfo;
    const uint8_t *bitmap;
} FONT_INFO;

typedef struct
{
    uint8_t width;
    uint16_t offset;
} FONT_CHAR_INFO;

#endif