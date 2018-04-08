#ifndef COMMAND_SERVER
#define COMMAND_SERVER

#include "ESP8266WiFi.h"
#include "StreamServer.h"
#include "CommandClient.h"

class CommandServer : public StreamServer {
  
public:
  CommandServer( int forPort ) : StreamServer( forPort ) {

  }

protected:
  virtual StreamClient* createClient( WiFiClient client ) {

      return new CommandClient( client );
  }
};

#endif
