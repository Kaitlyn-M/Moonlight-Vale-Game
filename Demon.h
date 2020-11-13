//Speeds up compilation by only needing the file once.
#pragma once
//Includes "Character" header information.
#include "Character.h"
//Helps with random number generator utilizing rand(). 
#include <cstdlib>
//Helps with seeding random number generator with current time.
#include <ctime>

//Demon derived class from Character.
class Demon : public Character
{
// Access specifier. Lists methods that can be directly accessed from anywhere the object can be accessed.
public:
	//Constructor that initializes all public and private properties in the Demon class. 
	Demon()
	{}
	//Virtual attack prototype that is constant and overriden.
	int attack() override;
	//Prototype for the demon's fight experience.
	void characterFight(Demon demon, Character angelGuard, int demonDmg, int angelDmg, int* demonHealth, int* angelHealth);
	//Virtual prototype for displaying the opponent's new health and overriden.
	void displayOppHealth(int* angelHealth) override;
	//Prototype for the main game for the demon.
	void game(std::string fightOrFlight, bool gameLoopContinue, Character character, Demon demon, Character angelGuard, int demonDmg, int angelDmg, int* demonHealth, int* angelHealth);
	//Virtual prototype for calculating the opponent's new health and overriden.
	int newOppHealth(int* angelHealth, int demonDmg) override;
	//Virtual prototype for setting a character's health and overriden.
	int setHealth(int* demonHealth) override;
	//Virtual prototype for displaying the story and overriden.
	void story() override;
	//Prototype for talking with a clearly defined morality.
	void talk(std::string dialogue, std::string morality);
};

