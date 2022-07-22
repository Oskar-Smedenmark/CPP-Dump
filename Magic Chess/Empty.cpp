#include "Empty.h"
#include "MyEnums.h"
#include <iostream>

Empty::Empty() : Piece()
{
	sf::Texture emptyTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	this->emptyTexture = emptyTexture;
}
Empty::Empty(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture emptyTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	this->emptyTexture = emptyTexture;
}

//get-functions
int Empty::getPieceType() const
{
	return EMPTY;
}
sf::Texture Empty::getTexture() const
{
	return this->emptyTexture;
}
void Empty::setToDeadTexture()
{

}

string Empty::toStringSpecific() const
{
	return "";
}