void FOTORESISTENZE () {
  fotI = analogRead (A14);
  fotS = analogRead (A15);

  if(fotI-fotS>260)
  { STOP();
    digitalWrite(buzzer, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rosso, HIGH);
    digitalWrite(led_blu, HIGH);
    delay (500);
     digitalWrite(buzzer, LOW);
     digitalWrite(led_verde, HIGH);
    digitalWrite(led_rosso, HIGH);
    digitalWrite(led_blu, HIGH);
    delay (500);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rosso, HIGH);
    digitalWrite(led_blu, HIGH);
    delay (500);
    digitalWrite(buzzer, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rosso, HIGH);
    digitalWrite(led_blu, HIGH);
    delay (500);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rosso, HIGH);
    digitalWrite(led_blu, HIGH);
    delay (500);
    digitalWrite(buzzer, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rosso, HIGH);
    digitalWrite(led_blu, HIGH);
    delay (500);
    AVANTI(1,1);
    delay(300);
    conta_luci++;}}

