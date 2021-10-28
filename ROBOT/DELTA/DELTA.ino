int mot_SX_A =4 ;
int mot_SX_I =2 ;
int mot_SX_PWM = 3;

int mot_DX_A =5 ;
int mot_DX_I =7 ;
int mot_DX_PWM = 6; 


int cicalino = 8;
int led = 12;
int baffo;
int count;

int fotores_s,fotores_i; //superiore blue ; inferiore bianco

float front,post,ant;
float distanza_F,distanza_ant,distanza_post;
float dist_F,dist_ant,dist_post,dist_media;

int pwm_sx = 70, pwm_dx=150;

void setup() {
 delay(700);
 pinMode(mot_SX_A,OUTPUT);
 pinMode(mot_SX_I,OUTPUT);
 pinMode(mot_SX_PWM, OUTPUT);
 pinMode(mot_DX_A,OUTPUT);
 pinMode(mot_DX_I,OUTPUT);
 pinMode(mot_DX_PWM, OUTPUT);
 pinMode(cicalino,OUTPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT); 
 pinMode(9,INPUT);
 pinMode(12, OUTPUT);

}

void loop() {
  analogWrite(mot_SX_PWM, pwm_sx);    //guardare frontalmente il robot
  analogWrite(mot_DX_PWM, pwm_dx);
  
  front = analogRead(A2); // frontale
  post= analogRead(A0); // posteriore
  ant = analogRead(A1); // anteriore
  fotores_s= analogRead(A3); //superiore
  fotores_i= analogRead(A4); //inferiore
  baffo = digitalRead(9);
  sharp_F();
  sharp_post();
  sharp_ant();
   
  
  
  if(dist_F<12 && dist_F>0){  
    fermo();
    delay(50);
    
    verso_sxx();
    delay(150);
  }
  else{
    avanti();
  }
  
  if (dist_ant < 10 || dist_post < 10){//avvicinamento
    verso_dx();
    //delay(5);
  }
   else{
    avanti();
  }
                                                             
   if (dist_ant>12 || dist_post>12){//allontanamento   
    verso_sx();
    //delay(5);
  }
  else{
    avanti();
  }

  if(dist_ant > 18 || dist_post > 18){
    
    avanti();
    delay(100);
    fermo();
    delay(50);
    verso_dxx();
    delay(120);
    fermo();
    delay(50); 
    avanti();
    delay(150);
    
  }
  if (baffo == 1){
    dietro();
    delay(150);
    verso_sxx();
    delay(150);
    }
    else{
    avanti();
  }

  if(fotores_i - fotores_s > 90){
    fermo();
    lamp();
    avanti();
    count++;
    }
     else{
    avanti();
  }
  if(count == 4){
    verso_sxx();
    delay(500);
    avanti();
    delay(1250);
    count = 0;
  }

  
 
 
 }
