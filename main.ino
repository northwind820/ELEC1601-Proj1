#include <Servo.h>

// declare servos
Servo servoLeft;
Servo servoRight;
LServo = ;
RServo = ;

// declare pins
LSensor = ;
LReceiver = ;
RSensor = ;
RReceiver = ;

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

void stop()
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
    pinMode(LSensor, INPUT);
    pinMode(LReceiver, INPUT);
    pinMode(RSensor, INPUT);
    pinMode(RReceiver, INPUT);

    // servos
    servoLeft.attach(LServo);
    servoRight.attach(RServo);

}

void loop()
{

}