//Includes "Angel" header information.
#include "Angel.h"
//Controls the input and output.
#include <iostream>

//Attack method that is constant and overriden.
int Angel::attack()
{
	//Stores a random number from 1 to 20 in the result variable.
	int angelDmg = Character::randomRoll(20);
	//Returns the result value to main().
	return angelDmg;
}
//The angel's fight experience.
void Angel::characterFight(Angel angel, Character demonGuard, int angelDmg, int demonDmg, int* angelHealth, int* demonHealth)
{
	//Takes in addresses of characters' initial health values and sets their health.	
	angel.setHealth(angelHealth);
	demonGuard.setHealth(demonHealth);
	//Gets characters' health value.
	angel.getHealth();
	demonGuard.getHealth();
	//The angel's damage depends on the attack.
	angelDmg = angel.attack();
	//The guard's health is reduced based on the angel's damage.
	angel.newOppHealth(demonHealth, angelDmg);
	//The guard's updated health is displayed.
	angel.displayOppHealth(demonHealth);
	//The guard's damage depends on the attack.
	demonDmg = demonGuard.attack();
	//The angel's health is reduced based on the guard's damage.
	demonGuard.newOppHealth(angelHealth, demonDmg);
	//The angel's updated health is displayed.
	demonGuard.displayOppHealth(angelHealth);
}
//Displays the demon's updated health.
void Angel::displayOppHealth(int* demonHealth)
{
	std::cout << "The demon now has " << *demonHealth << " health." << std::endl;
}
//The main game for the angel.
void Angel::game(std::string fightOrFlight, bool gameLoopContinue, Character character, Angel angel, Character demonGuard, int angelDmg, int demonDmg, int* angelHealth, int* demonHealth)
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
		std::cout << "\nYou decide to fight the demon guard!\n";

		//Fighting game loop.
		//Executes at least once and repeats until the character wins or dies.
		do
		{
			//The character's scenario one fight experience.
			angel.characterFight(angel, demonGuard, angelDmg, demonDmg, angelHealth, demonHealth);

			//Executes if the angel loses.
			if (*angelHealth <= 0)
			{
				//The game loop will not continue.
				gameLoopContinue = false;
				//Indicates that the character died.
				std::cout << "\n\nGame over. Your character died.\n";
			} //End of the *angelHealth if statement.

			  //Executes if the demon looses.
			else if (*demonHealth <= 0)
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
		angel.characterFlight(character);

	} //End of flightOrFlight else statement.
}
//Takes in a pointer to the demon's health and the angel's damage. The demon's new health is calculated.
int Angel::newOppHealth(int* demonHealth, int angelDmg)
{
	//The new health is the original health minus the result random number.
	*demonHealth = *demonHealth - angelDmg;
	//Returns the new health.
	return *demonHealth;
}
//Setter method that takes in the pointer to the ninja's health to determine the ninja's new health
int Angel::setHealth(int* angelHealth)
{
	//If angelHealth is greater than 0, return angelHealth.
	if (angelHealth > 0)
	{
		return *angelHealth;
	}
}
//Displays the angel's story.
void Angel::story()
{
	std::cout << "\nI banged on the walls of my cell.";
	std::cout << "\nEventually, I grew tried and decided to sit down.";
	std::cout << "\nAfter looking around for a while, I noticed a small crack in the wall.";
	std::cout << "\nWith my holy magic, I was able to blast the wall open.";
	std::cout << "\nI have to get out of here now!";
	std::cout << "\n...I see someone but I don't know if I should fight or run...\n";
	std::cout << "\nChoose 'fight' or 'flight'\n";
}
//Talking and stating morality.
void Angel::talk(std::string dialogue, std::string morality)
{
	//Outputs the character's dialogue with a clearly defined morality.
	std::cout << dialogue << " I am " << morality << ".";
}