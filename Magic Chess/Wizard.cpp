#include "Wizard.h"
#include "MyEnums.h"
#include <iostream>

Wizard::Wizard() : Piece()
{
	sf::Texture emptyTexture;
	sf::Texture wizardTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!wizardTexture.loadFromFile("../assets/Black Wizard idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!wizardTexture.loadFromFile("../assets/White Wizard idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->wizardTexture = wizardTexture;
	this->emptyTexture = emptyTexture;
	this->checked = false;
}
Wizard::Wizard(int id, int health, float deathX, float deathY, float x, float y, string team) : Piece(id, health, deathX, deathY, x, y, team)
{
	sf::Texture emptyTexture;
	sf::Texture wizardTexture;

	if (!emptyTexture.loadFromFile("../assets/Empty.png"))
	{
		cout << "Error loading sprite";
	}

	if (Piece::getTeam() == "Black")
	{
		if (!wizardTexture.loadFromFile("../assets/Black Wizard idle sprite.png"))
		{
			cout << "Error loading black sprite";
		}
	}
	else
	{
		if (!wizardTexture.loadFromFile("../assets/White Wizard idle sprite.png"))
		{
			cout << "Error loading white sprite";
		}
	}

	this->wizardTexture = wizardTexture;
	this->emptyTexture = emptyTexture;
}
Wizard::~Wizard()
{

}

int Wizard::getPieceType() const
{
	return WIZARD;
}
sf::Texture Wizard::getTexture() const
{
	return this->wizardTexture;
}
void Wizard::setToDeadTexture()
{
	this->wizardTexture = this->emptyTexture;
}

bool Wizard::canMakeThatMove(float x, float newX, float y, float newY) const
{
	bool result = false;

	//Right/up diagonal
	if (x < newX && x + 100 - y + 100 == newX - newY)
	{
		result = true;
	}
	//Left/up diagonal
	else if (x > newX && y + 100 - x - 100 == newY - newX)
	{
		result = true;
	}
	//Right/down diagonal
	if (x < newX && x + 100 - y - 100 == newX - newY)
	{
		result = true;
	}
	//Left/down diagonal
	else if (x > newX && y + 100 + x - 100 == newY + newX)
	{
		result = true;
	}

	//Up movement
	if (x == newX && y == newY + 100)
	{
		result = true;
	}
	//Down movement
	else if (x == newX && y == newY - 100)
	{
		result = true;
	}
	//Left movement
	if (y == newY && x == newX + 100)
	{
		result = true;
	}
	//Right movement
	else if (y == newY && x == newX - 100)
	{
		result = true;
	}

	return result;
}

void Wizard::isChecked(bool checked)
{
	this->checked = checked;
}

string Wizard::toStringSpecific() const
{
	return "";
}