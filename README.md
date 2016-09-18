# Sumobot

Arduino code for a sumo robot project.
Author: Carlos André de M. Teixeira
	carlosandrematte@gmail.com


### Arduino Pin Distribution

Component	| Pin
   ------------ | -------------
Relay1 (R)	|	D2
Relay2 (R)	|	D3
Relay3 (L)	|	D4
Relay4 (L)	|	D5
InfraF		|	D7
UltraF_trig	| 	D12
UltraF_echo	| 	D13
LineL		|	A1
LineR		|	A2
LineC		|	A3


### H Bridge Matrix

Relay 		| 1 2 3 4
   ------------ | -------------
Stop 		| 0 0 0 0
MoveForward 	| 0 1 0 1
MoveBackwards   | 1 0 1 0
TurnLeft 	| 
TurnRight       | 
RotateLeft	| 
RotateRight	| 


