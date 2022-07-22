#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Piece
{
public:
	Piece();
	Piece(int id, int health, float deathX, float deathY, float x, float y, string team);
	Piece(const Piece &origObj);
	virtual ~Piece();

	int getId() const;
	int getHealth() const;
	float getDeathX() const;
	float getDeathY() const;
	float getX() const;
	float getY() const;
	string getTeam() const;

	virtual int getPieceType() const = 0;
	virtual sf::Texture getTexture() const = 0;
	virtual void setToDeadTexture() = 0;

	void setId(int id);
	void setHealth(int health);
	void setDeathX(float deathX);
	void setDeathY(float deathY);
	void setX(float x);
	void setY(float y);
	void setTeam(string team);

	

	string toString() const;
	virtual string toStringSpecific() const = 0;

	void operator=(const Piece &origObj);

private:
	int id;
	int health;
	float deathX;
	float deathY;
	float x;
	float y;
	string team;

};

#endif