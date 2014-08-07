/*
  Zigbee Blink
  
  Using the Zigbee connected to my laptop to pass messages into
  Zigbee connected to Arduino.  Based on these messages, the Arduino
  will send logic signals that will brighten or dim an attached LED
 */
 
#include <SoftwareSerial.h>
SoftwareSerial XBee(2, 3); //RX, TV of XBee

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int led_blue = 13;
const int led_green = 11;
const int led_red = 9;

int intensity = 20;
int value;

const int MAXINTENSITY = 40;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digitals pin as inputs and outputs
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(led_red, OUTPUT);
 
  // initialize Xbee and Arduino Serial Ports
  XBee.begin(9600);
  Serial.begin(9600); 
}

// the loop routine runs over and over again forever:
void loop() {
  
  if (XBee.available()) { 
     // if data arrives through the XBee, print data on serial monitor and take action
     value = XBee.read();
     Serial.write(value);
     
     if (value == 'u') {
       digitalWrite(led_green, HIGH);
       digitalWrite(led_blue, LOW);  
       
       if (intensity < MAXINTENSITY) {
         intensity += 1;
         Serial.write("Letter u received.  Intensity going up\n");
       }
     }
     
     else if (value == 'd') {
       digitalWrite(led_green, LOW);
       digitalWrite(led_blue, HIGH);
       
       if (intensity > 0) {
         intensity -= 1;
         Serial.write ("Letter d received.  Intensity going down\n");
       }
     }
     
     else {
       digitalWrite(led_green, LOW);
       digitalWrite(led_blue, LOW);
     }
  }
  
  digitalWrite(led_red, HIGH);
  delay(intensity);
  digitalWrite(led_red, LOW);
  delay(MAXINTENSITY - intensity);
  
}   

