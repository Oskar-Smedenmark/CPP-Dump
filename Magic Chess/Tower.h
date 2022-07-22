#ifndef TOWER_H
#define TOWER_H

#include "Piece.h"

class Tower : public Piece
{
public:
	Tower();
	Tower(int id, int health, float deathX, float deathY, float x, float y, string team);
	virtual ~Tower();

	int getPieceType() const;
	bool getIsChecking() const;
	sf::Texture getTexture() const;

	void setIsChecking(bool isChecking);
	void setToDeadTexture();

	bool canMakeThatMove(float x, float newX, float y, float newY) const;

	string toStringSpecific() const;

private:
	bool isChecking;

	sf::Texture towerTexture;
	sf::Texture emptyTexture;
};
#endif