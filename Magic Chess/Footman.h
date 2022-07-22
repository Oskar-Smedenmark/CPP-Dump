#ifndef FOOTMAN_H
#define FOOTMAN_H

#include "Piece.h"

class Footman : public Piece
{
public:
	Footman();
	Footman(int id, int health, float deathX, float deathY, float x, float y, string team);
	virtual ~Footman();

	bool getHasBeenMoved() const;
	bool getDefenceStanceActive() const;
	int getPieceType() const;
	sf::Texture getTexture() const;
	void setToDeadTexture();

	void setHasBeenMoved(bool hasBeenMoved);
	void setDefenceStanceActive(bool defenceStanceActive);

	bool canMakeThatMove(float x, float newX, float y, float newY) const;

	string toStringSpecific() const;

private:
	bool hasBeenMoved;
	bool defenceStanceActive;

	sf::Texture footmanTexture;
	sf::Texture emptyTexture;
};

#endif