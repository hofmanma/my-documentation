#ifndef STREAM_CLIENT
#define STREAM_CLIENT

#include "ESP8266WiFi.h"

class StreamClient {

  protected:
    WiFiClient client;
  
  public:
  
    StreamClient( WiFiClient forClient ) {

      client = forClient;
    }

    virtual bool run() {

      return false;
    }
    
    int readInt() {

      int result = 0;
      for ( int pos = 0; pos < sizeof( int ); pos ++ ) {

         char c = client.read();
         *(((char*) &result) + pos) = c;
      } 
           
      return result;
    }

    float readFloat() {

      float result = 0;
      for ( int pos = 0; pos < sizeof( float ); pos ++ ) {

         char c = client.read();
         *(((char*) &result) + pos) = c;
      } 
           
      return result;
    }
  
  String readString( int length ) {

    String result = "";
    for ( int pos = 0; pos < length; pos ++ ){

        if ( isAvailable() ) {
          
          result = result + client.read();
        
        } else {

          return ( "quit" );
        } 
    }

    return result;  
  }

  void sendInt( int value ) {

    for ( int pos = 0; pos < sizeof( int ); pos ++ ) {

       char c = *(((char*) &value) + pos);
       client.print( c );
    }
  }

  void sendFloat( float value ) {

    for ( int pos = 0; pos < sizeof( float ); pos ++ ) {

       char c = *(((char*) &value) + pos);
       client.print( c );
    }
  }
  
  bool sendString( String data ) {

    if ( isAvailable() ) {

      client.print( "##" );
      
      sendInt( data.length() ); 
      client.print( data );

      return true;
      
    } else {

      return false; 
    }
  }

  void stop() {

    client.stop();
    
    Serial.println("client disonnected");
  }
  
  protected:
    
    bool isAvailable() {

       return client.available() && client.connected();
    }
};

#endif
