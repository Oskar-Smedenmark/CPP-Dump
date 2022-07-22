#include "Bowman.h"
#include "MyEnums.h"
#include <iostream>

Bowman::Bowman() : Piece()
{
	sf::Texture emptyTexture;
	sf::Texture bowmanTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!bowmanTexture.loadFromFile("../assets/Black Bowman idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!bowmanTexture.loadFromFile("../assets/White Bowman idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->isChecking = false;

	this->bowmanTexture = bowmanTexture;
	this->emptyTexture = emptyTexture;
}
Bowman::Bowman(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture emptyTexture;
	sf::Texture bowmanTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!bowmanTexture.loadFromFile("../assets/Black Bowman idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!bowmanTexture.loadFromFile("../assets/White Bowman idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->isChecking = false;

	this->bowmanTexture = bowmanTexture;
	this->emptyTexture = emptyTexture;
}
Bowman::~Bowman()
{

}

int Bowman::getPieceType() const
{
	return BOWMAN;
}
bool Bowman::getIsChecking() const
{
	return this->isChecking;
}
sf::Texture Bowman::getTexture() const
{
	return this->bowmanTexture;
}

void Bowman::setIsChecking(bool isChecking)
{
	this->isChecking = isChecking;
}
void Bowman::setToDeadTexture()
{
	this->bowmanTexture = this->emptyTexture;
}

bool Bowman::canMakeThatMove(float x, float newX, float y, float newY) const
{
	bool result = false;

	if (x < newX && newX + newY == x + y)
	{
		result = true;
	}
	else if (x > newX && newY - newX == y - x)
	{
		result = true;
	}

	if (x < newX && newX - newY == x - y)
	{
		result = true;
	}
	else if (x > newX && newY + newX == y + x)
	{
		result = true;
	}
	
	return result;
}

string Bowman::toStringSpecific() const
{
	return "";
}