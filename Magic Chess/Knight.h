#ifndef KNIGHT_H
#define KNIGHT_H


#include "Piece.h"

class Knight : public Piece
{
public:
	Knight();
	Knight(int id, int health, float deathX, float deathY, float x, float y, string team);
	virtual ~Knight();

	int getPieceType() const;
	sf::Texture getTexture() const;
	void setToDeadTexture();

	bool canMakeThatMove(float x, float newX, float y, float newY) const;

	string toStringSpecific() const;
private:

	sf::Texture knightTexture;
	sf::Texture emptyTexture;
};
#endif