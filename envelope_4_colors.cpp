#include <M5Stack.h>
int cnt = 0;
int state = 0;

void setup(){
  M5.begin();
  M5.Lcd.setTextSize(4);
}

void loop(){
  M5.update();

  int w = M5.Lcd.width();
  int h = M5.Lcd.height();
  if (cnt < 0 || 4 * cnt > min(h, w)){
    cnt = 0;
  } else {
    cnt++;
  }

  if (M5.BtnA.wasReleased()){
    state = 1;
  } else if (M5.BtnB.wasReleased()){
    state = 2;
  } else if (M5.BtnC.wasReleased()){
    state = 3;
  } else if (M5.BtnB.wasReleasefor(300)){
    state = 0;
  }

  if (state == 0){
    M5.Lcd.clear();
  } else if (state == 1){
    if (8 * cnt < min(h, w)){
      M5.Lcd.drawLine(0, h - 4 * cnt, 4 * cnt, 0, RED);
    } else {
      M5.Lcd.drawLine(0, h - 4 * cnt, 4 * cnt, 0, BLUE);
    }
  } else if (state == 3){
    if (8 * cnt < min(h, w)){
      M5.Lcd.drawLine(4 * cnt, h, w, h - 4 * cnt, YELLOW);
    } else {
      M5.Lcd.drawLine(4 * cnt, h, w, h - 4 * cnt, GREEN);
    }
  }
}
