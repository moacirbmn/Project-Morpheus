# Sumobot

Arduino code for a sumo robot project.
Author: Carlos André de M. Teixeira
	carlosandrematte@gmail.com


### Arduino Pin Distribution

Component	| Pin
   ------------ | -------------
Relay1		|	3
Relay2		|	4
Relay3		|	5
Relay4		|	6
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


