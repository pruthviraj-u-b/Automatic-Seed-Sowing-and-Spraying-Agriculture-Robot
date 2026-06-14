#include <Servo.h>
#include <SoftwareSerial.h>

// Motor A pins
#define ENA 8
#define IN1 2
#define IN2 3

// Motor B pins
#define ENB 9
#define IN3 4
#define IN4 5

// Relay control pin for additional DC motor
#define RELAY_PIN 7

// HC-05 Bluetooth on pins 10 (RX) and 11 (TX)
SoftwareSerial BTSerial(10, 11); // RX, TX

char command;
Servo servoW;      // Renamed from myServo
Servo servoX;      // Second servo motor

#define SERVO_W_PIN 6    // Main servo W pin
#define SERVO_X_PIN 12   // Servo X pin

bool servoWState = false;   // false = OFF, true = ON
bool servoXState = false;   // false = OFF, true = ON
bool relayState = false;    // false = OFF, true = ON

void setup() {
  // Initialize motor control pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize relay control pin
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensure relay is OFF at startup

  // Initialize servoW
  servoW.attach(SERVO_W_PIN);
  servoW.write(0);  // Start with servoW OFF

  // Initialize servoX
  servoX.attach(SERVO_X_PIN);
  servoX.write(45);  // Start with servoX OFF

  // Initialize serial communications
  BTSerial.begin(9600); // Bluetooth serial
  Serial.begin(9600);   // Debugging serial
}

void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();
    moveBot(command);
  }
}

void moveBot(char cmd) {
  switch (cmd) {
    case 'L': // Left
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
      analogWrite(ENA, 255); analogWrite(ENB, 255);
      break;

    case 'R': // Right
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
      analogWrite(ENA, 255); analogWrite(ENB, 255);
      break;

    case 'F': // Forward
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
      analogWrite(ENA, 255); analogWrite(ENB, 255);
      break;

    case 'B': // Backward
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
      analogWrite(ENA, 255); analogWrite(ENB, 255);
      break;

    case 'S': // Stop
      digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
      analogWrite(ENA, 0); analogWrite(ENB, 0);
      break;

    case 'W': // Turn Servo W ON (0 degrees)
      if (!servoWState) {
        servoW.write(0);
        servoWState = true;
        Serial.println("Servo W turned ON");
      }
      break;

    case 'w': // Turn Servo W OFF (45 degrees)
      if (servoWState) {
        servoW.write(45);
        servoWState = false;
        Serial.println("Servo W turned OFF");
      }
      break;

    case 'V': // Turn Relay ON
      if (!relayState) {
        digitalWrite(RELAY_PIN, HIGH);
        relayState = true;
        Serial.println("Relay turned ON");
      }
      break;

    case 'v': // Turn Relay OFF
      if (relayState) {
        digitalWrite(RELAY_PIN, LOW);
        relayState = false;
        Serial.println("Relay turned OFF");
      }
      break;

    case 'X': // Turn Servo X ON (45 degrees)
      if (!servoXState) {
        servoX.write(45);
        servoXState = true;
        Serial.println("Servo X turned ON");
      }
      break;

    case 'x': // Turn Servo X OFF (0 degrees)
      if (servoXState) {
        servoX.write(0);
        servoXState = false;
        Serial.println("Servo X turned OFF");
      }
      break;
  }
}    


