#define MoveForward     1
#define MoveBackwards   2
#define TurnLeft        3
#define TurnRight       4

int movement;
int HBridge [4];


void setup () 
{
  
}

void loop ()
{
  
}

// --- Function List ---

void Move ();


// --- Functions ---

void Move ()
{
  switch (movement)
  {
    case MoveForward:   HBridge = [1,0,1,0];
    case MoveBackwards: HBridge = [0,1,0,1];
    case TurnLeft:      HBridge = [1,0,1,0];
    case TurnRight:     HBridge = [0,1,1,0];
  }
}

