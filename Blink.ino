/*
 * Blinks two LEDs when motion detected
 */

//variables
int led1 = 7;
int wait = 500; //500ms = 1/2s

void setup()
{
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 10; i++)
  {
    Serial.println("Hello World!");
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    delay(200);
  }
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  }
}
