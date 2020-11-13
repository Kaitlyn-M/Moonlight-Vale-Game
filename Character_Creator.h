//Speeds up compilation by only needing the file once.
#pragma once

//Iostream controls the input and output.
#include <iostream>
//Allows for file input and output.
#include <fstream>
//Includes the string object to be accessed through a variable.
#include <string>

//Creates "Character_Creator" class.
class Character_Creator
{
// Access specificer. Lists properties that can only be accessed by methods declared in public section of class.
private:
	//Creates a string for the character's name.
	std::string characterName;
	//String for the character's species property.
	std::string CharacterSpecies;
	//String for the character's species.
	std::string characterSpecies;
// Access specifier. Lists all members that can be directly accessed from anywhere the object can be accessed.
public:
	//Prototype for entering the user's character name.
	void enterCharacterName();
	//Prototype for entering the user's character age.
	int enterCharacterAge();
	//Prototype for entering the user's character species.
	void enterCharacterSpecies();
	//Prototype for entering the user's character catchphrase.
	void enterCharacterCatchphrase();
	//Prototype for getting a character's species.
	std::string getCharacterSpecies();
	//Prototype for using characterName to search for an existing character.
	void readNameFromFile(std::string characterName, std::string characterSpecies, std::string characterNameSearch);
	//Prototype for setting a character's species.
	void setCharacterSpecies(std::string characterSpecies);
	//Prototype for the menu.
	void menu(std::string userMenuChoice);
};

