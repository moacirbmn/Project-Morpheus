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
UltraF_trig	|	D8
UltraF_echo	|	D9
UltraL_trig	|	D10
UltraL_echo	|	D11
UltraR_trig	| 	D12
UltraR_echo	| 	D13
LineL		|	A3
LineR		|	A4
LineC		|	A5


### H Bridge Matrix

Relay 		| 1 2 3 4
   ------------ | -------------
Stop 		| 0 0 0 0
MoveForward 	| 0 1 0 1
MoveBackwards   | 1 0 1 0
TurnLeft 	| 0 0 0 1
TurnRight       | 0 1 0 0
RotateLeft	| 1 0 0 1
RotateRight	| 0 1 1 0


