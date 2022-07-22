#ifndef STARTFUNCTIONS_H
#define STARTFUNCTIONS_H
#include "Character.h"
#include <iostream>
#include <fstream>
#include <vector>

void mainMenu()
{
	//Skriver ut menyn
	cout << "0. Exit" << endl;
	cout << "1. Resume game" << endl;
	cout << "2. Start new game" << endl;
	cout << "3. Credits" << endl;
	cout << "Write your choice: ";
}

Character createCharacter(Character* &characters, string name, int &nrOfElements, int &cap)
{
	Weapon theWeapon;
	//Skriver ut de olika valen
	int choice = 0;
	cout << "What kind of loadout would you like to go with?" << endl;
	cout << "1. Light(sub-machine gun, c4, fast speed, low weight, low armor)" << endl;
	cout << "2. Medium(Assault rifle, grenades, medium speed, medium weight, medium armor)" << endl;
	cout << "3. Heavy(Shotgun, rocket launcher, slow speed, high weight, high armor)" << endl;
	cout << "Your choice: ";
	cin >> choice;

	//De olika valen
	if (choice == 1)
	{
		theWeapon.setName("Sub-Machine gun");
		theWeapon.setDamage(10);
		theWeapon.setWeight(15);
		theWeapon.setRof(9);
		//Ordningen är, name, type, health, weight, exp, level, armor och explosives
		characters[nrOfElements] = Character(name, "Light", 100, 100, 50, 0, 1, 40, 1, theWeapon, 0);
	}
	else if (choice == 2)
	{
		theWeapon.setName("Assault rifle");
		theWeapon.setDamage(15);
		theWeapon.setWeight(25);
		theWeapon.setRof(5);
		characters[nrOfElements] = Character(name, "Medium", 150, 150, 100, 0, 1, 100, 3, theWeapon, 0);
	}
	else if (choice == 3)
	{
		theWeapon.setName("Shotgun");
		theWeapon.setDamage(40);
		theWeapon.setWeight(30);
		theWeapon.setRof(2);
		characters[nrOfElements] = Character(name, "Heavy", 200, 200, 150, 0, 1, 150, 2, theWeapon, 0);
	}
	nrOfElements++;

	return characters[nrOfElements - 1];
}

void expand(Character* &characters, int nrOfElements, int &cap)
{
	Character* temp = nullptr;
	//Expandera arrayen
	cap += 5;
	temp = new Character[cap];

	//Ge värdena i characters till temp
	for (int i = 0; i < nrOfElements; i++)
	{
		temp[i] = characters[i];
	}

	//Återlämna minne
	delete[]characters;

	//Characters perkar på samma ställe som temp
	characters = temp;

	//Temp pekar inte på något längre
	temp = nullptr;
}

void loadFile(Character* &characters, int &nrOfElements, int &cap)
{
	string characterName = "";
	int characterHealth = 0;
	int characterBaseHealth = 0;
	int characterWeight = 0;
	int characterExperience = 0;
	int characterLevel = 0;
	int characterArmor = 0;
	int characterExplosives = 0;
	string weaponName = "";
	int weaponDamage = 0;
	int weaponWeight = 0;
	int weaponRof = 0;
	int weaponDurability = 0;
	string characterType = "";
	int inventorySize = 0;
	int score = 0;

	Weapon theWeapon;
	

	//Ladda in de sparade karaktärerna till arrayen.
	ifstream charactersFile;
	charactersFile.open("../Saves/Characters.save");

	//ladda in kapaciteten och antalet karaktärer
	charactersFile >> cap;
	charactersFile >> nrOfElements;

	//Allokera minne till characters arrayen
	characters = new Character[cap];

	for (int i = 0; i < nrOfElements; i++)
	{
		charactersFile >> score;
		charactersFile.ignore();
		//Ladda in information till variabler
		getline(charactersFile, characterName);
		getline(charactersFile, characterType);
		charactersFile >> characterHealth;
		charactersFile >> characterBaseHealth;
		charactersFile >> characterWeight;
		charactersFile >> characterExperience;
		charactersFile >> characterLevel;
		charactersFile >> characterArmor;
		charactersFile >> characterExplosives;
		charactersFile.ignore();
		getline(charactersFile, weaponName);
		charactersFile >> weaponDamage;
		charactersFile >> weaponWeight;
		charactersFile >> weaponRof;
		charactersFile >> weaponDurability;

		theWeapon.setDamage(weaponDamage);
		theWeapon.setRof(weaponRof);
		theWeapon.setWeight(weaponWeight);
		theWeapon.setDurability(weaponDurability);
		theWeapon.setName(weaponName);
		//Sett in de variablerna i ett nytt karaktär objekt
		characters[i] = Character(characterName, characterType, characterHealth, characterBaseHealth, characterWeight, characterExperience, characterLevel, characterArmor, characterExplosives, theWeapon, score);
		//Add inventory
		charactersFile >> inventorySize;
		for (int n = 0; n < inventorySize; n++)
		{
			charactersFile.ignore();
			getline(charactersFile, weaponName);
			charactersFile >> weaponDamage;
			charactersFile >> weaponWeight;
			charactersFile >> weaponRof;
			charactersFile >> weaponDurability;

			characters[i].addWeapon(Weapon(weaponName, weaponDamage, weaponWeight, weaponRof, weaponDurability));
		}
	}
	charactersFile.close();
}

void saveFile(Character* &characters, int nrOfElements, int cap)
{
	ofstream charactersSave;
	charactersSave.open("../Saves/Characters.save");
	charactersSave << cap << endl;
	charactersSave << nrOfElements << endl;

	for (int i = 0; i < nrOfElements; i++)
	{
		charactersSave << characters[i].saveString();
	}
	charactersSave.close();
}
#endif