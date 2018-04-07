
////////////////////////////
// Nano MCU - Build In Led
////////////////////////////
// the ESP8266 has a builtin led that is attached to D4 as labeled 
// on LoLin boards which maps to GPIO2. One thing to Note is
// that the led is active low. 
////////////////////////////////
// In other words ... setting PIN 2 to '0' will turn the LED ON 
// and setting PIN 2 to '1' will turn the LED OFF

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);
  delay(1000);
  digitalWrite(2, HIGH); 
  delay(1000);  
}
