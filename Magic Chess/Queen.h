#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen();
	Queen(int id, int health, float deathX, float deathY, float x, float y, string team);
	virtual ~Queen();

	int getPieceType() const;
	bool getIsChecking() const;
	sf::Texture getTexture() const;

	void setIsChecking(bool isChecking);
	void setToDeadTexture();

	bool canMakeThatMove(float x, float newX, float y, float newY) const;

	string toStringSpecific() const;

private:
	bool isChecking;

	sf::Texture queenTexture;
	sf::Texture emptyTexture;
};

#endif