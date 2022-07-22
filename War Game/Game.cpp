//Lägg till highscore och online server highscore uppdatering
//Funktioner
#include "StartFunctions.h"
//Klasser
#include "Character.h"
#include "Enemy.h"
//Standard libraries
#include <ctime>
#include <Windows.h>

//Main game loop
void gameLoop(Character &currentChar);

//Inventory managment
void openInventory(Character &currentChar);

//Stats display
void stats(Character &currentChar);

//Exploring
void explore(Character &currentChar);
//Event
void anEvent(Character &currentChar);
//Combat
void fight(Character &currentChar);
void attack(Enemy &attackedEnemy, Character &attackingChar);
void defend(Character &attackedChar, Enemy &attackingEnemy);
void showFightHelp(Character &currentChar);
void drop(Character &currentChar);

//Character
void displayAvailableChars(Character* &characters, int nrOfElements);
Character chooseCharacter(Character* &characters, int nrOfElements);

//Highscore
int calculateHighscore(Character* &characters, int nrOfElements, string &leader);
void highscoreSave(int highscore, string leader);
void startHighScoreSending();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(0));
	//Initiera variabler
	int choice = 0;
	int capacity = 5;
	int nrOfCharacters = 0;

	int highScore = 0;
	string leader = "";

	string characterName = "";
	Character currentChar;
	Character* characters = nullptr;
	Character* temp = nullptr;
	
	loadFile(characters, nrOfCharacters, capacity);

	//Skriv ut huvudmenyn
	mainMenu();
	cin >> choice;
	Beep(1000, 150);
	//Val i huvudmenyn
	system("cls");
	switch (choice)
	{
	case 0:
		return 0;
		break;
		//återhämta sparat spel
	case 1:
		currentChar = chooseCharacter(characters, nrOfCharacters);
		system("cls");
		break;

		//Skapa ny karaktär
	case 2:
		//Kolla om arrayen behöver expanderas
		if (nrOfCharacters == capacity)
		{
			expand(characters, nrOfCharacters, capacity);
		}
		//Skapa karaktären
		cout << "What is your characters name?: ";
		cin.ignore();
		getline(cin, characterName);
		Beep(1000, 150);
		currentChar = createCharacter(characters, characterName, nrOfCharacters, capacity);
		saveFile(characters, nrOfCharacters, capacity);
		system("cls");
		break;
	}

	if (choice != 0)
	{
		gameLoop(currentChar);

		for (int i = 0; i < nrOfCharacters; i++)
		{
			if (characters[i].getName() == currentChar.getName())
			{
				if (currentChar.getHealth() <= 0)
				{
					for (int n = i; n < nrOfCharacters; n++)
					{
						characters[n] = characters[n + 1];
					}
					nrOfCharacters--;
				}
				else
				{
					characters[i] = currentChar;
				}
			}
		}
		saveFile(characters, nrOfCharacters, capacity);
	}

	highScore = calculateHighscore(characters, nrOfCharacters, leader);

	highscoreSave(highScore, leader);

	startHighScoreSending();

	delete[]characters;
	return 0;
}

void gameLoop(Character &currentChar)
{
	int choice = 0;

	while (choice != 4 && currentChar.getHealth() >= 0)
	{
		cout << "1. Explore" << endl;
		cout << "2. Open inventory" << endl;
		cout << "3. Stats" << endl;
		cout << "4. Quit" << endl;
		cout << "Make a pick: ";
		cin >> choice;
		Beep(1000, 150);
		system("cls");
		switch (choice)
		{
		case 0:
			choice = -1;
			break;
		case 1:
			explore(currentChar);
			break;

		case 2:
			openInventory(currentChar);
			break;

		case 3:
			stats(currentChar);
			break;
		}
		if (choice == -1)
		{
			cout << "That's not a choice." << endl;
		}
	}

}

