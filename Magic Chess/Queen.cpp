#include "Queen.h"
#include "MyEnums.h"
#include <iostream>

Queen::Queen() : Piece()
{
	sf::Texture emptyTexture;
	sf::Texture queenTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!queenTexture.loadFromFile("../assets/Black Queen idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!queenTexture.loadFromFile("../assets/White Queen idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->isChecking = false;

	this->queenTexture = queenTexture;
	this->emptyTexture = emptyTexture;
}
Queen::Queen(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture emptyTexture;
	sf::Texture queenTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!queenTexture.loadFromFile("../assets/Black Queen idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!queenTexture.loadFromFile("../assets/White Queen idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->isChecking = false;

	this->queenTexture = queenTexture;
	this->emptyTexture = emptyTexture;
}
Queen::~Queen()
{

}

int Queen::getPieceType() const
{
	return QUEEN;
}
bool Queen::getIsChecking() const
{
	return this->isChecking;
}
sf::Texture Queen::getTexture() const
{
	return this->queenTexture;
}

void Queen::setIsChecking(bool isChecking)
{
	this->isChecking = isChecking;
}
void Queen::setToDeadTexture()
{
	this->queenTexture = this->emptyTexture;
}

bool Queen::canMakeThatMove(float x, float newX, float y, float newY) const
{
	bool result = false;

	//Right/up diagonal
	if (x < newX && newX + newY == x + y)
	{
		result = true;
	}
	//Left/up diagonal
	else if (x > newX && newY - newX == y - x)
	{
		result = true;
	}
	//Right/down diagonal
	if (x < newX && newX - newY == x - y)
	{
		result = true;
	}
	//Left/down diagonal
	else if (x > newX && newY + newX == y + x)
	{
		result = true;
	}

	//Up movement
	if (x == newX && y > newY)
	{
		result = true;
	}
	//Down movement
	else if (x == newX && y < newY)
	{
		result = true;
	}
	//Left movement
	if (y == newY && x > newX)
	{
		result = true;
	}
	//Right movement
	else if (y == newY && x < newX)
	{
		result = true;
	}
	
	return result;
}

string Queen::toStringSpecific() const
{
	return "";
}