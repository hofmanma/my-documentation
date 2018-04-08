#ifndef STREAM_SERVER
#define STREAM_SERVER

#include "ESP8266WiFi.h"
#include "StreamClient.h"

class StreamServer {

  protected:
    WiFiServer* server;
    int         status;

  public:
    StreamServer( int forPort ) {

      WiFi.mode(WIFI_STA);
      WiFi.disconnect();

      server = new WiFiServer( forPort );
      status = WL_IDLE_STATUS;
    }

    bool login( char* ssid, char* password ) {

      if (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password);
      }

      int count = 0;
      for ( count = 0; count < 20 ; count++ )  {
          delay(500);

        status = WiFi.status();
        if ( status == WL_CONNECTED ) {
          break;
        }
      }

      if ( count == 20 ) {

        return false;

      } else {

        server->begin();

        return true;
     }
  }

  StreamClient* listen() {

    WiFiClient client = server->available();
    if (client && client.connected() && client.available()) {

       return createClient( client ); 

    } else {

       return NULL;
    }
  }

protected:

  virtual StreamClient* createClient( WiFiClient client ) {

      return new StreamClient( client );
  }
};

#endif