void openInventory(Character &currentChar)
{
	int choice = 0;
	Weapon temp;
	system("cls");
	cout << "Current Weapon: " << endl;
	cout << "--------------------------------------";
	cout << currentChar.getWeapon().toString();
	cout << "--------------------------------------" << endl << endl << endl;
	cout << "Inventory: " << endl;
	for (int i = 0; i < currentChar.getInventory().getWeapons().size(); i++)
	{
		cout << "--------------------------------------" << endl;
		cout << i << "." << endl << currentChar.getInventory().getWeapons().at(i).toString() << endl;
		cout << "--------------------------------------" << endl;
	}
	cout << "What do you want to do?" << endl;
	cout << "1. Choose a weapon to equip." << endl;
	cout << "2. Throw away a weapon." << endl;
	cout << "3. Return." << endl;
	cout << "Make a choice: ";
	
	
	cin >> choice;
	Beep(1000, 150);
	if (choice != 3)
	{
		switch (choice)
		{
		case 0:
			choice = -1;
			break;
		case 1:
			cout << "What weapon?: ";
			
			
			cin >> choice;
			Beep(1000, 150);
			if (choice >= 0)
			{
				currentChar.equipWeapon(choice);
			}
			break;
		case 2:
			cout << "What weapon do you want to throw away(-1 to abort)?: ";
			
			
			cin >> choice;
			Beep(1000, 150);

			if (choice != -1 && choice >= 0)
			{
				currentChar.removeWeaponAt(choice);
			}
			break;
		}
	}
	
	if(choice == -1)
	{
		cout << "That's not a choice." << endl;
		system("pause");
	}
	system("cls");
}

void stats(Character &currentChar)
{
	system("cls");
	cout << currentChar.getName() << "s score: " << currentChar.getScore() << endl;
	cout << currentChar.toString();
	system("pause");
	system("cls");
}

