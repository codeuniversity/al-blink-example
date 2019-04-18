int motorPin1 = 2;
int motorPin2 = 3;
int wait = 10; //ms

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void motorControl(int pin1, int pin2)
{
  digitalWrite(motorPin1, pin1);
  digitalWrite(motorPin2, pin2);
}

void motorStop()
{
  motorControl(LOW, LOW);
}

void motorLeft()
{
  motorControl(LOW, HIGH);
}

void motorRight()
{
  motorControl(HIGH, LOW);
}

void loop()
{
  motorRight();
  delay(wait);

  motorLeft();
  delay(wait);

  motorStop();
  delay(wait);

  //changing speed
  for (int i = 0; i < 255; i++)
  {
    motorControl(LOW, i);
    delay(wait);
  }
  for (int i = 255; i > 0; i--)
  {
    motorControl(LOW, i);
    delay(wait);
  }
}