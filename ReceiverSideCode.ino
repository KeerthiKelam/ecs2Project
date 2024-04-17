#include <VirtualWire.h>

const int ledPin1 = 2;  // Digital output pin for the first LED
const int ledPin2 = 3;  // Digital output pin for the second LED
const int ledPin3 = 4;  // Digital output pin for the second LED


const int rfReceiverPin = 11; // Digital input pin for RF receiver

void setup() {
  pinMode(ledPin1, OUTPUT); // Set first LED pin as output
  pinMode(ledPin2, OUTPUT); // Set second LED pin as output
  pinMode(ledPin3, OUTPUT); // Set second LED pin as output
  pinMode(rfReceiverPin, INPUT); // Set RF receiver pin as input
  
  // Initialize the RF receiver module
  vw_set_rx_pin(rfReceiverPin);
  vw_setup(2000); // Transmission speed (bits per second)
  vw_rx_start(); // Start the receiver
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Buffer to hold received message
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Length of the message buffer
  
  if (vw_get_message(buf, &buflen)) { // If a message is received
    // Convert the received message to a string
    buf[buflen] = '\0'; // Null-terminate the message
    String receivedMessage = String((char*)buf);
    
    // Check if the received message indicates Yellow Light 1 activation
    if (receivedMessage.equals("Yellow 1 is on")) {
      // Turn on Yellow Light 1
      digitalWrite(ledPin1, HIGH);
      delay(100); // Keep Yellow Light 1 on for 0.5 seconds
      digitalWrite(ledPin1, LOW); // Turn off Yellow Light 1
      delay(50);
    }
    // Check if the received message indicates Yellow Light 2 activation
    else if (receivedMessage.equals("Yellow 2 is on")) {
      // Turn on Yellow Light 2
      digitalWrite(ledPin2, HIGH);
      delay(100); // Keep Yellow Light 2 on for 0.5 seconds
      digitalWrite(ledPin2, LOW); // Turn off Yellow Light 2
      delay(50);
    }
    else if (receivedMessage.equals("RED is on")) {
      // Turn on Red Light 
      digitalWrite(ledPin3, HIGH);
      delay(50);
    }
    else if (receivedMessage.equals("RED is off")) {
      // Turn off Red Light 
      digitalWrite(ledPin3, LOW);
      delay(50);
    }
    
  }

}