//Exploring
void explore(Character &currentChar)
{
	int enemyEncounter = rand() % 100;

	if (enemyEncounter < 80)
	{
		fight(currentChar);
	}
	else
	{
		anEvent(currentChar);
	}
}
//Combat
void fight(Character &currentChar)
{
	int lastLevel = currentChar.getLevel();
	int choice = 0;
	int health = rand() % (200 * currentChar.getLevel()) + 20;
	int armor = rand() % (15 * currentChar.getLevel()) + 5;
	int damage = rand() % (10 * currentChar.getLevel()) + 1;
	int rof = rand() % 10 + 1;
	bool killedEnemy = false;

	if (currentChar.getLevel() >= 8)
	{
		health = rand() % (400 * currentChar.getLevel()) + 200;
		armor = rand() % (30 * currentChar.getLevel()) + 35;
		damage = rand() % (30 * currentChar.getLevel()) + 10;
		rof = rand() % 20 + 1;
	}

	Enemy anEnemy("Dangerous enemy!", health, armor, Weapon("Bang bang stick", damage, 10, rof, 100));

	while (choice != 4 && killedEnemy == false)
	{
		cout << currentChar.toString();
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "The enemy!" << endl << endl;
		cout << anEnemy.toString();
		cout << endl;
		cout << "1. Attack!" << endl;
		cout << "2. Defend!" << endl;
		cout << "3. Help" << endl;
		cout << "4. Quit" << endl;
		cout << "What will you do?: ";
		
		cin >> choice;
		Beep(1000, 150);
		system("cls");
		if (choice > 4)
		{
			cout << "That's not a vaiable choice." << endl;
		}
		if (choice < 0)
		{
			cout << "That's not a vaiable choice." << endl;
		}

		switch (choice)
		{
		case 0:
			choice = -1;
			break;
		case 1:
			attack(anEnemy, currentChar);
			break;

		case 2:
			defend(currentChar, anEnemy);
			break;

		case 3:
			showFightHelp(currentChar);
			break;
		}

		if (anEnemy.getHealth() <= 0)
		{
			cout << "You killed the enemy!" << endl;
			killedEnemy = true;
			cout << "You gained " << health + damage + armor << " experience!" << endl;
			currentChar.gainExp(health + damage + armor);
			if (lastLevel < currentChar.getLevel())
			{
				cout << "You've gained a level!!!" << endl;
			}
			drop(currentChar);
			currentChar.setScore(currentChar.getScore() + 1);
		}

		if (currentChar.getHealth() <= 0)
		{
			choice = 4;
		}

		if(choice == -1)
		{
			cout << "That's not a choice." << endl;
		}

		if (currentChar.getWeapon().getDurability() <= 0)
		{
			currentChar.destroyWeapon();
			openInventory(currentChar);
		}
	}
}
void attack(Enemy &attackedEnemy, Character &attackingChar)
{
	int damage = 0;
	int enemyArmorChance = rand() % attackedEnemy.getArmor() * attackingChar.getLevel();
	int charAttackChance = rand() % (attackingChar.getWeapon().getDamage() * (int)attackingChar.getWeapon().getRof());

	cout << "Enemy armor chance: " << enemyArmorChance << endl << "Your weapon attack chance: " << charAttackChance << endl;

	if (enemyArmorChance > charAttackChance)
	{
		damage = attackedEnemy.getWeapon().getDamage();
		attackingChar.setHealth(attackingChar.getHealth() - damage);
		attackingChar.loseDurability(1);

		cout << attackedEnemy.getName() << " did " << damage << " damage to " << attackingChar.getName() << endl;
	}
	else
	{
		damage = attackingChar.getWeapon().getDamage();
		attackedEnemy.setHealth(attackedEnemy.getHealth() - damage);

		cout << attackingChar.getName() << " did " << damage << " damage to " << attackedEnemy.getName() << endl;
	}
}
void defend(Character &attackedChar, Enemy &attackingEnemy)
{
	int blockChance = rand() % attackedChar.getArmor();
	int blockBreak = rand () % attackingEnemy.getWeapon().getDamage() * 2;

	cout << "Enemy block break: " << blockBreak << endl << "Your block chance: " << blockChance << endl;
	if (blockChance > blockBreak)
	{
		if (attackedChar.getHealth() < attackedChar.getBaseHealth())
		{
			attackedChar.setHealth(attackedChar.getHealth() + ((15 * attackedChar.getLevel())));
			if (attackedChar.getHealth() > attackedChar.getBaseHealth())
			{
				attackedChar.setHealth(attackedChar.getBaseHealth());
			}
		}
		else
		{
			cout << "You're already at full health." << endl;
		}
	}
	else
	{
		attackedChar.setHealth(attackedChar.getHealth() - attackingEnemy.getWeapon().getDamage());
		attackedChar.loseDurability(1);
	}
}
void showFightHelp(Character &currentChar)
{
	system("cls");
	cout << "Attack: " << "When you attack you get an attack chance. This chance is between 0 and the damage multiplied with the rate of fire." << endl;
	cout << "The enemy gets an armor chance which is somewhere between 0 and its armor multiplied with your character level." << endl << "If you fail the attack you take damage and if you succeed you'll do damage to the enemy." << endl << endl;
	cout << "Defend: " << "When you defend you'll get hp back if you succeed and lose health if you fail." << endl;
	cout << "You get a block chance between 0 and your armor. The enemy get a block break chance between 0 and its damage * 2." << endl;
	cout << "The hp you get back at your current level is" << 200*currentChar.getLevel() << " - your armor." << endl << endl;
	system("pause");
	system("cls");
}
void drop(Character &currentChar)
{
	int dropChance = rand() % 100;
	int findChance = rand() % 100;

	if (dropChance + 30 <= findChance)
	{
		int randWepName = rand() % 3;
		string diffWeaps[3] = { "Assault rifle", "Shotgun", "Smg" };
		int damage = rand() % (15 * currentChar.getLevel()) + 1;
		int weight = rand() % 60 + 10;
		int rof = rand() % (2 * currentChar.getLevel()) + 1;
		int durability = rand() % 100 + 1;

		Weapon dropedWeapon(diffWeaps[randWepName], damage, weight, rof, durability);
		currentChar.addWeapon(dropedWeapon);
		cout << "Weapon droped!" << endl;
		cout << "--------------------------------------" << endl;
		cout << currentChar.getInventory().getWeapons().back().toString();
		cout << "--------------------------------------" << endl;
	}
	system("pause");
	system("cls");
}
//Event
void anEvent(Character &currentChar)
{
	int randomEvent = rand() % 2 + 1;
	int choice = 0;

	string diffWeaps[3] = { "Assault rifle", "Shotgun", "Smg" };
	int randWepName = rand() % 3;
	int damage = rand() % (15 * currentChar.getLevel()) + 1;
	int weight = rand() % 60 + 10;
	int rof = rand() % (2 * currentChar.getLevel()) + 1;
	int durability = rand() % 100 + 1;

	switch (randomEvent)
	{
	case 1:
		currentChar.addWeapon(Weapon(diffWeaps[randWepName], damage, weight, rof, durability));
		cout << "Weapon found!" << endl;
		cout << "--------------------------------------" << endl;
		cout << currentChar.getInventory().getWeapons().back().toString();
		cout << "--------------------------------------" << endl;
		currentChar.setScore(currentChar.getScore() + 1);
		break;

	case 2:
		system("cls");
		cout << "You find a cabin!" << endl << endl;
		cout << "1. Open the door" << endl;
		cout << "2. Go away" << endl;
		cout << "3. Knock on the door" << endl;
		cout << "What will you do?: ";
		cin >> choice;
		switch(choice)
		{ 
		case 1:
			currentChar.addWeapon(Weapon(diffWeaps[randWepName], damage, weight, rof, durability));
			cout << "Weapon found!" << endl;
			cout << "--------------------------------------" << endl;
			cout << currentChar.getInventory().getWeapons().back().toString();
			cout << "--------------------------------------" << endl;
			currentChar.setScore(currentChar.getScore() + 3);
			system("pause");
			system("cls");
			break;
			
		case 2:
			cout << "You walk away..." << endl;
			system("pause");
			break;

		case 3:
			cout << "You knock on the door..." << endl;
			system("pause");
			cout << "Someone opens..." << endl;
			system("pause");
			fight(currentChar);
			break;
		}
		break;
	}
}
void displayAvailableChars(Character* &characters, int nrOfElements)
{
	for (int i = 0; i < nrOfElements; i++)
	{
		cout << "---------------------------------" << endl;
		cout << "Name: " << characters[i].getName() << endl << "Type: " << characters[i].getType() << endl << "Level: " << characters[i].getLevel() << endl;
		cout << "---------------------------------" << endl << endl;
	}
}

