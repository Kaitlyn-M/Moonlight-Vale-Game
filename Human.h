//Speeds up compilation by only needing the file once.
#pragma once
//Includes "Character" header information.
#include "Character.h"
//Helps with random number generator utilizing rand(). 
#include <cstdlib>
//Helps with seeding random number generator with current time.
#include <ctime>

//Human derived class from Character.
class Human : public Character
{
// Access specifier. Lists methods that can be directly accessed from anywhere the object can be accessed.
public:
	//Constructor that initializes all public and private properties in the Human class. 
	Human()
	{}
	//Virtual attack prototype that is constant and overriden.
	int attack() override;
	//Prototype for the human's fight experience.
	void characterFight(Human human, Character demonGuard, int humanDmg, int demonDmg, int* humanHealth, int* demonHealth);
	//Virtual prototype for displaying the opponent's new health and overriden.
	void displayOppHealth(int* demonHealth) override;
	//Prototype for the main game for the human.
	void game(std::string fightOrFlight, bool gameLoopContinue, Character character, Human human, Character demonGuard, int humanDmg, int demonDmg, int* humanHealth, int* demonHealth);
	//Virtual prototype for calculating the opponent's new health and overriden.
	int newOppHealth(int* demonHealth, int humanDmg) override;
	//Virtual prototype for setting a character's health and overriden.
	int setHealth(int* humanHealth) override;
	//Virtual prototype for displaying the story and overriden.
	void story() override;
	//Function for talking.
	void talk(std::string dialogue);
};

