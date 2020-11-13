/*
	Kaitlyn Moeller
	10/5/2020
	A game where you try to escape the asylum (Moonlight Vale) as a patient.
*/

//Controls the input and output.
#include <iostream>
//Allows the string object to be accessed through a variable.
#include <string>
//Includes "Angel" header information.
#include "Angel.h"
//Includes "Character" header information.
#include "Character.h"
//Includes "Character_Creator" header information.
#include "Character_Creator.h"
//Includes "Demon" header information.
#include "Demon.h"
//Includes "Human" header information.
#include "Human.h"

//Prototype for displaying the introduction.
void displayIntro();

//Controls the program's logic flow.
int main()
{
	//Displays the introduction.
	displayIntro();
	//Variable for the user's choice in the menu.
	std::string userMenuChoice;
	//Creates "user" object.
	Character_Creator user;
	//"user" executes menu(userMenuChoice).
	user.menu(userMenuChoice);

	//Initializes damage of all species to zero.
	int angelDmg = 0;
	int demonDmg = 0;
	int humanDmg = 0;
	//Stores the initial values of all species health.
	int initialHealthAngel = 100;
	int initialHealthDemon = 100;
	int initialHealthHuman = 100;
	//Creates pointers to addresses of their respective health variables.
	int* angelHealth = &initialHealthAngel;
	int* demonHealth = &initialHealthDemon;
	int* humanHealth = &initialHealthHuman;

	//String for the in-game character species.
	std::string gameSpecies;
	//The character's in-game species is based on the character's species.
	gameSpecies = user.getCharacterSpecies();
	//Tells the user that the game can be played now.
	std::cout << "\nYou can now play!";
	//Creates "character" object.
	Character character;
	//gameLoopContinue is initialized to false.
	bool gameLoopContinue = false;
	//Allows user to choose "fight" or "flight".
	std::string fightOrFlight;
	//Indicates flight success.
	int flightSuccess = 0;

	//Executes if the character is an angel.
	if (gameSpecies == "Angel")
	{
		//Creates "angel" object.
		Angel angel;
		//The angel introduces themselves.
		angel.talk("\n\nI'm an angel with holy magic!", "good");
		//The angel's story.
		angel.story();
		//Creates "demonGuard" object.
		Character demonGuard;
		//Seeds random number generator based on current date and time.
		srand(static_cast<unsigned int>(time(0)));
		//The main game for the angel.
		angel.game(fightOrFlight, gameLoopContinue, character, angel, demonGuard, angelDmg, demonDmg, angelHealth, demonHealth);
	} //End of the angel's if statement.
	//Executes if the character is a demon.
	else if (gameSpecies == "Demon")
	{
		//Creates "demon" object.
		Demon demon;
		//The demon states an introduction.
		demon.talk("\n\nI'm a demon with corrupt magic!", "evil");
		//The demon's storyline.
		demon.story();
		//Creates "angelGuard" object.
		Character angelGuard;
		//Seeds random number generator based on current date and time.
		srand(static_cast<unsigned int>(time(0)));
		//The main game for the demon.
		demon.game(fightOrFlight, gameLoopContinue, character, demon, angelGuard, demonDmg, angelDmg, demonHealth, angelHealth);
	}
	//Executes if the character is a human.
	else
	{
		//Creates "human" object.
		Human human;
		//The human states an introduction.
		human.talk("\n\nI'm a resourceful human!");
		//The human's storyline.
		human.story();
		//Creates "demonGuard" object.
		Character demonGuard;
		//Seeds random number generator based on current date and time.
		srand(static_cast<unsigned int>(time(0)));
		//The main game for the human.
		human.game(fightOrFlight, gameLoopContinue, character, human, demonGuard, humanDmg, demonDmg, humanHealth, demonHealth);
	}

	//Returns 0 to the function.
	return 0;
}

//Displays the introduction.
void displayIntro()
{
	std::cout << "\n\t\t-~* Moonlight Vale: Fight or Flight! *~-\n\n";
	std::cout << "\tThis is a game all about escaping the asylum as a patient!\n";
	std::cout << "\tYou can create a new character or play as an existing character.\n";
	std::cout << "\tYour experience will be slightly different based on your character species.\n";
	std::cout << "\tIf you choose fight, your character and enemy will start with 100 health.\n";
	std::cout << "\tHowever, your character may die.\n";
	std::cout << "\tIf you choose flight, your character might be successful.\n";
	std::cout << "\tIt's up to you to decide which action will work for your character!\n";
	std::cout << "\tHave fun playing!\n";
}