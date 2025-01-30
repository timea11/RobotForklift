#include <Servo.h>
#define MOTOR_SPEED 180
#define SLOW 105

//Right motor
int enableRightMotor=6;
int rightMotorPin1=8;
int rightMotorPin2=7;
//Left motor
int enableLeftMotor=5;
int leftMotorPin1=10;
int leftMotorPin2=9;

int repeat = 0;
int myState = 0;

Servo servo;
int pos;

void setup()
{
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(4, INPUT);
  
  rotateMotor(0,0);
  servo.attach(3); 
  toLower(20, 160);

}

void loop()
{
  mainFun();

}

void mainFun()
{

  int rightIRSensorValue = digitalRead(11);
  int leftIRSensorValue = digitalRead(12);
  int frontIRSensorValue = digitalRead(4);

  if(frontIRSensorValue == LOW)
  {
    forkLift();
  }

  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW  && frontIRSensorValue == HIGH)
  {
    forword();
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW  && frontIRSensorValue == HIGH)
  {
    turnRight();
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH && frontIRSensorValue == HIGH)
  {
    turnLeft();
  }
  else if(rightIRSensorValue == HIGH && leftIRSensorValue == HIGH )
  {
    stop();

  }
}

void toLift(int DOWN, int UP)
{ 
  for(pos = DOWN; pos>=UP; pos-=1)
      {
        servo.write(pos);
        delay(40);
      }
}

void toLower(int UP, int DOWN)
{
  for(pos = UP; pos<=DOWN; pos+=1)
      {
        servo.write(pos);
        delay(40);
      }
}

  void forword()
  {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }
  void backword()
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  }
  void turnRight()
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }
  void turnLeft()
  {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  }
  void stop()
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

void forkLift()
{
  stop();
  delay(1000);
  forword();
  delay(500);
  stop();
  delay(500);
  toLift();
  delay(1000);
  backword();
  delay(500);
  turnLeft();
  delay(500);
  forword();
  delay(1000);
  stop();
  delay(500);
  toLower();
  delay(1000);
  backword();
  delay(1000);

}

