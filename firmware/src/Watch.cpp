#include <Watch.h>
#include <cstdlib>
#include <random>
#include <visualizations.h>

RTC_DATA_ATTR int Watch::mode = 0;

void Watch::drawWatchFace() {
    switch (mode) {
        case 0:
            visualizePixelArtDitherings(display);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            visualizeRandomFill(display, mode);
            break;
        default:
            break;
    }
}

void Watch::handleButtonPress() {
    const uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();

    if (wakeupBit & UP_BTN_MASK && guiState == WATCHFACE_STATE) {
        mode++;
        if (mode >= MODES) {
            mode = 0;
        }
    } else if (wakeupBit & DOWN_BTN_MASK && guiState == WATCHFACE_STATE) {
        mode--;
        if (mode < 0) {
            mode = MODES - 1;
        }
    } else {
        return Watchy::handleButtonPress();
    }

    showWatchFace(true);
}
