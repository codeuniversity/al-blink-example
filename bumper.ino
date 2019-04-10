const int bumper_sensor = A0;
int sensor_reading = 0;

void setup() {
  pinMode(bumper_sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensor_reading = analogRead(bumper_sensor);

  if(sensor_reading == 0){
    Serial.println("Under pressure!");
  } else {
    Serial.println("Another one bytes the dust");
  }
  delay(10);
  
}