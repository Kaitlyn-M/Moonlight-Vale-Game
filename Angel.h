//Speeds up compilation by only needing the file once.
#pragma once
//Includes "Character" header information.
#include "Character.h"
//Helps with random number generator utilizing rand(). 
#include <cstdlib>
//Helps with seeding random number generator with current time.
#include <ctime>


//Angel derived class from Character.
class Angel : public Character
{
// Access specifier. Lists methods that can be directly accessed from anywhere the object can be accessed.
public:
	//Constructor that initializes all public and private properties in the Angel class. 
	Angel()
	{}
	//Virtual attack prototype that is constant and overriden.
	int attack() override;
	//Prototype for the angel's fight experience.
	void characterFight(Angel angel, Character demonGuard, int angelDmg, int demonDmg, int* angelHealth, int* demonHealth);
	//Virtual prototype for displaying the opponent's new health and overriden.
	void displayOppHealth(int* demonHealth) override;
	//Prototype for the main game for the angel.
	void game(std::string fightOrFlight, bool gameLoopContinue, Character character, Angel angel, Character demonGuard, int angelDmg, int demonDmg, int* angelHealth, int* demonHealth);
	//Virtual prototype for calculating the opponent's new health and overriden.
	int newOppHealth(int* demonHealth, int angelDmg) override;
	//Virtual prototype for setting a character's health and overriden.
	int setHealth(int* angelHealth) override;
	//Virtual prototype for displaying the story and overriden.
	void story() override;
	//Prototype for talking with a clearly defined morality.
	void talk(std::string dialogue, std::string morality);
};

