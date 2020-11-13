//Includes "Character_Creator" header information.
#include "Character_Creator.h"

//User can enter the character's name then display it.
void Character_Creator::enterCharacterName()
{
	//Explains that the user can enter a character's name and what will occur if the user gives an invalid type.
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "Here is where you can enter your character's name!\n";
	std::cout << "You can enter any name you want.\n";
	std::cout << "If the name is too short, you will be given an error and the chance to enter a longer name.\n\n";
	//Displays that it is the name.
	std::cout << "Full Name: ";
	//Creates a string for the character's name.
	std::string characterName;

	//Make a file object to use as a file handle.
	std::ofstream myFile;
	//Reference to myFile
	std::ofstream& characterFile = myFile;
	//Executes at least once then continues until the while condition is false.
	do
	{
		//Allows the user to input the character's full name.
		std::getline(std::cin, characterName);
		//Tests the code block for exceptions.
		try
		{
			//Executes if the character's name is a string.
			if (characterName.size() >= 10)
			{
				//Open the file.
				characterFile.open("characters.txt", std::ios_base::app);
				//Write character name to the file.
				characterFile << characterName << std::endl;
				//Indicates that the name has been saved to the file.
				std::cout << "\nName saved to file!\n";
				//Close the file.
				characterFile.close();
			}
			//Throws the exception to the catch block.
			else
			{
				throw(characterName);
			}

		}
		//Catches the name exception.
		catch (std::string exName)
		{
			std::cout << "\nSorry, you need a valid name to move on! " << exName << " is an invalid name. Enter a longer name.\n";
			std::cout << "Full Name: ";
		}
	//Executes while the character name size is less than 10.
	} while (characterName.size() < 10);
}
//Enter the user's character age.
int Character_Creator::enterCharacterAge()
{
	//Explains that the user can enter a character's age and what will occur if the user gives an invalid type.
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "Here is where you can enter your character's age!\n";
	std::cout << "You can enter any age you want as long as it is greater than 0.\n";
	std::cout << "If it is an invalid type, you will be given an error and the chance to enter a valid type.\n\n";
	//Displays that it is the age.
	std::cout << "Age: ";
	//Creates an int for the character's age.
	std::string characterAge;

	//Make a file object to use as a file handle.
	std::ofstream myFile;
	//Reference to myFile
	std::ofstream& characterFile = myFile;
	//Executes at least once then continues until the while condition is false.
	do
	{
		//Allows the user to input the character's age.
		getline(std::cin, characterAge);
		//Tests the code block for exceptions.
		try
		{
			//Executes if the character's age is an int. The string is converted to an int.
			if (stoi(characterAge) > 0)
			{
				//Open the file.
				characterFile.open("characters.txt", std::ios_base::app);
				//Write character age to the file.
				characterFile << characterAge << std::endl;
				//Indicates that the age has been saved to the file.
				std::cout << "\Age saved to file!\n";
				//Close the file.
				characterFile.close();
			}
			//Throws the exception to the catch block.
			else
			{
				throw(stoi(characterAge));
			}
		}
		//Catches the age exception.
		catch (int exAge)
		{
			std::cout << "\nSorry, you need a valid age to move on! " << exAge << " is an invalid age. Enter an age that is greater than 0.\n";
			std::cout << "Age: ";
		}
	//Executes while the character's age is 0 or less.
	} while (stoi(characterAge) <= 0);

	//Returns the character's age to main().
	return stoi(characterAge);
}
//Enter the user's character species.
void Character_Creator::enterCharacterSpecies()
{
	//Explains that the user can enter a character's species and what will occur if the user gives an invalid species.
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "Here is where you can enter your character's species!\n";
	std::cout << "The following valid species are: human, demon and angel.\n";
	std::cout << "Type: 'Human', 'Demon' or 'Angel' for the species to be valid.\n";
	std::cout << "If it is an invalid species, you will be given an error and the chance to enter a valid species.\n\n";
	//Displays that it is the species.
	std::cout << "Species: ";
	//Creates a string for the character's species.
	std::string characterSpecies;

	//Make a file object to use as a file handle.
	std::ofstream myFile;
	//Reference to myFile
	std::ofstream& characterFile = myFile;
	//Executes at least once then continues until the while condition is false.
	do
	{
		//Allows the user to input the character's species.
		getline(std::cin, characterSpecies);
		//Sets a character's species.
		Character_Creator::setCharacterSpecies(characterSpecies);
		//Tests the code block for exceptions.
		try
		{
			//Executes if the character's species is a 'Human', 'Demon' or 'Angel'.
			if (characterSpecies == "Human" || characterSpecies == "Demon" || characterSpecies == "Angel")
			{
				//Open the file.
				characterFile.open("characters.txt", std::ios_base::app);
				//Write character species to the file.
				characterFile << characterSpecies << std::endl;
				//Indicates that the species has been saved to the file.
				std::cout << "\Species saved to file!\n";
				//Close the file.
				characterFile.close();
			}
			//Throws the exception to the catch block.
			else
			{
				throw(characterSpecies);
			}
		}
		//Catches the species exception.
		catch (std::string exSpecies)
		{
			std::cout << "\nSorry, " << exSpecies << " is not a valid species. Enter 'Human', 'Demon' or 'Angel' to proceed.\n";
			std::cout << "Species: ";
		}
		//Close the file.
		characterFile.close();
	//Executes while the character's species is not 'Human', 'Demon' or 'Angel'.
	} while (characterSpecies != "Human" && characterSpecies != "Demon" && characterSpecies != "Angel");
}
//Enter the user's character catchphrase.
void Character_Creator::enterCharacterCatchphrase()
{
	//Explains that the user can enter a character's catchphrase and what will occur if the user gives an invalid catchphrase.
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "Here is where you can enter your character's catchphrase!\n";
	std::cout << "You can enter any catchphrase you want as long as it is not long.\n";
	std::cout << "If the catchphrase is too long, you will be given an error and the chance to enter a shorter catchphrase.\n\n";
	//Displays that it is the species.
	std::cout << "Catchphrase: ";
	//Creates a string for the character's catchphrase.
	std::string characterCatchphrase;
	//Creates an int for the size of the character's catchphrase.
	int sizeOfCatchphrase = 0;

	//Make a file object to use as a file handle.
	std::ofstream myFile;
	//Reference to myFile
	std::ofstream& characterFile = myFile;
	//Executes at least once then continues until the while condition is false.
	do
	{
		//Allows the user to input the character's catchphrase.
		std::getline(std::cin, characterCatchphrase);
		//Tests the code block for exceptions.
		try
		{
			//The size of the catchphrase equals characterCatchphrase.size();
			sizeOfCatchphrase = characterCatchphrase.size();
			//Executes if the character's name is a string.
			if (sizeOfCatchphrase <= 15)
			{
				//Open the file.
				characterFile.open("characters.txt", std::ios_base::app);
				//Write character catchphrase to the file.
				characterFile << characterCatchphrase << std::endl;
				//Indicates that the catchphrase has been saved to the file.
				std::cout << "\Catchphrase saved to file!\n";
				//Close the file.
				characterFile.close();
			}
			//Throws the exception to the catch block.
			else
			{
				throw(characterCatchphrase);
			}

		}
		//Catches the name exception.
		catch (std::string & exCatchphrase)
		{

			std::cout << "\nSorry, you need a valid catchphrase to move on! " << exCatchphrase << " is an invalid catchphrase. Enter a shorter catchphrase.\n";
			std::cout << "Catchphrase: ";

		}
	//Executes while the size of the character's catchphrase is more than 15.
	} while (sizeOfCatchphrase > 15);
}
//Gets a character's chosen species.
std::string Character_Creator::getCharacterSpecies()
{
	//Returns the result value to main().
	return CharacterSpecies;
}
//Prototype for using characterName to search for an existing character.
void Character_Creator::readNameFromFile(std::string characterName, std::string characterSpecies, std::string characterNameSearch)
{
	//Make a file object to use as a file handle.
	std::ifstream myFile;
	
	//Open the file.
	myFile.open("characters.txt");
	//Prompts the user to enter a search term.
	std::cout << "\nPlease enter the full or partial character name you want me to find (case sensitive): ";
	//Allows the user to enter a search term.
	getline(std::cin, characterNameSearch);

	//Executes at least once then continues until the while condition is false.
	do
	{
		//Executes if the character name contains the search term.
		if ((characterName.find(characterNameSearch) != std::string::npos))
		{
			//Displays that the program found the character then displays the character's name.
			std::cout << "Found your character!: ";
			std::cout << characterName << "\n";
			//Sets and gets the character species.
			setCharacterSpecies(characterSpecies);
			getCharacterSpecies();
		}
		
	}
	//Gets characterName lines until the if condition is met.
	while (std::getline(myFile, characterName));

	//Close the file.
	myFile.close();
}
//Sets a character's species.
void Character_Creator::setCharacterSpecies(std::string characterSpecies)
{
	CharacterSpecies = characterSpecies;
}
//The menu structure.
void Character_Creator::menu(std::string userMenuChoice)
{
	//The user can either create a new character or play with an existing character.
	std::cout << "\nEnter 'new' to create a new character.";
	std::cout << "\nEnter 'existing' to play as an existing character.";
	//The program will repeat as long as userMenuChoice is not "new" or "existing".
	while (userMenuChoice != "new" && userMenuChoice != "existing")
	{
		//Instructs the user to enter "new" or "existing".
		std::cout << "\nPlease enter 'new' or 'existing' to continue.\n\n";
		//Gets the player's choice.
		std::getline(std::cin, userMenuChoice);
	}
	//Executes if the player enters "new".
	if (userMenuChoice == "new")
	{
		//User can enter the character's name then display it.
		Character_Creator::enterCharacterName();
		//User can enter the character's age then display it.
		Character_Creator::enterCharacterAge();
		//User can enter the character's species then display it.
		Character_Creator::enterCharacterSpecies();
		//User can enter the character's catchphrase then display it.
		Character_Creator::enterCharacterCatchphrase();
	}
	//Executes if the player enters "existing".
	else
	{
		//String for characterNameSearch.
		std::string characterNameSearch;
		//Uses characterName to search for an existing character.
		Character_Creator::readNameFromFile(characterName, characterSpecies, characterNameSearch);
	}
}