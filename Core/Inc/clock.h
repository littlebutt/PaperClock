#ifndef __CLOCK_H
#define __CLOCK_H

#include "paint.h"
#include "time.h"
#include "stdlib.h"

typedef struct
{
    PAINT_TIME pt;
    long long int offset;
    int mode; // 1: Setting, 0: Running
} Clock_CTX;


void Clock_Init(Clock_CTX *ctx);

void Clock_Tick(Clock_CTX *ctx);

void Clock_ToggleMode(Clock_CTX *ctx);

void Clock_SetYear(Clock_CTX *ctx, int year);

void Clock_SetMonth(Clock_CTX *ctx, int month);

void Clock_SetDay(Clock_CTX *ctx, int day);

void Clock_SetHour(Clock_CTX *ctx, int hour);

void Clock_SetMinute(Clock_CTX *ctx, int minute);

void Clock_SetSecond(Clock_CTX *ctx, int second);

#endif