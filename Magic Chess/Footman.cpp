#include "Footman.h"
#include <sstream>
#include <iostream>
#include "MyEnums.h"

//Constructors and destructor
Footman::Footman() : Piece()
{
	sf::Texture footmanTexture;
	sf::Texture emptyTexture;

	if (Piece::getTeam() == "Black")
	{
		if (!footmanTexture.loadFromFile("../assets/Black Footman idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!footmanTexture.loadFromFile("../assets/White Footman idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	this->footmanTexture = footmanTexture;
	this->emptyTexture = emptyTexture;
	this->hasBeenMoved = false;
	this->defenceStanceActive = false;
	
}
Footman::Footman(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture footmanTexture;
	sf::Texture emptyTexture;

	if (Piece::getTeam() == "Black")
	{
		if (!footmanTexture.loadFromFile("../assets/Black Footman idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!footmanTexture.loadFromFile("../assets/White Footman idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	this->footmanTexture = footmanTexture;
	this->emptyTexture = emptyTexture;
	this->hasBeenMoved = false;
	this->defenceStanceActive = false;

}
Footman::~Footman()
{

}

//Get-functions
bool Footman::getHasBeenMoved() const
{
	return this->hasBeenMoved;
}
bool Footman::getDefenceStanceActive() const
{
	return this->defenceStanceActive;
}
int Footman::getPieceType() const
{
	return FOOTMAN;
}
sf::Texture Footman::getTexture() const
{
	return this->footmanTexture;
}
void Footman::setToDeadTexture()
{
	this->footmanTexture = this->emptyTexture;
}

//Set-functions
void Footman::setHasBeenMoved(bool hasBeenMoved)
{
	this->hasBeenMoved = hasBeenMoved;
}
void Footman::setDefenceStanceActive(bool defenceStanceActive)
{
	this->defenceStanceActive = defenceStanceActive;
}

//Checks if move is allowed
bool Footman::canMakeThatMove(float x, float newX, float y, float newY) const
{
	bool result = false;

	if (x == newX && y == newY - 200 && this->hasBeenMoved == false && this->getTeam() == "Black" || x == newX && y == newY - 100 && this->hasBeenMoved == false && this->getTeam() == "Black")
	{
		result = true;
	}

	if (x == newX && y == newY + 200 && this->hasBeenMoved == false && this->getTeam() == "White" || x == newX && y == newY + 100 && this->hasBeenMoved == false && this->getTeam() == "White")
	{
		result = true;
	}

	if (x == newX && y == newY - 100 && this->hasBeenMoved == true && this->getTeam() == "Black")
	{
		result = true;
	}

	if (x == newX && y == newY + 100 && this->hasBeenMoved == true && this->getTeam() == "White")
	{
		result = true;
	}

	if (y == newY - 100 && this->getTeam() == "Black" && x == newX - 100)
	{
		result = true;
	}
	
	if (y == newY - 100 && this->getTeam() == "Black" && x == newX + 100)
	{
		result = true;
	}

	if (y == newY + 100 && this->getTeam() == "White" && x == newX - 100)
	{
		result = true;
	}
	if (y == newY + 100 && this->getTeam() == "White" && x == newX + 100)
	{
		result = true;
	}

	return result;
}

//To string
string Footman::toStringSpecific() const
{
	stringstream converter;

	converter << "\nHas been moved: " << this->hasBeenMoved << "\nDefence stance is active: " << this->defenceStanceActive << endl;

	return converter.str();
}