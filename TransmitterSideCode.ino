#include <VirtualWire.h>

const int switchPin1 = 4;           // Digital input pin for the first switch
const int switchPin2 = 5;           // Digital input pin for the second switch
const int switchPin3 = 6;           // Digital input pin for the third switch

const int rfTransmitterPin = 10;    // Digital output pin for RF transmitter
const int ledPin1 = 2;              // Digital output pin for the first LED
const int ledPin2 = 3;              // Digital output pin for the second LED
const int ledPin3 = 7;              // Digital output pin for the third LED


void setup() {
  pinMode(switchPin1, INPUT_PULLUP); // Set first switch pin as input with internal pull-up resistor
  pinMode(switchPin2, INPUT_PULLUP); // Set second switch pin as input with internal pull-up resistor
  pinMode(switchPin3, INPUT_PULLUP); // Set second switch pin as input with internal pull-up resistor
  pinMode(rfTransmitterPin, OUTPUT);// Set RF transmitter pin as output
  pinMode(ledPin1, OUTPUT);          // Set first LED pin as output
  pinMode(ledPin2, OUTPUT);          // Set second LED pin as output
  pinMode(ledPin3, OUTPUT);          // Set second LED pin as output

  // Initialize the RF transmitter module
  vw_set_tx_pin(rfTransmitterPin);
  vw_setup(2000);  // Transmission speed (bits per second)
}

void loop() {
  // Check if the switch is activated
  if (digitalRead(switchPin1) == LOW) {
    // Switch is activated, send a message via RF transmitter
    const char *message = "Yellow 1 is on";
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();  // Wait for transmission to complete
    
    // Blink the first LED
    digitalWrite(ledPin1, HIGH); // Turn on first LED
    delay(100);    // Delay for 100 milliseconds
    digitalWrite(ledPin1, LOW); // Turn off first LED
    delay(100);    // Delay for 100 millisecond
  }

    // Check if the second switch is activated
  if (digitalRead(switchPin2) == LOW) {
    // Second switch is activated, send a message via RF transmitter
    const char *message = "Yellow 2 is on";
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();  // Wait for transmission to complete
    
    // Blink the second LED
    digitalWrite(ledPin2, HIGH); // Turn on second LED
    delay(100);    // Delay for 100 milliseconds
    digitalWrite(ledPin2, LOW); // Turn off second LED
    delay(100);    // Delay for 100 milliseconds
  }
    // Check if the second switch is activated
  if (digitalRead(switchPin3) == LOW) {
    // Second switch is activated, send a message via RF transmitter
    const char *message = "RED is on";
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();  // Wait for transmission to complete
    
    // Blink the second LED
    digitalWrite(ledPin3, HIGH); // Turn on second LED
    delay(100);    // Delay for 100 milliseconds
  }
  else{
    
    // Second switch is off, send a message via RF transmitter
    const char *message = "RED is off";
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();  // Wait for transmission to complete
     
    digitalWrite(ledPin3, LOW); // Turn on second LED
    delay(100);    // Delay for 100 milliseconds
    
  }
}
