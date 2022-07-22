#include "Board.h"
#include "Footman.h"
#include "Empty.h"
#include <iostream>

//Constructors and destructor
Board::Board()
{
	sf::Texture cobbleTexture;
	sf::Texture brimstoneTexture;

	if (!cobbleTexture.loadFromFile("../assets/Cobble.jpg"))
	{
		cout << "Error loading sprite";
	}
	if (!brimstoneTexture.loadFromFile("../assets/Red brick.png"))
	{
		cout << "Error loading sprite";
	}

	this->cobbleTexture = cobbleTexture;
	this->brimstoneTexture = brimstoneTexture;
}
Board::Board(const Board &origObj)
{
	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			this->board[i][j] = origObj.board[i][j];
		}
	}

	this->cobbleTexture = origObj.cobbleTexture;
	this->brimstoneTexture = origObj.brimstoneTexture;
}
Board::~Board()
{

}

//Draw out the board
void Board::drawBoard(sf::RenderTarget &target, sf::RenderStates states) const
{
	this->draw(target, states);
}
void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			target.draw(this->board[i][j], states);
		}
	}
}

//Initialize the boards
void Board::loadBoard()
{
	//The board texture loading
	sf::Vector2f size(100, 100);

	bool theSwitch = false;

	float x = 0.0f;
	float y = 0.0f;

	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			this->board[i][j].setPosition(x, y);
			if (i % 2 == 0 && j % 2 == 0 && theSwitch == false)
			{
				this->board[i][j].setTexture(this->cobbleTexture);
			}
			else if (i % 2 == 0 && j % 2 == 1 && theSwitch == false)
			{
				this->board[i][j].setTexture(this->brimstoneTexture);
			}

			if (i % 2 == 1 && j % 2 == 0 && theSwitch == true)
			{
				this->board[i][j].setTexture(this->brimstoneTexture);
			}
			else if (i % 2 == 1 && j % 2 == 1 && theSwitch == true)
			{
				this->board[i][j].setTexture(this->cobbleTexture);
			}
			x += size.x;
		}

		y += size.y;
		x = 0.0f;
		if (theSwitch == false)
		{
			theSwitch = true;
		}
		else
		{
			theSwitch = false;
		}
	}	
	
}

//Operators
void Board::operator=(const Board &origObj)
{
	if (this != &origObj)
	{
		for (int i = 0; i < this->BOARDCAP; i++)
		{
			for (int j = 0; j < this->BOARDCAP; j++)
			{
				this->board[i][j] = origObj.board[i][j];
			}
		}

		this->cobbleTexture = origObj.cobbleTexture;
		this->brimstoneTexture = origObj.brimstoneTexture;
	}
}