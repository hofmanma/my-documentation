#ifndef TEST_CLIENT
#define TEST_CLIENT

#include "ESP8266WiFi.h"
#include "CommandClient.h"

class TestClient : public CommandClient {

public:

  TestClient( WiFiClient forClient ) : CommandClient( forClient ) {

   }
   
  virtual bool handleCommand( String cmd ) {

     return true;
  }
};

#endif

