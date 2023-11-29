#ifndef DISPLAYSTACK_H
#define DISPLAYSTACK_H
#include "BaseScreen.h"
class DisplayStack {
public:
    void push(BaseScreen& screen) {
        this->screens[this->currentScreen] = &screen;
        this->currentScreen++;
        this->display();
    }

    void pop() {
        if (this->currentScreen > 0) {
            this->currentScreen--;
            this->display();
        }
    }

    void display() {
        if (this->currentScreen > 0) {
            this->screens[(this->currentScreen - 1)]->display();
        }
    }

    void loop() {
        if (this->currentScreen > 0) {
            this->screens[(this->currentScreen - 1)]->loop();
        }
    }

private:
    int currentScreen = 0;
    BaseScreen* screens[10];
};

#endif