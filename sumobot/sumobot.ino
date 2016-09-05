// ---- Movements ----

#define Stop            1
#define MoveForward     2
#define MoveBackwards   3
#define TurnLeft        4
#define TurnRight       5
#define RotateLeft      6
#define RotateRight     7

// ---- Component  /  Pin ----

#define Relay1          3
#define Relay2          4
#define Relay3          5
#define Relay4          6

#define InfraF          7
#define UltraF          8
#define UltraL          9
#define UltraR          10

#define LineL           A1
#define LineR           A2
#define LineC           A3

// ---- Variables ----

int Movement = 0;
int HBridge [4];

float SenseLimit;
float SenseL;
float SenseR;
float SenseC;


// --- Auxiliar Functions ---

void Move ()
{
  switch (Movement)
  {
    case Stop:          HBridge[0] = 0; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 0; break;
    case MoveForward:   HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 1; HBridge[3] = 0; break;
    case MoveBackwards: HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 0; HBridge[3] = 1; break;
    case TurnLeft:      HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 1; break;
    case TurnRight:     HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 1; HBridge[3] = 0; break;
    case RotateLeft:    HBridge[0] = 0; HBridge[1] = 0; HBridge[2] = 1; HBridge[3] = 0; break;
    case RotateRight:    HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 0; HBridge[3] = 0; break;
  }

  digitalWrite(Relay1, HBridge[0]);
  digitalWrite(Relay2, HBridge[1]);
  digitalWrite(Relay3, HBridge[2]);
  digitalWrite(Relay4, HBridge[3]);
}

void Sense ();

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

  SenseC = analogRead(LineC);
  SenseLimit = (SenseC+SenseC*2);
  
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
  delay(750);
}

void loop ()
{
  
}

