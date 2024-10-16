#include <Watch.h>
#include <settings.h>

Watch watch(settings);

void setup() {
    Serial.begin(9600);
    watch.init();
}

void loop() {
}
