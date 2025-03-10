#include "clock.h"

void _Clock_Sync(Clock_CTX *ctx) {
    struct tm *_tm;
    time_t now = HAL_GetTick() / 1000 + ctx->offset;
    _tm = gmtime(&now);
    ctx->pt.Year = 1900 + _tm->tm_year;
    ctx->pt.Month = 1 + _tm->tm_mon;
    ctx->pt.Day = _tm->tm_mday;
    ctx->pt.Hour = _tm->tm_hour;
    ctx->pt.Min = _tm->tm_min;
    ctx->pt.Sec = _tm->tm_sec;
    free(_tm);
}

void _Clock_SyncBack(Clock_CTX *ctx) {
    struct tm _tm;
    _tm.tm_year = ctx->pt.Year - 1900;
    _tm.tm_mon = ctx->pt.Month - 1;
    _tm.tm_mday = ctx->pt.Day;
    _tm.tm_hour = ctx->pt.Hour;
    _tm.tm_min = ctx->pt.Min;
    _tm.tm_sec = ctx->pt.Sec;
    ctx->offset = mktime(&_tm) - HAL_GetTick() / 1000;
}

void Clock_Init(Clock_CTX *ctx) {
    ctx->offset = 0;
    _Clock_Sync(ctx);
    ctx->mode = 0;
}

void Clock_Tick(Clock_CTX *ctx) {
    if (ctx->mode == 1) {
        return;
    }
    _Clock_Sync(ctx);
}

void Clock_ToggleMode(Clock_CTX *ctx) {
    ctx->mode = ctx->mode == 0 ? 1 : 0;
}

void Clock_SetYear(Clock_CTX *ctx, int year) {
    if (ctx->mode == 0) {
        return;
    }
    ctx->pt.Year = year;
    _Clock_SyncBack(ctx);
}

void Clock_SetMonth(Clock_CTX *ctx, int month) {
    if (ctx->mode == 0) {
        return;
    }
    ctx->pt.Month = month;
    _Clock_SyncBack(ctx);
}

void Clock_SetDay(Clock_CTX *ctx, int day) {
    if (ctx->mode == 0) {
        return;
    }
    ctx->pt.Day = day;
    _Clock_SyncBack(ctx);
}

void Clock_SetHour(Clock_CTX *ctx, int hour) {
    if (ctx->mode == 0) {
        return;
    }
    ctx->pt.Hour = hour;
    _Clock_SyncBack(ctx);
}

void Clock_SetMinute(Clock_CTX *ctx, int minute) {
    if (ctx->mode == 0) {
        return;
    }
    ctx->pt.Min = minute;
    _Clock_SyncBack(ctx);
}

void Clock_SetSecond(Clock_CTX *ctx, int second) {
    if (ctx->mode == 0) {
        return;
    }
    ctx->pt.Sec = second;
    _Clock_SyncBack(ctx);
}