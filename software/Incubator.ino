#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>
// #define ONE_WIRE_BUS 2

// OneWire oneWire(ONE_WIRE_BUS);
// DallasTemperature sensors(&oneWire);
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x38, 16, 2);

int startButton = 8;
int buttonState;
int heatPin = 9;
double temp_value = 0;
int pot = A0;
int pot_value;
double curTemp;
double prevTemp;
double max_temp = 0;


double set_pot() {
  pot_value = analogRead(pot);
  double max_value = map(pot_value, 0, 1023, 0, 100); //This is the desired temperature value
  return max_value;
}

long convert_time(long millisec) {
  int seconds = millisec/1000;
  if (seconds < 60) {
    lcd.print(seconds);
    lcd.print("secs");
  } else if (seconds == 60) {
    int minutes = seconds/60;
    lcd.print(minutes);
    lcd.print("mins");
  }
}


boolean heatUp(double desired_temp) {
  unsigned long startTime = millis();
  // sensors.requestTemperatures();
  curTemp = dht.readTemperature();
  // Serial.print(curTemp);
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(curTemp);
  lcd.print((char)223);
  lcd.print("C");
  while (curTemp < desired_temp) {
    int pulseDuration = min(10000,20000);
    digitalWrite(heatPin,LOW);
    delay(pulseDuration);
    digitalWrite(heatPin,HIGH);

    // check if temperatue is equal to or more than desired temperature
    curTemp = dht.readTemperature();
    // Serial.print(curTemp);
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(curTemp);
    lcd.print((char)223);
    lcd.print("C");
    if (curTemp >= desired_temp)
    break;

    // Wait a little as we approach desired temperature to avoid overheating
    if ((desired_temp - curTemp) < 2){
      do {
        prevTemp = curTemp;
        delay(1000);
        curTemp = dht.readTemperature();
        lcd.setCursor(0,1);
        lcd.print("Temp: ");
        lcd.print(curTemp);
        lcd.print((char)223);
        lcd.print("C");
        // Serial.print(curTemp);
      } while(curTemp > prevTemp);
    }

    // check if temperature is equal to or more than desired temperature
    if (curTemp >= desired_temp)
    break;
  }
  return true;
}

void holdConstantTemp(double idealTemp) {
  while (true) {
    lcd.setCursor(0,1);
    lcd.print(idealTemp);
    lcd.print((char)223);
    lcd.print("C");
    curTemp = dht.readTemperature();
    Serial.print(curTemp);
    if (curTemp < idealTemp) {
      digitalWrite(heatPin,HIGH);
      delay(5000);
      digitalWrite(heatPin,LOW);
    } else if (curTemp > (idealTemp+0.5)) {
      digitalWrite(heatPin,HIGH); //Turning off source of heat so it cools down naturally
    }
    delay(2000);
  }
}

void runIncubator() {
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Set Temp:");
  while (true) {
    lcd.setCursor(9,0);
    temp_value = set_pot();
    lcd.print(temp_value);
    lcd.print((char)223);
    lcd.print("C");
    // Serial.println(temp_value);
    // Serial.println("deg Celcius");
    buttonState = digitalRead(startButton);
    if (buttonState == LOW) {
      break;
    }
    delay(1000);
   }
  unsigned long startTime = millis();
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HEATING UP");
  if (!heatUp(temp_value)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Heat can't raise");
    lcd.setCursor(0,1);
    lcd.print("Something wrong");
  } else {
    //do nothing;
  }
  long timeElapsed = millis() - startTime;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Total heat time");
  lcd.setCursor(0,1);
  lcd.print(convert_time(timeElapsed));
  // Serial.println();
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Holding temp");
    
  max_temp = temp_value;
  holdConstantTemp(max_temp);
}


void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(startButton,INPUT);
  pinMode(heatPin,OUTPUT);
  digitalWrite(startButton,HIGH);
  digitalWrite(heatPin,HIGH);
  lcd.setCursor(0,0);
  lcd.print("Starting in ");
  delay(1000);
  for (int i = 5; i > 0; i--) {
    lcd.setCursor(13,0);
    lcd.print(i);
    lcd.print("..");
    delay(1000);
  }
  runIncubator();
}

void loop() {
  // put your main code here, to run repeatedly:

}
