# Factory SpaceWar

	Factory SpaceWar is a thrilling multiplayer game where you fly a spaceship and have to destroy all enemy spaceships

## Team Members
	- Aleix Gabarró
	- Óscar Hernández

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
	- Client/Server virtual connection ------------------------------- Óscar Hernández
	- Wolrd state replication
		- Server side -------------------------------------------- Óscar Hernández
		- Client side -------------------------------------------- Aleix Gabarró
	- Packet loss redundancy ----------------------------------------- Óscar Hernández
	- Packet delivery notification ----------------------------------- Aleix Gabarró
	- Latency handling
		- Client side prediction --------------------------------- Aleix Gabarró
		- Entity interpolation	---------------------------------- Both
	- Kill enemies and death window ---------------------------------- Both

## Bugs
	- Loss of input data with hi latency simulation
 