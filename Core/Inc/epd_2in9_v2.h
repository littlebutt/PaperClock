#ifndef __EPD_2IN9_V2_H
#define __EPD_2IN9_V2_H

#include "config.h"

// Display resolution
#define EPD_2IN9_V2_WIDTH       128
#define EPD_2IN9_V2_HEIGHT      296

void EPD_2IN9_V2_Init(void);
void EPD_2IN9_V2_Gray4_Init(void);
void EPD_2IN9_V2_Clear(void);
void EPD_2IN9_V2_Display(UBYTE *Image);
void EPD_2IN9_V2_Display_Base(UBYTE *Image);
void EPD_2IN9_V2_4GrayDisplay(UBYTE *Image);
void EPD_2IN9_V2_Display_Partial(UBYTE *Image);
void EPD_2IN9_V2_Sleep(void);
#endif
