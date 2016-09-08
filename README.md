# Sumobot

Arduino code for a sumo robot project.
Author: Carlos André de M. Teixeira
	carlosandrematte@gmail.com


### Arduino Pin Distribution

Component	| Pin
   ------------ | -------------
Relay1		|	D2
Relay2		|	D3
Relay3		|	D4
Relay4		|	D5
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
MoveForward 	| 0 1 0 1
MoveBackwards   | 1 0 1 0
TurnLeft 	| 0 0 0 1
TurnRight       | 1 0 0 0
RotateLeft	| 0 1 1 0
RotateRight	| 1 0 0 1


