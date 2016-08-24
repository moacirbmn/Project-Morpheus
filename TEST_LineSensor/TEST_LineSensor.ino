// Line Sensors Test
// Calibrate sensors, waits 4.75 seconds and prints sensor values 

int LineL          = 1;
int LineR          = 2;
int LineC          = 3;

float SenseLimit;
float SenseL;
float SenseR;
float SenseC;

void setup()
{
  Serial.begin(9600);
  
  SenseLimit = (analogRead(LineC)*2);
  Serial.print("Sensor Value: ");
  Serial.println(LineC);
  
  delay(1000);
  Serial.print("\n 1");
  delay(1000);
  Serial.print("\n 2");
  delay(1000);
  Serial.print("\n 3");
  delay(1000);
  Serial.print("\n 4");
  delay(750);
  Serial.print("\n 4.75 \n\n Start Test \n\n");
}

void loop() 
{
  Serial.print("Left Sensor: ");
  SenseL = analogRead(LineL);
  Serial.println(SenseL);
  if (SenseL > SenseLimit)
  {
    Serial.print(", Branco!\n");
  } else {
    Serial.print(", Preto!\n");
  }

  Serial.print("Right Sensor: ");
  SenseR = analogRead(LineR);
  Serial.println(SenseR);
  if (SenseR > SenseLimit)
  {
    Serial.print(", Branco!\n");
  } else {
    Serial.print(", Preto!\n");
  }

  Serial.print("Center Sensor: ");
  SenseC = analogRead(LineC);
  Serial.println(SenseC);
  if (SenseC > SenseLimit)
  {
    Serial.print(", Branco!\n");
  } else {
    Serial.print(", Preto!\n");
  }

  delay(7000);
}
