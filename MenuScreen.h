#ifndef MENUSCREEN_H
#define MENUSCREEN_H

class MenuScreen : public BaseScreen {
public:
    MenuScreen(DisplayStack& ds) : ds(ds) {}

    void display() override {
        BaseScreen::display();
        M5.Lcd.setTextDatum(MC_DATUM);
        M5.Lcd.drawString("menu", 160, 120, 2);
        M5.Lcd.print(M5.Lcd.getTextDatum());
    }

    // Override loop() if you need specific actions for the MenuScreen loop.

private:
    DisplayStack& ds;
};

#endif