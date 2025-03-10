#include "panel.h"

void Panel_Init(Panel_CTX *ctx, Clock_CTX *c_ctx) {
    ctx->c_ctx = c_ctx;
    ctx->target = 12;
}

void _Panel_StartSetting(Panel_CTX *ctx) {
    Clock_ToggleMode(ctx->c_ctx);
    ctx->year_digits[0] = ctx->c_ctx->pt.Year / 1000;
    ctx->year_digits[1] = ctx->c_ctx->pt.Year % 1000 / 100;
    ctx->year_digits[2] = ctx->c_ctx->pt.Year % 100 / 10;
    ctx->year_digits[3] = ctx->c_ctx->pt.Year % 10;
    ctx->month_digits[0] = ctx->c_ctx->pt.Month / 10;
    ctx->month_digits[1] = ctx->c_ctx->pt.Month % 10;
    ctx->day_digits[0] = ctx->c_ctx->pt.Day / 10;
    ctx->day_digits[1] = ctx->c_ctx->pt.Day % 10;
    ctx->hour_digits[0] = ctx->c_ctx->pt.Hour / 10;
    ctx->hour_digits[1] = ctx->c_ctx->pt.Hour % 10;
    ctx->minute_digits[0] = ctx->c_ctx->pt.Min / 10;
    ctx->minute_digits[1] = ctx->c_ctx->pt.Min % 10;
    ctx->target = 0;
}

void _Panel_FinishSetting(Panel_CTX *ctx) {
    Clock_ToggleMode(ctx->c_ctx);
    ctx->target = 12;
    Clock_SetYear(ctx->c_ctx, ctx->year_digits[0] * 1000 + ctx->year_digits[1] * 100 + ctx->year_digits[2] * 10 + ctx->year_digits[3]);
    Clock_SetMonth(ctx->c_ctx, ctx->month_digits[0] * 10 + ctx->month_digits[1]);
    Clock_SetDay(ctx->c_ctx, ctx->day_digits[0] * 10 + ctx->day_digits[1]);
    Clock_SetHour(ctx->c_ctx, ctx->hour_digits[0] * 10 + ctx->hour_digits[1]);
    Clock_SetMinute(ctx->c_ctx, ctx->minute_digits[0] * 10 + ctx->minute_digits[1]);
    Clock_SetSecond(ctx->c_ctx, 0);
}

void Panel_ToggleSetting(Panel_CTX *ctx) {
    if (ctx->c_ctx->mode == 1) {
        _Panel_FinishSetting(ctx);
    } else {
        _Panel_StartSetting(ctx);
    }
}

void Panel_MoveCursor(Panel_CTX *ctx) {
    if (ctx->target == 12) {
        return;
    }
    ctx->target  = (ctx->target + 1) % 12;
}

void Panel_SetNumber(Panel_CTX *ctx) {
    if (ctx->target < 4) {
        int _cursor = ctx->target;
        ctx->year_digits[_cursor] = (ctx->year_digits[_cursor] + 1) % 10;
    } else if (ctx->target < 6) {
        int _cursor = ctx->target - 4;
        ctx->month_digits[_cursor] = (ctx->month_digits[_cursor] + 1) % 10;
    } else if (ctx->target < 8) {
        int _cursor = ctx->target - 6;
        ctx->day_digits[_cursor] = (ctx->day_digits[_cursor] + 1) % 10;
    } else if (ctx->target < 10) {
        int _cursor = ctx->target - 8;
        ctx->hour_digits[_cursor] = (ctx->hour_digits[_cursor] + 1) % 10;
    } else {
        int _cursor = ctx->target - 10;
        ctx->minute_digits[_cursor] = (ctx->minute_digits[_cursor] + 1) % 10;
    }
}