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

  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");

    while (client.connected() && client.available() ) {

        if ( handleRequest( client ) == false ) {

           break;
        }
    }

    client.stop();
    Serial.println("client disonnected");
  }
}

bool handleRequest( WiFiClient client ){

    String cmd = readCommand( client );

    if( cmd == "test" ) {

      Serial.println( "test");
      return true;
    } else if( cmd == "quit" ) {

      Serial.println( "quit");
      return false;
    } else {

      Serial.println( "Unknown Command");
      return true;
    }
}

int readInt( WiFiClient client ) {

  char c1 = client.read();
  char c2 = client.read();

  int result = 0;
  *(((char*) &result) + 0) = c1;
  *(((char*) &result) + 1) = c2;

  return result;
}

String readCommand( WiFiClient client ) {

  return readData( client, 4 );
}

String readData( WiFiClient client, int length ) {

    String result = "";
    for ( int pos = 0; pos < length; pos ++ ){

        if ( ! client.available() || ! client.connected() ){

          return ( "quit" );

        } else {

          result = result + client.read();
        }
    }

    return result;
}
