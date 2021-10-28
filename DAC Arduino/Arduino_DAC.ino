//input dig 0 1 2 4 7 8 12 13
// output PWM 3

int in0 = 0, in1 = 1, in2 = 2, in3 = 4, in4 = 7, in5 = 8, in6 = 12, in7 = 13, PWM_pin = 3;
int n0,n1,n2,n3,n4,n5,n6,n7;
int argm;


void setup() {
  pinMode(in0,INPUT); // dichiarazione degli ingressi digitali 
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode(in4,INPUT);
  pinMode(in5,INPUT);
  pinMode(in6,INPUT);
  pinMode(in7,INPUT);
  pinMode(PWM_pin,OUTPUT); // dichiarazione dell'uscita PWM sul pin 3
}

void loop() {
  delay(10);
  n0 = digitalRead(in0); // lettura dei pin digitali
  n1 = digitalRead(in1);
  n2 = digitalRead(in2);
  n3 = digitalRead(in3);
  n4 = digitalRead(in4);
  n5 = digitalRead(in5);
  n6 = digitalRead(in6);
  n7 = digitalRead(in7);

  argm = (n0*1)+(n1*2)+(n2*4)+(n3*8)+(n4*16)+(n5*32)+(n6*64)+(n7*128); // conversione dal sistema binario al sistema decimale

  analogWrite(PWM_pin, argm); // output
  

}
