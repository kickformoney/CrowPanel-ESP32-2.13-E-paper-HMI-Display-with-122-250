#include <Arduino.h>
#include "../../config.h"
#include "SelectedFont.h"
#include "NotoSans.h"
#include "NirmalaText.h"

#ifdef USE_FONT_NOTOSANS

const ActiveFont CurrentFont =
{
    &NotoSans_8ptFontInfo,
    NotoSans_8ptDescriptors,
    NotoSans_8ptBitmaps
};

#elif defined(USE_FONT_NIRMALATEXT)

const ActiveFont CurrentFont =
{
    &NirmalaText_8ptFontInfo,
    NirmalaText_8ptDescriptors,
    NirmalaText_8ptBitmaps
};

#endif