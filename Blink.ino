/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int led_blue = 13;
const int led_green = 11;
const int led_red = 9;
const int button_up = 7;
const int button_down = 6;

int intensity = 300;
int value_up;
int value_down;

const int MAXINTENSITY = 600;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(button_up, INPUT);
  pinMode(button_down, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  
  value_up = digitalRead(button_up);
  value_down = digitalRead(button_down);
  
  if (value_up == HIGH && value_down == HIGH) {
    digitalWrite(led_green, HIGH);
    digitalWrite(led_blue, HIGH);
    
  }
  
  else if (value_up == HIGH) {
    if (intensity < MAXINTENSITY)
      intensity += 10;
      
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, HIGH);
  }
  
  else if (value_down ==HIGH) {
    if (intensity > 0)
      intensity -= 10;
      
    digitalWrite(led_green, HIGH);
    digitalWrite(led_blue, LOW);
  }
  
  else {
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
  }
  
  delay (100);
  //digitalWrite(led_red, HIGH);
  //delay(intensity);
  //digitalWrite(led_red, LOW);
  //delay(MAXINTENSITY - intensity);
  
}
