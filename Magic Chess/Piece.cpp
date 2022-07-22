#include "Piece.h"
#include <sstream>
#include <iostream>
#include "MyEnums.h"

//Constructor and destructor
Piece::Piece()
{
	this->id = 1;
	this->health = 1;
	this->deathX = 0;
	this->deathY = 0;
	this->x = 0;
	this->y = 0;
	this->team = "unknown";
}
Piece::Piece(int id, int health, float deathX, float deathY, float x, float y, string team)
{
	this->id = id;
	this->health = health;
	this->deathX = deathX;
	this->deathY = deathY;
	this->x = x;
	this->y = y;
	this->team = team;
}
Piece::Piece(const Piece &origObj)
{
	this->id = origObj.id;
	this->health = origObj.health;
	this->deathX = origObj.deathX;
	this->deathY = origObj.deathY;
	this->x = origObj.x;
	this->y = origObj.y;
	this->team = origObj.team;
}
Piece::~Piece()
{

}

//Get-functions
int Piece::getId() const
{
	return this->id;
}
int Piece::getHealth() const
{
	return this->health;
}
float Piece::getDeathX() const
{
	return this->deathX;
}
float Piece::getDeathY() const
{
	return this->deathY;
}
float Piece::getX() const
{
	return this->x;
}
float Piece::getY() const
{
	return this->y;
}
string Piece::getTeam() const
{
	return this->team;
}
int Piece::getPieceType() const
{
	return 0;
}
sf::Texture Piece::getTexture() const
{
	sf::Texture texture;

	return texture;
}

//Set-functions
void Piece::setId(int id)
{
	this->id = id;
}
void Piece::setHealth(int health)
{
	this->health = health;
}
void Piece::setDeathX(float deathX)
{
	this->deathX = deathX;
}
void Piece::setDeathY(float deathY)
{
	this->deathY = deathY;
}
void Piece::setX(float x)
{
	this->x = x;
}
void Piece::setY(float y)
{
	this->y = y;
}
void Piece::setTeam(string team)
{
	this->team = team;
}

//To string
string Piece::toString() const
{
	stringstream converter;

	converter << "ID: " << this->id << "\nHealth: " << this->health << "\nDeathX: " << this->deathX << "\nDeathY: " << this->deathY << "\nTeam: " << this->team << endl << this->toStringSpecific() << endl;

	return converter.str();
}

//Operators
void Piece::operator=(const Piece &origObj)
{
	if (this != &origObj)
	{
		this->id = origObj.id;
		this->health = origObj.health;
		this->deathX = origObj.deathX;
		this->deathY = origObj.deathY;
		this->x = origObj.x;
		this->y = origObj.y;
		this->team = origObj.team;
	}
}