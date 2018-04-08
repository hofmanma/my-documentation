#ifndef TEST_SERVER
#define TEST_SERVER

#include "ESP8266WiFi.h"
#include "CommandServer.h"
#include "TestClient.h"

class TestServer : public CommandServer {

public:
  TestServer( int forPort ) : CommandServer( forPort ) {

  }

protected:
  virtual StreamClient* createClient( WiFiClient client ) {

      return new TestClient( client );
  }
};

#endif
