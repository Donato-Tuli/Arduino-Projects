void PERIMETRO() {
  SHARP();
  FOTORESISTENZE();
  SUONO();
 


  B = digitalRead(39); //TOCCO DEL BAFFO
  if (B == 0) {
 analogWrite(pwm_dx,H-20);
  analogWrite(pwm_sx,H-50);
  digitalWrite(avantidx,0);
  digitalWrite(dietrodx,1);
  digitalWrite(avantisx,1);
  digitalWrite(dietrosx,0);
  est=0;
  }

  else {



    if (SHARPLATERALE1 >= 4 && SHARPLATERALE1 < 6 && SHARPLATERALE2 >= 4 && SHARPLATERALE2 < 6 && SHARPFRONTALE >= 10) { //DISTANZA CORRETTA 8 10
      AVANTI(0, 0);
    }


    if (SHARPLATERALE1 >= 6 && SHARPLATERALE1 < 20 || SHARPLATERALE2 >= 6 && SHARPLATERALE2 < 20 && SHARPFRONTALE >= 10 ) { //AVVICINAMENTO
      
      AVANTI(30, 0);
    }

    if (SHARPLATERALE1 < 4 || SHARPLATERALE2 < 4 && SHARPFRONTALE >= 10) { //ALLONTANAMENTO
      AVANTI(0, 30);
    
    }

    if (SHARPFRONTALE < 11) { //ANGOLO INTERNO
      ruotadx(-20, -20);
      delay(5);
    }

if (SHARPLATERALE1 >= 12 && SHARPLATERALE2 >= 12 && SHARPFRONTALE > 8 && f==0 ){
   SHARP();
   STOP();
   est=est+1;
   delay(300);
    ruotasx(0,0);
    delay(400);
   t0=millis(); f=1;}
  
  if (SHARPLATERALE1 >= 16 && SHARPLATERALE2 >= 12 && SHARPFRONTALE > 8 && f==1 ){
     SHARP();
     t1=millis(); 
     if(t1-t0>=0 && t1-t0<700){ AVANTI(0,0);}
     if(t1-t0>700){f=0;}
     

 
   

}}}
    

      

      
     




