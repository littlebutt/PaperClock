#ifndef __PANEL_H
#define __PANEL_H

#include "clock.h"

typedef struct{
    Clock_CTX *c_ctx;
    int year_digits[4];
    int month_digits[2];
    int day_digits[2];
    int hour_digits[2];
    int minute_digits[2];
    int target;
} Panel_CTX;

void Panel_Init(Panel_CTX *ctx, Clock_CTX *c_ctx);

void Panel_ToggleSetting(Panel_CTX *ctx);

void Panel_StartSetting(Panel_CTX *ctx);

void Panel_MoveCursor(Panel_CTX *ctx);

void Panel_SetNumber(Panel_CTX *ctx);
#endif