//Includes "Character" header information.
#include "Character.h"
//Helps with random number generator utilizing rand(). 
#include <cstdlib>
//Helps with seeding random number generator with current time.
#include <ctime>
//Controls the input and output.
#include <iostream>
//Allows the string object to be accessed through a variable.
#include <string>

//Allows the character to attack an opponent.
int Character::attack()
{
	//Stores a random number from 1 to 10 in the result variable.
	int attackResult = randomRoll(10);
	//Returns the result value to main().
	return attackResult;
}
//The character's fight experience.
void Character::characterFight(Character character1, Character enemyCharacter, int character1Dmg, int enemyCharacterDmg, int* character1Health, int* enemyCharacterHealth)
{
	//Takes in addresses of characters' initial health values and sets their health.	
	character1.setHealth(character1Health);
	enemyCharacter.setHealth(enemyCharacterHealth);
	//Gets characters' health value.
	character1.getHealth();
	enemyCharacter.getHealth();
	//Character one's damage depends on the attack.
	character1Dmg = character1.attack();
	//Enemy character's health is reduced based on character one's damage.
	character1.newOppHealth(enemyCharacterHealth, character1Dmg);
	//The enemy character's updated health is displayed.
	character1.displayOppHealth(enemyCharacterHealth);
	//Enemy character's damage depends on the attack.
	enemyCharacterDmg = enemyCharacter.attack();
	//Character one's health is reduced based on the enemy character's damage.
	enemyCharacter.newOppHealth(character1Health, enemyCharacterDmg);
	//Character one's updated health is displayed.
	enemyCharacter.displayOppHealth(character1Health);
}
//The character's scenario one flight experience.
void Character::characterFlight(Character character)
{
	//Indicates the flight.
	std::cout << "\nYour character runs away!";
	//Seeds random number generator based on current date and time.
	srand(static_cast<unsigned int>(time(0)));
	//flightSuccess value is based on flightRandomRoll().
	int flightSuccess = character.flightRandomRoll();

	//Executes if flightSuccess is one.
	if (flightSuccess == 1)
	{
		std::cout << "\n\nGame over. Your character died in flight.";
	} //Ends flightSuccess if statement.

	//Executes if flightSuccess is two.
	else
	{
		std::cout << "\n\nYou successfully got to the exit! Escape now...\n";
	} //Ends flightSuccess else statement.
}
//Displays an opponent's current health.
void Character::displayOppHealth(int* h)
{
	std::cout << "Your character now has " << *h << " health." << std::endl;
}
//Determines the character's flight success.
int Character::flightRandomRoll()
{
	//Sets 1 or 2 into the flightSuccess variable.
	int flightSuccess = (rand() % 2);
	//Returns randomNum to main().
	return flightSuccess;
}
//The main game for the character.
void Character::game(std::string fightOrFlight, bool gameLoopContinue, Character character, Character character1, Character enemyCharacter, int character1Dmg, int enemyCharacterDmg, int* character1Health, int* enemyCharacterHealth)
{
	//User can enter "fight or flight".
	getline(std::cin, fightOrFlight);
	//Executes until user chooses "fight" or "flight".
	while (fightOrFlight != "fight" && fightOrFlight != "flight")
	{
		std::cout << "\nYou must enter fight or flight: ";
		//User can enter "fight or flight".
		getline(std::cin, fightOrFlight);
	} //End of the fightOrFlight while statement.
	//Executes if user chooses "fight".
	if (fightOrFlight == "fight")
	{
		std::cout << "\nYou decide to fight the demon!";

		//Fighting game loop.
		//Executes at least once and repeats until the character wins or dies.
		do
		{
			//The character's scenario one fight experience.
			character1.characterFight(character1, enemyCharacter, character1Dmg, enemyCharacterDmg, character1Health, enemyCharacterHealth);

			//Executes if the angel loses.
			if (*character1Health <= 0)
			{
				//The game loop will not continue.
				gameLoopContinue = false;
				//Indicates that the character died.
				std::cout << "\n\nGame over. Your character died.\n";
			} //End of the *angelHealth if statement.

			  //Executes if the demon looses.
			else if (*enemyCharacterHealth <= 0)
			{
				//Game loop does not continue.
				gameLoopContinue = false;
				std::cout << "\n\nYou won and successfully got to the exit! Escape now...\n";
			}  //End of the *demonHealth if statement.

			//Executes if the fight continues.
			else
			{
				//Game loop continues.
				gameLoopContinue = true;
				//Indicates that the fight continues.
				std::cout << "\nThe battle rages on!";

			} //End of the gameLoopContinue else statement.

		}//End of the do loop.

		//Repeats as long as the game loop continues.
		while (gameLoopContinue == true);

	} //End of flightOrFlight if statement.

	//Executes if user chooses "flight".
	else
	{
		//The character's flight experience.
		character1.characterFlight(character);

	} //End of flightOrFlight else statement.
}
//Getter method that returns Health's updated value.
int Character::getHealth()
{
	return Health;
};
//Calculates the opponent's new health after being attacked.
int Character::newOppHealth(int* h, int attackResult)
{
	//The new health is the original health minus the result random number.
	*h = *h - attackResult;
	//Returns a character's new health
	return *h;
}
//Generates a random number from 1 to an upper limit and returns that number to main().
int Character::randomRoll(int upperLimit)
{
	//Sets a random number from 1 to an upper limit into the randomNum variable.
	int randomNum = (rand() % upperLimit + 1);
	//Displays a random number from 1 to an upper limit.
	std::cout << "\nThat hit did " << randomNum << " hit points of damage." << std::endl;
	//Returns randomNum to main().
	return randomNum;
}
//Setter method that takes in the "h" integer to determine the character's new health
int Character::setHealth(int* h)
{
	//If h(health) is greater than 0, return health.
	if (h > 0)
	{
		return *h;
	}
}
//Displays the story.
void Character::story()
{
	std::cout << "";
}
//Takes in string dialogue.
void Character::talk(std::string dialogue)
{
	//Outputs the character's dialogue.
	std::cout << dialogue;
};
//Talking and stating morality.
void Character::talk(std::string dialogue, std::string morality)
{
	//Outputs the character's dialogue with a clearly defined morality.
	std::cout << dialogue << " I am " << morality << ".";
}