#include "ESP8266WiFi.h"
#include "TestServer.h"
#include "StreamClient.h"

TestServer* server;

void setup() {

  Serial.begin(9600);

  server = new TestServer(80);
  if ( server->login( "WLAN-xy","Password")) {

    Serial.println(".. Server listening on port 80.");

  } else {

    Serial.println(".. Server could not be started.");

    delete server;
    server = NULL;
  }
}

void loop() {

    if ( server ) {

      StreamClient* client = server->listen();
      if ( client ) {

          Serial.println(".. Client connected and running.");
          while ( client->run() ) {

              delay( 10 );
          }

          delete client;
          Serial.println(".. Client Closed.");
      }
  }
}
