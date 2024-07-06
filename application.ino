#include<Servo.h>

#define directionPin 2  //Direction pin
#define stepPin 3       //Pulse pin
#define directionPin2 4  //Direction pin
#define stepPin2 5       //Pulse pin
int temp = 7200;

int basePin = 10;
Servo baseServo;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  baseServo.attach(basePin);

}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming data
    Serial.println(command);

    switch (command) {
      case '1': // Forward
        Serial.println("Forward X");
        move_forward_X();
        break;

      case '2': // Backward
        move_backward_X();
        Serial.println("Backward X");
        break;

      case '3': // forward
        Serial.println("Forward Y");
        move_forward_Y();
        break;

      case '4': // backward
        Serial.println("Backward Y");
        move_backward_Y();
        break;


      case '7': // forward
        Serial.println("rforward");
        baseServo.write(50);

        break;

      case '8': // backward
        Serial.println("rbackward");
        baseServo.write(0);

        break;

    }
  }
}

void move_forward_X() {
  Serial.println("Forward");
  for (int i = 0; i < 1600; i++) {
    digitalWrite(directionPin, HIGH);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
}



void move_backward_X() {
  Serial.println("Backward");
  for (int i = 0; i < 1600; i++) {
    digitalWrite(directionPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
}


void move_forward_Y() {
  Serial.println("Forward");
  for (int i = 0; i < 1600; i++) {
    digitalWrite(directionPin2, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(100);
  }
}


void move_backward_Y() {
  Serial.println("Backward");
  for (int i = 0; i < 1600; i++) {
    digitalWrite(directionPin2, LOW);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(100);
  }
}