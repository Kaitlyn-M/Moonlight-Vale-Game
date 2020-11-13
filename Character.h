//Speeds up compilation by only needing the file once.
#pragma once
//Includes the string object to be accessed through a variable.
#include <string>

//Creates "Character" class.
class Character
{
// Access specificer. Lists properties that can only be accessed by methods declared in public section of class.
private:
	//Initializes a character's health to 100.
	int Health = 100;
// Access specifier. Lists all members that can be directly accessed from anywhere the object can be accessed.
public:
	//Virtual prototype for attacking an opponent.
	virtual int attack();
	//Prototype for the character's fight experience.
	void characterFight(Character character1, Character enemyCharacter, int character1Dmg, int enemyCharacterDmg, int* character1Health, int* enemyCharacterHealth);
	//Prototype for the character's flight experience.
	void characterFlight(Character character);
	//Virtual prototype that displays the opponent's health.
	virtual void displayOppHealth(int* h);
	//Prototype for generating 1 or 2 as the flight success number.
	int flightRandomRoll();
	//Prototype for the main game for the character.
	void game(std::string fightOrFlight, bool gameLoopContinue, Character character, Character character1, Character enemyCharacter, int character1Dmg, int enemyCharacterDmg, int* character1Health, int* enemyCharacterHealth);
	//Getter prototype that gets a character's health.
	int getHealth();
	//Virtual prototype for calculating the opponent's new health.
	virtual int newOppHealth(int* h, int attackResult);
	//Prototype for generating a random number between 1 and an upper limit.
	int randomRoll(int upperLimit);
	//Virtual prototype for setting a character's health.
	virtual int setHealth(int* h);
	//Virtual prototype for displaying the story.
	virtual void story();
	//Prototype for talking.
	void talk(std::string dialogue);
	//Prototype for talking and stating morality.
	void talk(std::string dialogue, std::string morality);
};

