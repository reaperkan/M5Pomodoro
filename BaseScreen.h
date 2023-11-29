#ifndef BASESCREEN_H
#define BASESCREEN_H

class BaseScreen {
public:
    virtual void display() {
        M5.Lcd.clear();
    }

    virtual void loop() {}
};

#endif