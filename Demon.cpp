//Includes "Demon" header information.
#include "Demon.h"
//Controls the input and output.
#include <iostream>

//Virtual attack method that is constant and overriden.
int Demon::attack()
{
	//Stores a random number from 1 to 20 in the result variable.
	int demonDmg = Character::randomRoll(20);
	//Returns the result value to main().
	return demonDmg;
}
//The demon's fight experience.
void Demon::characterFight(Demon demon, Character angelGuard, int demonDmg, int angelDmg, int* demonHealth, int* angelHealth)
{
	//Takes in addresses of characters' initial health values and sets their health.	
	demon.setHealth(demonHealth);
	angelGuard.setHealth(angelHealth);
	//Gets characters' health value.
	demon.getHealth();
	angelGuard.getHealth();
	//The demon's damage depends on the attack.
	demonDmg = demon.attack();
	//The guard's health is reduced based on the demon's damage.
	demon.newOppHealth(angelHealth, demonDmg);
	//The guard's updated health is displayed.
	demon.displayOppHealth(angelHealth);
	//The guard's damage depends on the attack.
	angelDmg = angelGuard.attack();
	//The demon's health is reduced based on the guard's damage.
	angelGuard.newOppHealth(demonHealth, angelDmg);
	//The demon's updated health is displayed.
	angelGuard.displayOppHealth(demonHealth);
}
//Displays the angel's updated health.
void Demon::displayOppHealth(int* angelHealth)
{
	std::cout << "The angel now has " << *angelHealth << " health." << std::endl;
}
//The main game for the angel.
void Demon::game(std::string fightOrFlight, bool gameLoopContinue, Character character, Demon demon, Character angelGuard, int demonDmg, int angelDmg, int* demonHealth, int* angelHealth)
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
		std::cout << "\nYou decide to fight the angel guard!\n";

		//Fighting game loop.
		//Executes at least once and repeats until the character wins or dies.
		do
		{
			//The character's scenario one fight experience.
			demon.characterFight(demon, angelGuard, demonDmg, angelDmg, demonHealth, angelHealth);

			//Executes if the angel loses.
			if (*demonHealth <= 0)
			{
				//The game loop will not continue.
				gameLoopContinue = false;
				//Indicates that the character died.
				std::cout << "\n\nGame over. Your character died.\n";
			} //End of the *angelHealth if statement.

			  //Executes if the demon looses.
			else if (*angelHealth <= 0)
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
		demon.characterFlight(character);

	} //End of flightOrFlight else statement.
}
//Takes in a pointer to the angel's health and the demon's damage. The angel's new health is calculated.
int Demon::newOppHealth(int* angelHealth, int demonDmg)
{
	//The new health is the original health minus the result random number.
	*angelHealth = *angelHealth - demonDmg;
	//Returns the new health.
	return *angelHealth;
}
//Setter method that takes in the pointer to the demon's health to determine the demon's new health
int Demon::setHealth(int* demonHealth)
{
	//If demonHealth is greater than 0, return demonHealth.
	if (demonHealth > 0)
	{
		return *demonHealth;
	}
}
//Displays the demon's story.
void Demon::story()
{
	std::cout << "\nI scratched cell wall and screamed my lungs out.";
	std::cout << "\nEventually, I angrily crossed my arms in defeat.";
	std::cout << "\nAfter closing my eyes, I came up with a plan.";
	std::cout << "\nWith my corrupt magic, I was able to tear the door open and darken the area.";
	std::cout << "\nNo matter the cost, I'm getting out of here!";
	std::cout << "\n...I see someone I want to fight but it might be best if I run...\n";
	std::cout << "\nChoose 'fight' or 'flight'\n";

}
//Talking and stating morality.
void Demon::talk(std::string dialogue, std::string morality)
{
	//Outputs the character's dialogue with a clearly defined morality.
	std::cout << dialogue << " I am " << morality << ".";
}
