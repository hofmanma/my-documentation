//////////////////////////////////////////////////////////////////////////////////
// Temperatur und Feuchtigkeitsmessung
////////////////////////////////////////
// http://www.arduino-tutorial.de/temperatur-und-luftfeuchtigkeit-messen-dht22/
//////////
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
 
#define DHTPIN 8                                           
#define DHTTYPE DHT22                                      
DHT dht(DHTPIN, DHTTYPE);                                  
  
void setup() {
  dht.begin();   
  Serial.begin(9600);                                            
}
 
void loop() {

  Serial.println( "Temperature:" );
  Serial.println( dht.readTemperature() );

  Serial.println( "Humidity:" );
  Serial.println( dht.readHumidity() );
 
  delay(2000);
}
