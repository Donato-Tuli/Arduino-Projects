int avantidx=13;              //AVANTI DESTRA
int dietrodx=12;              //DIETRO DESTRA
int pwm_dx=11;                //PWM MOTORE DESTRO
int avantisx=9;               //AVANTI SINISTRA
int dietrosx=8;               //DIETRO SINISTRA
int pwm_sx=10;                //PWM MOTORE SINISTRO
int buzzer=7;                 //PIN BUZZER
int led_verde=6;              //PIN LED VERDE
int led_rosso=5;              //PIN LED ROSSO
int led_blu=4;                //PIN LED BLU
int fotI,fotS,Suono,Gas;      //VARIABILI DI LETTURA DELLE LDR, DEL SUONO E DEL GAS
float x,y,z,B;                //VARIABILI DI LETTURA DEL BAFFO E DEI VALORI ANALOGICI RESTITUITI DAGLI SHARP
float SHARPFRONTALE;          //VARIABILE IN CUI E' CONTENUTA LA DISTANZA IN CM DELLO SHARP FRONTALE
float SHARPLATERALE1;         //VARIABILE IN CUI E' CONTENUTA LA DISTANZA IN CM DELLO SHARP LATERALE 1
float SHARPLATERALE2;         //VARIABILE IN CUI E' CONTENUTA LA DISTANZA IN CM DELLO SHARP LATERALE 2
float DistFront;              //VARIABILE PER FARE IL CONSTRAIN DELLO SHARP FRONTALE
float DistLate1;              //VARIABILE PER FARE IL CONSTRAIN DEL PRIMO SHARP LATERALE
float DistLate2;              //VARIABILE PER FARE IL CONSTRAIN DEL SECONDO SHARP LATERALE
int conta_luci=0;             //VARIABILE CHE SI INCREMENTA OGNI VOLTA CHE VIENE TROVATA UNA LUCE
int est=0;                    //VARIABILE CHE CONTA GLI ANGOLI ESTERNI NEL CASO SI PERDESSE
float W1,W2,D1,D2,S1,S2;      //PARAMETRI PER MODIFICARE LE VELOCITA'
int H=120;                    //VELOCITA' MOTORI STANDARD        
bool f = 0;                   //FLAG PER FAR FARE L'ANGOLO ESTERNO CONTINUANDO LA LETTURA
long int t0=0,t1=0;           //VARIABILI DI TEMPO PER FARE L'ANGOLO ESTERNO CONTINUANDO LA LETTURA
float l,lunga,DistLunga;      //VARIABILI SHARP A LUNGA DISTANZA
bool s=0;                     //FLAG LETTURA SUONO
long int s1=0,s2=0;           //VARIABILI DI TEMPO PER GESTIRE LA LETTURA DEL SUONO
                     
 
void setup() {
pinMode(avantidx,OUTPUT);
pinMode(dietrodx,OUTPUT);
pinMode(pwm_dx,OUTPUT);
pinMode(avantisx,OUTPUT);
pinMode(dietrosx,OUTPUT);
pinMode(pwm_sx,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(led_verde,OUTPUT);
pinMode(led_rosso,OUTPUT);
pinMode(led_blu,OUTPUT);
pinMode(39,INPUT_PULLUP);
Serial.begin(9600);

digitalWrite(led_verde, HIGH);
digitalWrite(led_rosso, HIGH);
digitalWrite(led_blu, HIGH);}

void loop() {

  
PERIMETRO();

if(est>=5){
  analogWrite(pwm_dx,95);
  analogWrite(pwm_sx, 200+(est*4));
  digitalWrite(avantidx,1);
  digitalWrite(dietrodx,0);
  digitalWrite(avantisx,1);
  digitalWrite(dietrosx,0);
  delay(1500);}


if(conta_luci==4){
  STOP();
  delay(300);
  ruotadx(0,+5);
  delay(425);
  AVANTI(0,0);
while(digitalRead (39)){}
  conta_luci=conta_luci+1;}

if(conta_luci==7){
  STOP();
  delay(300);
  ruotadx(0,+5);
  delay(415);
  AVANTI(0,0);
while(digitalRead (39)){}
  conta_luci=conta_luci+1;}
 
  Serial.print(Gas);
  Serial.print("         ");
  Serial.print(fotI);
  Serial.print("    ");
  Serial.print(fotS);
  Serial.print("    ");
  


  


   

   Serial.println(); 

}
