#include <RCSwitch.h>

RCSwitch mySwitch1 = RCSwitch();
RCSwitch mySwitch2 = RCSwitch();

const int buttonPin1 = 5; 
const int buttonPin2 = 4;

void setup() {
  Serial.begin(9600);

  mySwitch1.enableTransmit(14);
  mySwitch2.enableTransmit(12);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  Serial.println("System Initialized");
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  Serial.print("Button 1 State: ");
  Serial.println(buttonState1);
  Serial.print("Button 2 State: ");
  Serial.println(buttonState2);

  if (buttonState1 == LOW) {
    Serial.println("Button 1 Pressed - Sending Signal 1234");
    mySwitch1.send("1234"); 
    delay(2000); 
  }

  if (buttonState2 == LOW) {
    Serial.println("Button 2 Pressed - Sending Signal 5678");
    mySwitch2.send("5678"); 
    delay(2000); 
  }
}
