#include <visualizations.h>

void visualizePixelArtBlack(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_BLACK);
}

void visualizePixelArtDarkestGrey(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_BLACK);
    for (int16_t y = gy + 1; y < gy + h; y += 2) {
        for (int16_t x = gx; x < gx + w; x += 2) {
            display.drawPixel(x, y,GxEPD_WHITE);
        }
    }
}

void visualizePixelArtDarkGrey(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_BLACK);
    for (int16_t y = gy; y < gy + h; y++) {
        if (y % 2 == 0) {
            for (int16_t x = gx; x < gx + w; x += 2) {
                display.drawPixel(x, y,GxEPD_WHITE);
            }
        } else {
            for (int16_t x = gx + y % 4; x < gx + w; x += 4) {
                display.drawPixel(x, y,GxEPD_WHITE);
            }
        }
    }
}

void visualizePixelArtGrey(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_BLACK);
    for (int16_t y = gy; y < gy + h; y++) {
        for (int16_t x = gx; x < gx + w; x++) {
            if ((x + y) % 2 == 0) {
                display.drawPixel(x, y,GxEPD_WHITE);
            }
        }
    }
}

void visualizePixelArtLightGrey(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_WHITE);
    for (int16_t y = gy; y < gy + h; y++) {
        if (y % 2 == 0) {
            for (int16_t x = gx; x < gx + w; x += 2) {
                display.drawPixel(x, y,GxEPD_BLACK);
            }
        } else {
            for (int16_t x = gx + y % 4; x < gx + w; x += 4) {
                display.drawPixel(x, y,GxEPD_BLACK);
            }
        }
    }
}

void visualizePixelArtLightestGrey(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_WHITE);
    for (int16_t y = gy + 1; y < gy + h; y += 2) {
        for (int16_t x = gx; x < gx + w; x += 2) {
            display.drawPixel(x, y,GxEPD_BLACK);
        }
    }
}

void visualizePixelArtWhite(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int16_t gx,
    const int16_t gy,
    const int16_t w,
    const int16_t h
) {
    display.fillRect(gx, gy, w, h,GxEPD_WHITE);
}

void visualizePixelArtDitherings(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display
) {
    int16_t height = display.height();
    int16_t width = display.width();

    while (height % 3 != 0) { height--; }
    while (width % 3 != 0) { width--; }

    Serial.printf("height: %d, width: %d\n", height, width);

    const int16_t marginTop = (display.height() - height) / 2;
    const int16_t marginLeft = (display.width() - width) / 2;

    Serial.printf("marginTop: %d, marginLeft: %d\n", marginTop, marginLeft);

    const int16_t h = height / 3;
    const int16_t w = width / 3;

    Serial.printf("h: %d, w: %d\n", h, w);

    display.fillScreen(GxEPD_WHITE);
    visualizePixelArtBlack(display, marginLeft, marginTop, w, h);
    visualizePixelArtDarkestGrey(display, marginLeft + w, marginTop, w, h);
    visualizePixelArtDarkGrey(display, marginLeft + 2 * w, marginTop, w, h);
    visualizePixelArtGrey(display, marginLeft, marginTop + h, w, h);
    visualizePixelArtLightGrey(display, marginLeft + w, marginTop + h, w, h);
    visualizePixelArtLightestGrey(display, marginLeft + 2 * w, marginTop + h, w, h);
    visualizePixelArtWhite(display, marginLeft, marginTop + 2 * h, w, h);
    visualizePixelArtBlack(display, marginLeft + w, marginTop + 2 * h, w, h);
}

void visualizeRandomFill(
    GxEPD2_BW<WatchyDisplay, WatchyDisplay::HEIGHT> &display,
    const int mode
) {
    display.fillScreen(GxEPD_BLACK);
    for (int16_t y = 0; y < display.height(); y++) {
        for (int16_t x = 0; x < display.width(); x++) {
            if (random(10) < mode) {
                display.drawPixel(x, y,GxEPD_WHITE);
            }
        }
    }
}
