#include "Tower.h"
#include "MyEnums.h"
#include <iostream>

Tower::Tower() : Piece()
{
	sf::Texture emptyTexture;
	sf::Texture towerTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!towerTexture.loadFromFile("../assets/Black Tower idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!towerTexture.loadFromFile("../assets/White Tower idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}
	
	this->isChecking = false;

	this->towerTexture = towerTexture;
	this->emptyTexture = emptyTexture;
}
Tower::Tower(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture emptyTexture;
	sf::Texture towerTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!towerTexture.loadFromFile("../assets/Black Tower idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!towerTexture.loadFromFile("../assets/White Tower idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->isChecking = false;

	this->towerTexture = towerTexture;
	this->emptyTexture = emptyTexture;
}
Tower::~Tower()
{

}

int Tower::getPieceType() const
{
	return TOWER;
}
bool Tower::getIsChecking() const
{
	return this->isChecking;
}
sf::Texture Tower::getTexture() const
{
	return this->towerTexture;
}

void Tower::setIsChecking(bool isChecking)
{
	this->isChecking = isChecking;
}
void Tower::setToDeadTexture()
{
	this->towerTexture = this->emptyTexture;
}

bool Tower::canMakeThatMove(float x, float newX, float y, float newY) const
{
	bool result = false;
	
	if (x == newX)
	{
		result = true;
	}
	if (y == newY)
	{
		result = true;
	}

	return result;
}

string Tower::toStringSpecific() const
{
	return "";
}