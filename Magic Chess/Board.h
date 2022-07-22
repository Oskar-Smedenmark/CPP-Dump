#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "MyEnums.h"

class Board : public sf::Drawable
{
public:
	Board();
	Board(const Board &origObj);
	virtual ~Board();

	void drawBoard(sf::RenderTarget &target, sf::RenderStates states) const;

	void loadBoard();

	void operator=(const Board &origObj);

private:
	static const int BOARDCAP = 8;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Sprite board[BOARDCAP][BOARDCAP];

	sf::Texture cobbleTexture;
	sf::Texture brimstoneTexture;
};

#endif