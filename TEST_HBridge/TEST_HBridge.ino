// H-Bridge Test
// Moves: Stop, Forward, Backwards, Turn Right, Turn Left


#define Stop            1
#define MoveForward     2
#define MoveBackwards   3
#define TurnLeft        4
#define TurnRight       5
#define RotateLeft      6
#define RotateRight     7

// ---- Component  /  Pin ----

#define Relay1          2
#define Relay2          3
#define Relay3          4
#define Relay4          5

int Movement = 0;
int HBridge [4];


// --- Functions ---

void Move ()
{
  switch (Movement)
  {
    case Stop:          HBridge[0] = 0; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 0; break;
    case MoveForward:   HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 0; HBridge[3] = 1; break;
    case MoveBackwards: HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 1; HBridge[3] = 0; break;
    case TurnLeft:      HBridge[0] = 0; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 1; break;
    case TurnRight:     HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 0; break;
    case RotateLeft:    HBridge[0] = 0; HBridge[1] = 1; HBridge[2] = 1; HBridge[3] = 0; break;
    case RotateRight:   HBridge[0] = 1; HBridge[1] = 0; HBridge[2] = 0; HBridge[3] = 1; break;
  }

  digitalWrite(Relay1, HBridge[0]);
  digitalWrite(Relay2, HBridge[1]);
  digitalWrite(Relay3, HBridge[2]);
  digitalWrite(Relay4, HBridge[3]);
}


// --- Main Functions ---

void setup () 
{
  pinMode (Relay1, OUTPUT);
  pinMode (Relay2, OUTPUT);
  pinMode (Relay3, OUTPUT);
  pinMode (Relay4, OUTPUT);
}

void loop ()
{
  for (int i=2; i<8; i++)
  {
    Movement = i;
    Move();
    delay(1500);
    Movement = 1;
    Move();
    delay(1500);
  }
}
