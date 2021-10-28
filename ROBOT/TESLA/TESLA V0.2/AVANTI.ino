void AVANTI(float W1 ,float W2){
  analogWrite(pwm_dx,H+W1+80);
  analogWrite(pwm_sx,H+W2+9);
  digitalWrite(avantidx,1);
  digitalWrite(dietrodx,0);
  digitalWrite(avantisx,1);
  digitalWrite(dietrosx,0);} 
