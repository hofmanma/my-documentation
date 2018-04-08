#ifndef LED_SERVER
#define LED_SERVER

#include "ESP8266WiFi.h"
#include "CommandServer.h"
#include "LEDClient.h"

class LEDServer : public CommandServer {

public:
  LEDServer( int forPort ) : CommandServer( forPort ) {

  }

protected:
  virtual StreamClient* createClient( WiFiClient client ) {

      return new LEDClient( client );
  }
};

#endif
