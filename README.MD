# Factory SpaceWar

	Factory SpaceWar is a thrilling multiplayer game where you fly a spaceship and have to destroy all enemy spaceships

## Team Members
	- Aleix Gabarr�
	- �scar Hern�ndez

## How to play
	You need to start the application and Start a server if there is no existing server. 
	Once the server is created you can connect to the server selecting the adress and the port. 
	Then you can write your name an selec your spaceship.

	You can shoot and kill enemies. If you are killed you can join the battle again!

## Controls 
	- Keyboard
		- A: Rotate left
		- D: Rotate right
		- Down Arrow: Move forward
		- Left Arrow: Shoot
	- Controller
		- LStick: Rotate
		- A: Move forward
		- X: Shoot
## Features
	- Client/Server virtual connection ------------------------------- �scar Hern�ndez
	- Wolrd state replication
		- Server side -------------------------------------------- �scar Hern�ndez
		- Client side -------------------------------------------- Aleix Gabarr�
	- Packet loss redundancy ----------------------------------------- �scar Hern�ndez
	- Packet delivery notification ----------------------------------- Aleix Gabarr�
	- Latency handling
		- Client side prediction --------------------------------- Aleix Gabarr�
		- Entity interpolation	---------------------------------- Both
	- Kill enemies and death window ---------------------------------- Both

## Bugs
	- Loss of input data with hi latency simulation
 