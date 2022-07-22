#ifndef EMPTY_H
#define EMPTY_H

#include "Piece.h"

class Empty : public Piece
{
public:
	Empty();
	Empty(int id, int health, float deathX, float deathY, float x, float y, string team);

	int getPieceType() const;
	sf::Texture getTexture() const;
	void setToDeadTexture();

	string toStringSpecific() const;

private:
	sf::Texture emptyTexture;
};

#endif