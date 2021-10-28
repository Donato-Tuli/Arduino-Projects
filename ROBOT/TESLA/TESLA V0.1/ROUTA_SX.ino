void ruotasx(float S1 ,float S2){
  analogWrite(pwm_dx,H+S1+80);
  analogWrite(pwm_sx,H+S2+9);
  digitalWrite(avantidx,1);
  digitalWrite(dietrodx,0);
  digitalWrite(avantisx,0);
  digitalWrite(dietrosx,1);}
