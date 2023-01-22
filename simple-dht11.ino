//
// This is a simple example of an Arduino microcontroller in combination with a DHT11 sensor
// It assumed you have the DHT libs loaded in your arduino libraries directory
// 
#include <DHT.h>
#define Type DHT11

// connect the sensor to pin on Arduino

int sensePin=2;

// create the object
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime=500;

// set a time for delay in miliseconds
// the output will be once every minute
int dt=20000;

// setup the Arduino
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
HT.begin();
delay(setTime);

}

// Perform the loop and print the results to the serial monitor
void loop() {
  // put your main code here, to run repeatedly:
humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print(" Temperature C ");
Serial.print(tempC);
Serial.print(" C ");
Serial.print(tempF);
Serial.print(" F ");
Serial.print('\n');
delay(dt);

}
