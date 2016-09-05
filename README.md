# Sumobot

Arduino code for a sumo robot project.
Author: Carlos André de M. Teixeira
	carlosandrematte@gmail.com


### Arduino Pin Distribution

Component	| Pin
   ------------ | -------------
Relay1		|	D3
Relay2		|	D4
Relay3		|	D5
Relay4		|	D6
InfraF		|	D7
UltraF		|	D8
UltraL		|	D9
UltraR		| 	D10
LineL		|	A1
LineR		|	A2
LineC		|	A3


### H Bridge Matrix

Relay 		| 1 2 3 4
   ------------ | -------------
Stop 		| 0 0 0 0
MoveForward 	| 1 0 1 0
MoveBackwards   | 0 1 0 1
TurnLeft 	| 1 0 0 1
TurnRight       | 0 1 1 0
RotateLeft	| 1 0 0 0
RotateRight	| 0 0 0 1


