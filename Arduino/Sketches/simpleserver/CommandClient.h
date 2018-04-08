#ifndef COMMAND_CLIENT
#define COMMAND_CLIENT
 
#include "ESP8266WiFi.h"
#include "StreamClient.h"

class CommandClient : public StreamClient {

public:
   CommandClient( WiFiClient forClient ) : StreamClient( forClient ) {

   }
    
  virtual bool run() {

    String cmd = nextCommand();
    if ( cmd == "exit" ) {

      Serial.println( "Exit Command reveived" );

        stop();
      return false;
    
    } else {

        return handleCommand( cmd );
    }
  }

  String nextCommand() {

     return readString( readInt() );
  }

protected:

  virtual bool handleCommand( String cmd ) {

     return false;
  }
};

#endif
