#ifndef HOMESCREEN_H
#define HOMESCREEN_H

class MenuScreen; // Forward declaration

class HomeScreen : public BaseScreen {
public:
    HomeScreen(DisplayStack& ds) : ds(ds), ms(nullptr) {}
    void setMenuScreen(BaseScreen* screen) { this->ms = screen; }

    void display() override {
        BaseScreen::display();
        M5.Lcd.setTextDatum(MC_DATUM);
        M5.Lcd.drawString("hello", 160, 120, 2);
        M5.Lcd.print(M5.Lcd.getTextDatum());
    }

    void loop() override {
        if (M5.BtnA.isPressed() && ms) {
            ds.push(*ms);
            delay(500);
        }
    }

private:
    DisplayStack& ds;
    BaseScreen* ms;
};

#endif