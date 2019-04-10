int motorPin1=2;
int motorPin2=3;
int wait=10; //ms

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void stopMotor()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void loop()
{
  // right
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(wait);
  
  // left
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(wait);
  
  //stop
  stopMotor();
  delay(wait);
    
  //changing speed
  digitalWrite(motorPin1, LOW);
  for (int i=0; i<255; i++){
    analogWrite(motorPin2, i);
    delay(wait);
  }
  for (int i=0; i<255; i++){
    analogWrite(motorPin2, 255-i);
    delay(wait);
  }
}