#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
 
#define DHTPIN 8                                           
#define DHTTYPE DHT22                                      
DHT dht(DHTPIN, DHTTYPE);                                  
 
float humidity, temperature;                               
 
void setup() {
  dht.begin();   
  Serial.begin(9600);                                            
}
 
void loop() {
  humidity = dht.readHumidity();                           
  temperature = dht.readTemperature();                     

  Serial.println( "Temperature:" );
  Serial.println( temperature );

  Serial.println( "Humidity:" );
  Serial.println( humidity );
 
  delay(2000);
}
