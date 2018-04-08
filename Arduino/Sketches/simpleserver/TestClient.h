#ifndef TEST_CLIENT
#define TEST_CLIENT

#include "ESP8266WiFi.h"
#include "CommandClient.h"

class TestClient : public CommandClient {

public:

  TestClient( WiFiClient forClient ) : CommandClient( forClient ) {

     pinMode(3, OUTPUT);
  }
   
  virtual bool handleCommand( String cmd ) {

      Serial.println( "Command .. " + cmd  );
      
      if ( cmd == "LEDON" ) {

        digitalWrite(3, LOW);
        
      } else if ( cmd == "LEDOFF" ) {

        digitalWrite(3, HIGH);
      } 
      
      return true;
  }
};

#endif

