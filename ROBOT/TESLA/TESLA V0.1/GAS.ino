void GAS () {
  Gas = analogRead (A0);
 
 if (Gas > 1200){
  



      STOP();
      digitalWrite(buzzer, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_rosso, LOW);
      digitalWrite(led_blu, HIGH);
      delay (500);
      digitalWrite(buzzer, LOW);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_rosso, HIGH);
      digitalWrite(led_blu, HIGH);
      delay (500);
      digitalWrite(buzzer, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_rosso, LOW);
      digitalWrite(led_blu, HIGH);
      delay (500);
      digitalWrite(buzzer, LOW);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_rosso, HIGH);
      digitalWrite(led_blu, HIGH);
      delay (500);
      digitalWrite(buzzer, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_rosso, LOW);
      digitalWrite(led_blu, HIGH);
      delay (500);
      digitalWrite(buzzer, LOW);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_rosso, HIGH);
      digitalWrite(led_blu, HIGH);
      delay (500);
      AVANTI(1, 1);
      delay(300);
      }}


