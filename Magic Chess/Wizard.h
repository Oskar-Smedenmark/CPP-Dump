#ifndef WIZARD_H
#define WIZARD_H

#include "Piece.h"

class Wizard : public Piece
{
public:
	Wizard();
	Wizard(int id, int health, float deathX, float deathY, float x, float y, string team);
	virtual ~Wizard();

	int getPieceType() const;
	sf::Texture getTexture() const;
	void setToDeadTexture();

	bool canMakeThatMove(float x, float newX, float y, float newY) const;

	void isChecked(bool checked);

	string toStringSpecific() const;

private:
	bool checked;

	sf::Texture wizardTexture;
	sf::Texture emptyTexture;
};

#endif