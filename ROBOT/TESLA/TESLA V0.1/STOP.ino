void STOP() {
  analogWrite(pwm_dx,0);
  analogWrite(pwm_sx,0);
  digitalWrite(avantidx,0);
  digitalWrite(dietrodx,0);
  digitalWrite(avantisx,0);
  digitalWrite(dietrosx,0);
}
