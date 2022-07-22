#include "Knight.h"
#include "MyEnums.h"
#include <iostream>


//Constructors and destructor
Knight::Knight() : Piece()
{
	sf::Texture knightTexture;
	sf::Texture emptyTexture;

	if (Piece::getTeam() == "Black")
	{
		if (!knightTexture.loadFromFile("../assets/Black Knight idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!knightTexture.loadFromFile("../assets/White Knight idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	this->knightTexture = knightTexture;
	this->emptyTexture = emptyTexture;
}
Knight::Knight(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture knightTexture;
	sf::Texture emptyTexture;

	if (Piece::getTeam() == "Black")
	{
		if (!knightTexture.loadFromFile("../assets/Black Knight idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!knightTexture.loadFromFile("../assets/White Knight idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	this->knightTexture = knightTexture;
	this->emptyTexture = emptyTexture;
}
Knight::~Knight()
{

}

//Get-functions
int Knight::getPieceType() const
{
	return KNIGHT;
}
sf::Texture Knight::getTexture() const
{
	return this->knightTexture;
}
void Knight::setToDeadTexture()
{
	this->knightTexture = this->emptyTexture;
}

bool Knight::canMakeThatMove(float x, float newX, float y, float newY) const
{
	bool result = false;

	if (newY == y + 200)
	{
		if (newX == x - 100 || newX == x + 100)
		{
			result = true;
		}
	}
	if (newY == y - 200)
	{
		if (newX == x - 100 || newX == x + 100)
		{
			result = true;
		}
	}
	if (newX == x + 200)
	{
		if (newY == y - 100 || newY == y + 100)
		{
			result = true;
		}
	}
	if (newX == x - 200)
	{
		if (newY == y - 100 || newY == y + 100)
		{
			result = true;
		}
	}

	return result;
}

//To string
string Knight::toStringSpecific() const
{
	return "";
}