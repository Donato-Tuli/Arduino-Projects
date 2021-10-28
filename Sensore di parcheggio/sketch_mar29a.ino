#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 2, 3, 4, 5);

#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int x;

void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  lcd.begin(16,2);
  
}

void loop() {
  /*
  Serial.print("Distanza in cm: ");
  Serial.println(ultrasonic.distanceRead());
  delay(1000);*/
  /*delay(1);
  lcd.setCursor(0,0);
  lcd.print("Distanza:");
  delay(10);
  lcd.setCursor(1,1);
  lcd.print(String(ultrasonic.distanceRead()));
  lcd.setCursor(10,1);
  lcd.print("cm");
  delay(1000);
  lcd.clear();
  */
  x = ultrasonic.distanceRead();

  if (x < 100){
    digitalWrite(7,1);
    delay(x*10);
    digitalWrite(7,0);
    delay(x*10);
  }
  
}
