#include <Ultrasonic.h>

// ---- Movements ----

#define Stop            1
#define MoveForward     2
#define MoveBackwards   3
#define TurnLeft        4
#define TurnRight       5
#define RotateLeft      6
#define RotateRight     7

// ---- States ----

#define Search 1
#define Escape 2
#define Attack 3

// ---- Component  /  Pin ----

#define Relay1          2
#define Relay2          3
#define Relay3          4
#define Relay4          5

#define InfraF          7
#define UltraF_E        12
#define UltraF_T        13

#define LineR           A1
#define LineC           A2
#define LineL           A3

// ---- Variables ----

int Movement = 0;
int HBridge [4];
int Infra;

float SenseLimitL;
float SenseLimitR;
float SenseLimitC;
float SenseL;
float SenseR;
float SenseC;
float UltraF;


// --- Auxiliar Functions ---

void Move ()
{
  switch (Movement)
  {
    case Stop:          HBridge[0] = 0; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 0; break;
    case MoveForward:   HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 0; HBridge[3] = 1; break;
    case MoveBackwards: HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 1; HBridge[3] = 0; break;
    case TurnLeft:      HBridge[0] = 0; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 1; break;
    case TurnRight:     HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 0; HBridge[3] = 0; break;
    case RotateLeft:    HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 1; break;
    case RotateRight:   HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 1; HBridge[3] = 0; break;
  }

  digitalWrite(Relay1, HBridge[0]);
  digitalWrite(Relay2, HBridge[1]);
  digitalWrite(Relay3, HBridge[2]);
  digitalWrite(Relay4, HBridge[3]);
}

void SensorSetup()
{
  SenseC = analogRead(LineC);
  SenseLimitC = (SenseC-SenseC/2);
  SenseR = analogRead(LineR);
  SenseLimitR = (SenseR-SenseR/2);
  SenseL = analogRead(LineL);
  SenseLimitL = (SenseL-SenseL/2);

  Ultrasonic ultrasonic(UltraF_T, UltraF_E);
}

void Sense ()
{
  SenseR = analogRead(LineR);
  SenseL = analogRead(LineL);
  SenseC = analogRead(LineC);

  long microsec = ultrasonic.timing();
  UltraF = ultrasonic.convert(microsec, Ultrasonic::CM);

  InfraF = digitalRead(Infra);
}

void Think ();


// --- Main Functions ---

void setup () 
{
  pinMode (Relay1, OUTPUT);
  pinMode (Relay2, OUTPUT);
  pinMode (Relay3, OUTPUT);
  pinMode (Relay4, OUTPUT);

  pinMode (InfraF, INPUT);
  pinMode (UltraF, INPUT);
  pinMode (UltraL, INPUT);
  pinMode (UltraR, INPUT);

  SensorSetup();
  
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
  delay(750);
}

void loop ()
{
  Sense();
  Think();
  Move();
  delay(15);
}

