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
int MSensor = 6;
int MReceiver = 7;

// functions
void forward()
{
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1400);
}

void backward()
{
    servoLeft.writeMicroseconds(1400);
    servoRight.writeMicroseconds(1600);
}

void leanRight()
{
    servoLeft.writeMicroseconds(1550);
    servoRight.writeMicroseconds(1500);
}

void leanLeft()
{
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1450);
}

void turnRight()
{
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1450);
}

void turnLeft()
{
    servoLeft.writeMicroseconds(1550);
    servoRight.writeMicroseconds(1400);
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
    pinMode(MSensor, OUTPUT);
    pinMode(MReceiver, INPUT);

    // servos
    servoLeft.attach(LServo);
    servoRight.attach(RServo);

}
 
void loop()
{
  // scan
  int left = digitalRead(LReceiver);
  int middle = digitalRead(MReceiver);
  int right = digitalRead(RReceiver);
  
  Serial.print("Left: ");
  Serial.println(left);
  Serial.print("\nRight: ");
  Serial.println(right);
  Serial.print("\nMiddle: ");
  Serial.println(middle);
  delay(1000);

  // run
  // straight
  if (left == 1 && middle == 0 && right == 1) {
      forward()
      delay(1000)
  }
  // lean left
  if (left == 1 && middle == 1 && right == 0) {
      leanRight()
      delay(1000)
  }
  // lean right
  if (left == 0 && middle == 1 && right == 1) {
      leanLeft()
      delay(1000)
  }
  // turn left
  if (left == 0 && middle == 0 && right == 1) {
      turnLeft()
      delay(1000)
  }
  // turn right
  if (left == 1 && middle == 0 && right == 0) {
      turnLeft()
      delay(1000)
  }
}
