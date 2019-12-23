#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7
#define FAN_PIN 13
#define LED_BLUE_PIN 8
#define LED_GREEN_PIN 10
#define LED_RED_PIN 9
void setup()

{
  
 pinMode(FAN_PIN, OUTPUT);
 pinMode(LED_BLUE_PIN, OUTPUT);
 pinMode(LED_GREEN_PIN, OUTPUT);
 pinMode(LED_RED_PIN, OUTPUT);

 
 lcd.begin(20 , 4);
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("Project By : ");
 lcd.setCursor(4,2);
 lcd.print("AMIR SHARIFI ");

 delay (5000);

}

void loop()

{
  
 int temperature = DHT.temperature;
 int sensor_value = analogRead(0);
 int chk = DHT.read11(DHT11_PIN);
 int humidity = DHT.humidity;



 
 lcd.clear();

 lcd.setCursor(0,0);
 lcd.print("Soil Moisture : ");
 lcd.print(sensor_value);

 lcd.setCursor(0,1);
 lcd.print("Temperature : ");
 lcd.print(temperature);
 lcd.print((char)223); 
 lcd.print("C");

 lcd.setCursor(0,2);
 lcd.print("Humidity : ");
 lcd.print(humidity);
 lcd.print("%");


 
  if (sensor_value >= 1000) {
   digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_GREEN_PIN, LOW);
     digitalWrite(LED_BLUE_PIN, LOW);
 
  };
  if ((sensor_value <= 999) && (sensor_value >=901)) {
    digitalWrite(LED_BLUE_PIN, HIGH);
     digitalWrite(LED_GREEN_PIN, LOW);
     digitalWrite(LED_RED_PIN, LOW);
  
  }
  ;
if (sensor_value <= 900) {
   digitalWrite(LED_GREEN_PIN, HIGH);
   digitalWrite(LED_RED_PIN, LOW);
   digitalWrite(LED_BLUE_PIN, LOW);
  };

  
  if (temperature > 27 )
  {

        digitalWrite(FAN_PIN, HIGH);
        lcd.setCursor(0,3);
        lcd.print("Fan Status : ON ");  
        
  }
  else 
  {

        digitalWrite(FAN_PIN, LOW);
        lcd.setCursor(0,3);
        lcd.print("Fan Status : OFF ");  
  }

  delay(1500);

}


// project by amir sharifi
