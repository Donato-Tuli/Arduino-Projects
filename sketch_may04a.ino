// Librerie
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
WiFiServer server(80);
#include <SoftwareSerial.h>
IPAddress local_IP(192,168,43,160);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);
#include <Wire.h> 
#include <TEA5767N.h>
TEA5767N radio=TEA5767N();
#include <LiquidCrystal.h>
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(D0, D4, D3, D5, D6, D7);

#include<PrintString.h>

//SCL = D1;
//SDA = D2;

// WiFi SSID e Password //
const char* ssid = "Infostrada-830E1E";
const char* password = "34B8EYQMRH";
WiFiClient client;

//Variabili//
String nome_radio;
float value;
float freq;
String l;
String c;
float t;
String i;
String valore;
String result,off="-1",apertura;
char servername[]="api.openweathermap.org";

// Meteo //
String APIKEY = "d418343d23db879ff4e644100f845c16";                                 
String CityID = "3168699"; 

void setup() {
  
  Serial.begin(115200);
  lcd.begin(16, 2);
  radio.setStandByOn();
  radio.selectFrequency(87.5);
  // Inizio I2C //
  Wire.begin();
  Wire.setClock(400000L);

  // WiFi //
  WiFi.begin(ssid, password);
  server.begin();
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP("DT_Radio");
  Serial.print("Connessione in corso.");
  while ( WiFi.status() != WL_CONNECTED ){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connesso");
  lcd.setCursor(0, 0);
  lcd.print("Connesso");
  lcd.setCursor(0, 1);
  lcd.print("192,168,43,160");
  delay(1000); 
  apertura = "-1";
}

void loop() {
  if(off == apertura){
    apertura = "0";
  if (client.connect(servername, 80)){  //Inizio l'apertura del server                                            
          client.println("GET /data/2.5/weather?id="+CityID+"&units=metric&lang=it&APPID="+APIKEY);
          client.println("Host: api.openweathermap.org");
          client.println("User-Agent: ArduinoWiFi/1.1");
          client.println("Connection: close");
          client.println();
          } 
  else {
         Serial.println("Connessione fallita");   
         Serial.println();
       }

  while(client.connected() && !client.available()) 
  delay(1);
  while (client.connected() || client.available())    
       {                                             
         char c = client.read();                     
         result = result+c;
         continue;
       }

  client.stop();                                      
  result.replace('[', ' ');
  result.replace(']', ' ');
  //Serial.println(result);
  char jsonArray [result.length()+1];
  result.toCharArray(jsonArray,sizeof(jsonArray));
  jsonArray[result.length() + 1] = '\0';
  StaticJsonBuffer<1024> json_buf;
  JsonObject &root = json_buf.parseObject(jsonArray);

  if (!root.success()){
      Serial.println("parseObject() failed");
  }
  //LOCATION
  String location = root["name"];
  String country = root["sys"]["country"];
  float temperature = root["main"]["temp"];
  l=location;
  c=country;
  t=temperature;
}
  // TEMPERATURA o METEO //
  lcd.setCursor(0, 0);
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.print(l);
  lcd.print(",");
  lcd.print(c);

  
  // Radio //
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Aspetta dati dall'utente //
  while(!client.available()){
    delay(1);
  }
  // Legge i dati inviati dall'utente //
  String request = client.readStringUntil('\r');
  client.flush();
  
  if (request.startsWith("RadioCapital=1", 5))  {         //Radio Capital
    value = 95.8;
    nome_radio="Radio Capital";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("R.Capital");
    lcd.setCursor(10,1);
    lcd.print(value);
}
   if(request.startsWith("RadioKissKiss=2", 5))  { 
    value = 99.3;      //Radio Kiss Kiss
    nome_radio="Radio Kiss Kiss";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("R.KissKiss");
    lcd.setCursor(11,1);
    lcd.print(value);
   }
   if(request.startsWith("RadioPotenzaCentrale=3", 5))  { 
    value = 89.9;     //Radio potenza centrale
    nome_radio="R Potenza Centrale";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("R.Po.Centr");
    lcd.setCursor(11,1);
    lcd.print(value);
  }
    if (request.startsWith("RTL=4", 5))  { 
    value = 94.1;            //RTL
    nome_radio="RTL 102.5";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("RTL");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
   if(request.startsWith("RadioDeejay=5", 5))  { 
    value = 88;        //Radio Deejay
    nome_radio="Radio Deejay";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("R.Deejay");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
  if (request.startsWith("RDS=6", 5))  { 
    value = 96.5;                //RDS
    nome_radio="RDS Grandi Successi";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("RDS");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
  if (request.startsWith("RadioMaria=7", 5))  { 
    value = 92.4;         //Radio Maria
    nome_radio="Radio Maria";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("R.Maria");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
  if (request.startsWith("Radiocentocinque=8", 5))  { 
    value = 105.0;    //Radio 105
    nome_radio="Radio 105";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Radio 105");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
  if (request.startsWith("RadioItalia=9", 5))  { 
    value = 106.0;       //Radio Italia
    nome_radio="Radio Italia";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("R.Italia");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
  if(request.startsWith("Rcentouno=10", 5))  { 
    value = 101.8;      //R101
    nome_radio="Radio 101";
    radio.setStandByOff();
    radio.selectFrequency(value);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Radio101");
    lcd.setCursor(10,1);
    lcd.print(value);
  }
    if (request.startsWith("x", 15))  { 
    valore = request.substring(17);
    valore.replace("+", " ");
    valore.replace(" HTTP/1.1", " ");
    valore.toFloat();
    radio.setStandByOff();
    radio.selectFrequency(value);
    Serial.println(valore);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Frequenza=");
    lcd.setCursor(11,1);
    lcd.print(value);
    }
}
