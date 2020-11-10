#include <Servo.h>

// declare servos
Servo servoLeft;
Servo servoRight;
int LServo = 13;
int RServo = 12;

// declare pins
int LSensor = 9;
int LReceiver = 10;
int RSensor = 2;
int RReceiver = 3;

// functions
void forward()
{
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
}

void backward()
{
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1700);
}

void turnRight()
{
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1700);
}

void turnLeft()
{
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
}

void stop_car()
{
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
}

// setup
void setup()
{
    // serial
    Serial.begin(9600);

    // sensors
    pinMode(LSensor, OUTPUT);
    pinMode(LReceiver, INPUT);
    pinMode(RSensor, OUTPUT);
    pinMode(RReceiver, INPUT);

    // servos
    servoLeft.attach(LServo);
    servoRight.attach(RServo);

}
 
void loop()
{
  int left = digitalRead(LReceiver);
  int right = digitalRead(RReceiver);
  Serial.print("Left:");
  Serial.println(left);
  Serial.print("Right:");
  Serial.println(right);
  delay(1000);
}
