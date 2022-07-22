#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Piece.h"
#include "Board.h"

using namespace std;

class Game : public sf::Drawable
{
public:
	Game(Board theBoard);
	virtual ~Game();

	void update(float dt, sf::Window &window);

	void setSpriteBoard();

	void drawLogicBoard() const;

	string save() const;

	bool gameOver() const;

	void setLogicBoard(int indexX, int indexY, int piece);
	void savedGamePieces(int indexX, int indexY, string team);
	void setWhitePlayersTurn(bool whitePlayersTurn);

private:
	static const int BOARDCAP = 8;
	static const int PIECECAP = 32;

	int nrOfBlackCheckingPieces;
	int nrOfWhiteCheckingPieces;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int logicBoard[BOARDCAP][BOARDCAP];

	Board theBoard;

	bool whitePlayersTurn;
	bool buttonBeenPressed;
	bool spriteBoardHasBeenExecuted;
	bool whiteCheck;
	bool blackCheck;
	bool whiteCheckmate;
	bool blackCheckmate;

	Piece* gamePieces[BOARDCAP][BOARDCAP];
	Piece* blackCheckingPieces[PIECECAP];
	Piece* whiteCheckingPieces[PIECECAP];
	sf::Texture pieceTextures[BOARDCAP][BOARDCAP];
	sf::Sprite spritePieces[BOARDCAP][BOARDCAP];

	bool checkIfPossible(float x, float y, float newX, float newY, int thePieceId, int indexX, int indexY, int newIndexX, int newIndexY) const;

	bool isFootmanMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const;
	bool isTowerMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const;
	bool isKnightMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const;
	bool isBowmanMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const;
	bool isQueenMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const;
	bool isWizardMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const;

	bool wizardInCheck(int wizardIndexX, int wizardIndexY, int attackIndexX, int attackIndexY, bool pieceAlreadyInPos);
	bool checkCheckingPieces(int wizardIndexX, int wizardIndexY, int attackIndexX, int attackIndexY, bool canPieceMakeAMove);
	bool checkmateCheck(int wizardIndexX, int wizardIndexY, int attackIndexX, int attackIndexY);
};

#endif