Character chooseCharacter(Character* &characters, int nrOfElements)
{
	Character choosen;
	bool found = false;
	string characterName = "";
	while (found == false)
	{
		displayAvailableChars(characters, nrOfElements);
		cout << "Character name to load: ";
		
		cin.ignore();
		getline(cin, characterName);
		Beep(1000, 150);

		for (int i = 0; i < nrOfElements; i++)
		{
			if (characters[i].getName() == characterName)
			{
				choosen = characters[i];
				found = true;
			}
		}
		if (found == false)
		{
			cout << "That character dosen't exist..." << endl << endl;
		}
	}
	return choosen;
}

int calculateHighscore(Character* &characters, int nrOfElements, string &leader)
{
	int currentHighScore = 0;
	string currentLeader = "";

	ifstream highScoreFile;
	highScoreFile.open("../Data/highscore.data");

	getline(highScoreFile, currentLeader);
	highScoreFile >> currentHighScore;

	highScoreFile.close();

	for (int i = 0; i < nrOfElements; i++)
	{
		if (characters[i].getScore() >= currentHighScore)
		{
			currentHighScore = characters[i].getScore();
			leader = characters[i].getName();
		}
	}

	return currentHighScore;
}

void highscoreSave(int highscore, string leader)
{
	ofstream scoreFile;
	scoreFile.open("../Data/highscore.data");
	scoreFile << leader << endl << highscore;
	scoreFile.close();
}

void startHighScoreSending()
{
	
}