#include <Ultrasonic.h>

#define InfraF          7
#define UltraF_E        12
#define UltraF_T        13

#define LineR           1
#define LineC           2
#define LineL           3

#define Relay1          2
#define Relay2          3
#define Relay3          4
#define Relay4          5

float SenseLimitL;
float SenseLimitR;
float SenseLimitC;
float SenseL;
float SenseR;
float SenseC;
float UltraF;

int LimitR;
int i = 0;

Ultrasonic ultrasonic(UltraF_T, UltraF_E);


//---- Multitasking Structure ---- //

typedef struct Timer
{
  unsigned long start;
  unsigned long timeout;
};

unsigned long Now ( void )
{
  return millis ( );
}

boolean TimerOut (struct Timer * timer)
{
  if ( Now () > timer->start + timer->timeout) {
    return true;
  }
  return false;
}

void timerStart(struct Timer * timer) {
  timer->start = Now();
}

void timerDesloc(struct Timer * timer, unsigned long Time) {
  timer->start = Now() + Time;
}

Timer TimerEdge = {0, 10};     // Checks edges every 10ms
Timer TimerFound = {0, 100};   // Looks for enemies every 100ms
Timer TimerSpin = {0, 800}; // MoveForward time
//Timer TimerSpin = {0, 3200};   // Spin time
Timer TimerEnd = {0, 85000};   // Round is over after 1min and 30seconds
boolean SpinDirection = true;  // Spin direction


// ---- Setup Functions ---- //

void setup() {

  pinMode (Relay1, OUTPUT);
  pinMode (Relay2, OUTPUT);
  pinMode (Relay3, OUTPUT);
  pinMode (Relay4, OUTPUT);

  Stop();
  SensorSetup();
  
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
  delay(750);
  TimerSpin.start = Now() - TimerSpin.timeout;
  //TimerSpin.start = Now();
  TimerFound.start = Now();
  MoveForward();
  delay(500);
}

void SensorSetup()
{
  SenseC = analogRead(LineC);
  SenseLimitC = (SenseC + SenseC / 1.5);
  SenseR = analogRead(LineR);
  SenseLimitR = (SenseR + SenseR / 1.5);
  SenseL = analogRead(LineL);
  SenseLimitL = (SenseL + SenseL / 1.5);
}


// ---- Loop Function ---- //

void loop()
{
  if (TimerOut(&TimerEnd)) 
  {
    while (1)
      Stop();
  }

  if (i = 0)
  {
    timerStart(&TimerEdge);
//    timerStart(&TimerSpin);
    timerStart(&TimerFound);
    i += 1;
  }

  if (TimerOut(& TimerSpin))
  {
    LeftSpin();
    timerStart(& TimerSpin);
    //timerStart(& TimerSpin);
  }


  if (TimerOut(& TimerEdge)) 
  {
    if ( (analogRead(LineR) > SenseLimitR) ) 
    { 
      LeftSpin();
      delay(750);
      MoveForward();
      delay(400);
      timerStart(& TimerSpin);
//    timerDesloc(& TimerSpin, -TimerSpin.timeout);
      timerStart(& TimerFound);
    } else if ((analogRead(LineL) > SenseLimitL)) 
    {
      RightSpin();
      delay(750);
      MoveForward();
      delay(400);
      timerStart(& TimerSpin);
//    timerDesloc(& TimerSpin, -TimerSpin.timeout);
      timerStart(& TimerFound);
    }
    timerStart(& TimerEdge);
  }
  if (TimerOut(& TimerFound))
  {
    if (Found())
    {
      MoveForward();
     // timerStart(& TimerSpin);
    }
    timerStart(& TimerFound);
  }
  /*if (TimerOut(& TimerSpin)) 
  {
    if (SpinDirection) 
    {
      RightSpin();
      SpinDirection = !SpinDirection;
    }
    else
    {
      LeftSpin();
      SpinDirection = !SpinDirection;
    }
    timerStart(& TimerSpin);
  }*/
}


// ---- Movement and Search Functions ---- //

void MoveForward() 
{
  digitalWrite(Relay1, LOW);
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, LOW);
  digitalWrite(Relay4, HIGH);
}
void MoveBackwards() 
{
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, LOW);
  digitalWrite(Relay3, HIGH);
  digitalWrite(Relay4, LOW);
}
void Stop()
{
  digitalWrite(Relay1, LOW);
  digitalWrite(Relay2, LOW);
  digitalWrite(Relay3, LOW);
  digitalWrite(Relay4, LOW);
}
void RightSpin() 
{
  digitalWrite(Relay1, LOW);
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, LOW);
  digitalWrite(Relay4, LOW);
}
void LeftSpin()
{
  digitalWrite(Relay1, LOW);
  digitalWrite(Relay2, LOW);
  digitalWrite(Relay3, LOW);
  digitalWrite(Relay4, HIGH);
}

float Distance() 
{
  float dist;
  long microsec = ultrasonic.timing();
  dist = ultrasonic.convert(microsec, Ultrasonic::CM);
  return dist;
}
boolean Found() 
{
  if (Distance() < 55)
    return true;
  else
    return false;
}
