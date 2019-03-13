/*
 * Blinks two LEDs when motion detected
 */

//variables
int led1 = 13;
int wait = 2000; //500ms = 1/2s

void setup()
{
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  digitalWrite(led1, HIGH);
  delay(wait);
  digitalWrite(led1, LOW);
  delay(wait);
}
