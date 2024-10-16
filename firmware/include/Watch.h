#ifndef WATCH_H
#define WATCH_H

#include <Watchy.h>

class Watch : public Watchy {
    using Watchy::Watchy;

    static int mode;
    static constexpr int MODES = 10;

public:
    void drawWatchFace();

    void handleButtonPress() override;
};

#endif
