#include <M5Stack.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

// The setup() function runs once each time the micro-controller starts
void setup()
{
  // init lcd, serial, but don't init sd card
  M5.begin(true, false, true);

  /*
    Power chip connected to gpio21, gpio22, I2C device
    Set battery charging voltage and current
    If used battery, please call this function in your project
  */
  M5.Power.begin();

  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.setTextColor(RED);

  // bleの初期化
  bleKeyboard.begin();
  while (!bleKeyboard.isConnected()) {
  };
  M5.Lcd.println("BLE Connected!");
}

// Add the main program code into the continuous loop() function
void loop()
{
  // update button state
  M5.update();

  if (M5.BtnA.wasPressed()) {
    M5.Lcd.println("A was pressed");
    bleKeyboard.press('a');
  }
  else if (M5.BtnA.wasReleased()) {
    M5.Lcd.println("A was released");
    bleKeyboard.release('a');
  }

  if (M5.BtnB.wasPressed()) {
    M5.Lcd.println("B was pressed");
    bleKeyboard.press('b');
  }
  else if (M5.BtnB.wasReleased()) {
    M5.Lcd.println("B was released");
    bleKeyboard.release('b');
  }

  if (M5.BtnC.wasPressed()) {
    M5.Lcd.println("C was pressed");
    bleKeyboard.press('c');
  }
  else if (M5.BtnC.wasReleased()) {
    M5.Lcd.println("C was released");
    bleKeyboard.release('c');
  }
}
