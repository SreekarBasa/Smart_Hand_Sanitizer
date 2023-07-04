// C++ code
#include <Servo.h>

int distance = 0;

Servo servo_2;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_2.attach(2, 500, 2500);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  servo_2.write(0);
  while (1 == 1) {
    distance = 0.01723 * readUltrasonicDistance(11, 10);
    if (distance > 10) {
      digitalWrite(7, HIGH);
    }
    if (distance <= 10) {
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      servo_2.write(180);
      delay(2000); // Wait for 2000 millisecond(s)
      servo_2.write(0);
      delay(3000); // Wait for 3000 millisecond(s)
      digitalWrite(6, LOW);
    }
  }
}