#include <LiquidCrystal.h>

// include the library code:
//connect mq135 data pin to A0
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 8           //dht data pin  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
char val;  //variable for storing blutooth data
int a;    //variable for analogRead MQ135


void setup() {
  
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("MINI PROJECT");
  delay(4000);
  lcd.clear();
  Serial.println("//////");
  dht.begin();
  pinMode(11, OUTPUT); //for buzzer.
  //pinMode( 8, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

}// DHT 11 temprature and humidity code

void loop() {

  int h = dht.readHumidity();
  int t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Humidity :");
  lcd.print(h);
  Serial.println(h);
  lcd.setCursor(0, 1);
  lcd.print(("Temperature:"));
  lcd.print(t);
  lcd.print("'C");
  Serial.println(h);
  delay(500);
}
 /* // MQ135 Smoke/Gas sensor code

  a = analogRead(0);
  if (a > 275)
  {
    digitalWrite(13, HIGH);
    lcd.clear();
    lcd.print("SMOKE");
    lcd.setCursor(0, 1);
    lcd.print ("DETECTED");
    delay(1000);
    Serial.print("MQ135 DATA ");
    Serial.print(a);
    digitalWrite(11, HIGH);


  }
  else {
    //digitalWrite(13, LOW);
    //delay(1000);
  }

  // Code for Bluetooth

  if (Serial.available()) {
    val = Serial.read();
    Serial.println(val);
  }
  if (val == '1') {
    digitalWrite(13, LOW);

  }
  else if (val == '2') {
    digitalWrite(13, HIGH);

  }
  Serial.println(a);

}*/
