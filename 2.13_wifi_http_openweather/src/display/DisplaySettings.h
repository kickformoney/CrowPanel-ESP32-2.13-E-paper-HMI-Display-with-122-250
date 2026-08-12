#pragma once

// This file contains enums and helper functions only.  Most editable
// settings can be found in config.h

// Which unit system(s) to show on screen. Set via DISPLAY_UNITS in config.h
enum UnitDisplayMode
{
    DISPLAY_METRIC,
    DISPLAY_IMPERIAL,
    DISPLAY_BOTH
};

// Which unit system a single-unit layout should use.  Derived automatically
// from DISPLAY_UNITS.  Refer to GetUnitType() below for more information
enum UnitType
{
    UNIT_METRIC,
    UNIT_IMPERIAL
};

// Infers the single unit system to use, and to decide what to request
// from the weather API.  When both units are displayed, imperial vs. 
// metric is inconsequential, so this defaults to metric
constexpr UnitType GetUnitType(UnitDisplayMode displayUnits)
{
    return (displayUnits == DISPLAY_IMPERIAL) ? UNIT_IMPERIAL : UNIT_METRIC;
}

// Horizontal text alignment for a screen element.  Used by Anchor below and
// by EPD's anchored string drawing helpers to decide whether to shift text
// left/right of the anchor point, based on the text's measured width
enum class TextAlignment
{
    Left,
    Center,
    Right
};

// A single positioned, aligned screen element.  (x, y) is the anchor point.
// For Left alignment, this is the left edge of the text, for Center/Right, 
// it's the horizontal center/right edge, with the actual draw position 
// computed from the text's measured width at draw time
struct Anchor
{
    int x;
    int y;
    TextAlignment alignment = TextAlignment::Left;

    constexpr Anchor(int x_val, int y_val, TextAlignment align_val = TextAlignment::Left)
        : x(x_val), y(y_val), alignment(align_val) {}
};
