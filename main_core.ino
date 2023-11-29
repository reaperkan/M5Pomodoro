#include <M5Core2.h>
#include "DisplayStack.h"
#include "MenuScreen.h"
#include "HomeScreen.h"


DisplayStack ds;
HomeScreen hs(ds);
MenuScreen ms(ds);

void setup() {
    M5.begin();
    hs.setMenuScreen(&ms);
    ds.push(hs);
}

void loop() {
    M5.update();
    ds.loop();
    if(M5.BtnC.wasPressed()){
      ds.pop();
    }
}
