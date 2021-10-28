#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



int valore,B,R0,bottone;
double temp,tempdht,hum,diff;

void setup() {
  pinMode(A0,INPUT);
  pinMode(7,INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  delay(1000);
  tempdht = dht.readTemperature();
  hum = dht.readHumidity();
  //valore = analogRead(A0);
  B = 3950; 
  R0 = 23000; // 23K ohm ed è la resistenza a 25°C
  /*
  double V=(5/1023.00)*valore; //la tensione serve per la resistenza
  double R=((10000.00*5)/V)-10000.00; // la resistenza è quella della sonda dataci dal partitore
  double T=B/log(R/(R0*pow(M_E,(-B/298.15)))); // formula per il calcolo della temperatura 
  temp = T-273,15;

  diff = temp-tempdht;
  */
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: " + String(tempdht));
  lcd.setCursor(0,1);
  lcd.print("Umidita': " + String(hum));
  bottone = digitalRead(9);
  
  if(bottone == 0){
    delay(50);
    valore = analogRead(A0);
    
    double V=(5/1023.00)*valore; //la tensione serve per la resistenza
    double R=((10000.00*5)/V)-10000.00; // la resistenza è quella della sonda dataci dal partitore
    double T=B/log(R/(R0*pow(M_E,(-B/298.15)))); // formula per il calcolo della temperatura 
    temp = T-273,15;
    diff = tempdht - temp;
    if(diff < 4 && diff > -4){ // LCD
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sonda buona");
      lcd.setCursor(0,1);
      lcd.print("Temp letta: " + String(temp));
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sonda rotta.");
      lcd.setCursor(0,1);
      lcd.print("Temp " + String(temp));
    }
    delay(1500);
  }
}
