#include "ESP8266WiFi.h"

char ssid[] = "WLAN-xy";       // your network SSID (name)
char pass[] = ""; // your network password

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {

  Serial.begin(9600);
  Serial.println("..Starting Server");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
  }

  int count = 0;
  for ( count = 0; count < 20 ; count++ )  {
      delay(500);

      status = WiFi.status();
      Serial.print( count ); Serial.print( " WifiStat: " );
      Serial.println( status );
      if ( status == WL_CONNECTED ) {
        break;
      }
  }

  if ( count == 20 ) {

    Serial.println( "Couldn't get a wifi connection." );
  }
  else {

    server.begin();
    Serial.print("Connected to wifi. My address:");
    Serial.println( WiFi.localIP() );
  }
}

void loop() {

}
