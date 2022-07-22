#ifndef BOWMAN_H
#define BOWMAN_H

#include "Piece.h"

class Bowman : public Piece
{
public:
	Bowman();
	Bowman(int id, int health, float deathX, float deathY, float x, float y, string team);
	virtual ~Bowman();

	int getPieceType() const;
	bool getIsChecking() const;
	sf::Texture getTexture() const;

	void setIsChecking(bool isChecking);
	void setToDeadTexture();

	bool canMakeThatMove(float x, float newX, float y, float newY) const;

	string toStringSpecific() const;

private:
	bool isChecking;

	sf::Texture bowmanTexture;
	sf::Texture emptyTexture;
};

#endif