 void ruotadx(float D1 ,float D2){
  analogWrite(pwm_dx,H+D1+80);
  analogWrite(pwm_sx,H+D2+9);
  digitalWrite(avantidx,0);
  digitalWrite(dietrodx,1);
  digitalWrite(avantisx,1);
  digitalWrite(dietrosx,0);
 }
