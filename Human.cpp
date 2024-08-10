//Includes "Human" header information.
#include "Human.h"
//Controls the input and output.
#include <iostream>

//Virtual attack method that is constant and overriden.
int Human::attack()
{
	//Stores a random number from 1 to 15 in the result variable.
	int humanDmg = Character::randomRoll(15);
	//Returns the result value to main().
	return humanDmg;
};
//The human's fight experience.
void Human::characterFight(Human human, Character demonGuard, int humanDmg, int demonDmg, int* humanHealth, int* demonHealth)
{
	//Takes in addresses of characters' initial health values and sets their health.	
	human.setHealth(humanHealth);
	demonGuard.setHealth(demonHealth);
	//Gets characters' health value.
	human.getHealth();
	demonGuard.getHealth();
	//The human's damage depends on the attack.
	humanDmg = human.attack();
	//The guard's health is reduced based on the human's damage.
	human.newOppHealth(demonHealth, humanDmg);
	//The guard's updated health is displayed.
	human.displayOppHealth(demonHealth);
	//The guard's damage depends on the attack.
	demonDmg = demonGuard.attack();
	//The human's health is reduced based on the guard's damage.
	demonGuard.newOppHealth(humanHealth, demonDmg);
	//The human's updated health is displayed.
	demonGuard.displayOppHealth(humanHealth);
}
//Displays the demon's updated health.
void Human::displayOppHealth(int* demonHealth)
{
	std::cout << "The demon now has " << *demonHealth << " health." << std::endl;
}
//The main game for the human.
void Human::game(std::string fightOrFlight, bool gameLoopContinue, Character character, Human human, Character demonGuard, int humanDmg, int demonDmg, int* humanHealth, int* demonHealth)
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
			human.characterFight(human, demonGuard, humanDmg, demonDmg, humanHealth, demonHealth);

			//Executes if the angel loses.
			if (*humanHealth <= 0)
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
		human.characterFlight(character);

	} //End of flightOrFlight else statement.
}
//Takes in a pointer to the demon's health and the human's damage. The demon's new health is calculated.
int Human::newOppHealth(int* demonHealth, int humanDmg)
{
	//The new health is the original health minus the result random number.
	*demonHealth = *demonHealth - humanDmg;
	//Returns the new health.
	return *demonHealth;
};
//Setter method that takes in the pointer to the human's health to determine the human's new health
int Human::setHealth(int* humanHealth)
{
	//If humanHealth is not null, return humanHealth.
	if (humanHealth != nullptr)
	{
		return *humanHealth;
	}
}
//Displays the human's story.
void Human::story()
{
	std::cout << "\nI looked around my cell.";
	std::cout << "\nEventually, I got bored and decided to sit on the ground.";
	std::cout << "\nBeside me, I saw a small keycard.";
	std::cout << "\nOnce everyone got lunch, I slid the keycard through the lock to open the door.";
	std::cout << "\nWhen the door opened, I ran without a care in the world.";
	std::cout << "\n...I see someone but would it be better if I fought or ran?\n";
	std::cout << "\nChoose 'fight' or 'flight'\n";
}
//Takes in string dialogue.
void Human::talk(std::string dialogue)
{
	//Outputs the character's dialogue.
	std::cout << dialogue;
};