#ifndef _EPD_H_
#define _EPD_H_

#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include "EPD_Init.h"
#include "DisplaySettings.h"
#include "../fonts/NotoSans.h"
#include "../fonts/NirmalaText.h"

/* 函数说明 */
void EPD_DrawPoint(uint16_t x, uint16_t y, uint8_t color);
void EPD_DrawLine(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint8_t color);                              // 划线函数
void EPD_DrawRectangle(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint8_t color);                         // 绘制空心矩形
void Draw_Circle(int xc, int yc, int x, int y, uint8_t color);                                                     // 8分法画圆内部调用
void EPD_DrawCircle(uint16_t xc, uint16_t yc, uint16_t r, uint8_t color, uint16_t mode);                           // 绘制圆形
void EPD_DrawTriangel(uint16_t x, uint16_t y, uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint8_t color);  // 绘制空心三角形
void EPD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint8_t color, uint8_t sizey);                              // 显示字符函数
void EPD_ShowString(uint16_t x, uint16_t y, const char *s, uint8_t color, uint16_t sizey);                         // 显示字符串
uint32_t mypow(uint8_t m, uint8_t n);                                                                              // 幂运算内部调用
void EPD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t color, uint8_t sizey);                 // 显示数字
void EPD_ShowFloatNum(uint16_t x, uint16_t y, float num, uint8_t pre, uint8_t len, uint8_t color, uint8_t sizey);  // 显示浮点数
void EPD_ShowPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t pic[], uint8_t color); // 图片显示
void EPD_ShowWatch(uint16_t x, uint16_t y, float num, uint8_t pre, uint8_t len, uint8_t color, uint8_t sizey);     // 显示秒表

void EPD_ShowGFXChar(
    int16_t x,
    int16_t y,
    char c,
    const GFXfont *font,
    uint8_t color);

void EPD_ShowGFXString(
    int16_t x,
    int16_t y,
    const char *str,
    const GFXfont *font,
    uint8_t color);

  void EPD_ShowDotFactoryChar(
    uint16_t x,
    uint16_t y,
    char c,
    uint8_t color);

void EPD_ShowDotFactoryString(
    uint16_t x,
    uint16_t y,
    const char *str,
    uint8_t color);

// Returns the pixel width EPD_ShowDotFactoryString()/EPD_ShowGFXString()
// would draw the given string at, without drawing anything. Used to
// support TextAlignment Center/Right in the helpers below
uint16_t EPD_MeasureDotFactoryString(const char *str);
uint16_t EPD_MeasureGFXString(const char *str, const GFXfont *font);

// Like EPD_ShowDotFactoryString()/EPD_ShowGFXString(), but positioned by
// an Anchor instead of a raw (x, y).  For Center/Right alignment, the
// string is measured first, then shifted, so it lands at the anchor point
void EPD_ShowAnchoredDotFactoryString(Anchor anchor, const char *str, uint8_t color);
void EPD_ShowAnchoredGFXString(Anchor anchor, const char *str, const GFXfont *font, uint8_t color);

#endif
