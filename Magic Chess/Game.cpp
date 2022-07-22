#include "Game.h"
#include "Empty.h"
#include "Footman.h"
#include "Tower.h"
#include "Knight.h"
#include "Bowman.h"
#include "Queen.h"
#include "Wizard.h"
#include "MyEnums.h"
#include <iostream>
#include <sstream>


Game::Game(Board theBoard)
{
	//Setting up the logic board
	int nrOfElements = 64;
	int width = 8;

	State level1[] = {
		TOWER, KNIGHT, BOWMAN, QUEEN, WIZARD, BOWMAN, KNIGHT, TOWER,
		FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN,
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
		FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN, FOOTMAN,
		TOWER, KNIGHT, BOWMAN, QUEEN, WIZARD, BOWMAN, KNIGHT, TOWER
	};
	State level2[] = {
		TOWER, KNIGHT, BOWMAN, QUEEN, WIZARD, BOWMAN, KNIGHT, TOWER,
		FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY,
		EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN,
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
		EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
		EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN,
		FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY, FOOTMAN, EMPTY,
		TOWER, KNIGHT, BOWMAN, QUEEN, WIZARD, BOWMAN, KNIGHT, TOWER
	};

	for (int i = 0; i < nrOfElements; i++)
	{
		int xP = i / width;
		int yP = i % width;
		this->logicBoard[xP][yP] = level1[i];
	}

	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			//Initiate all the black gamePieces
			if (i == 0 && j == 0 || i == 0 && j == 7)
			{
				this->gamePieces[i][j] = new Tower(TOWER, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
			}
			if (i == 0 && j == 1 || i == 0 && j == 6)
			{
				this->gamePieces[i][j] = new Knight(KNIGHT, 2, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
			}
			if (i == 0 && j == 2 || i == 0 && j == 5)
			{
				this->gamePieces[i][j] = new Bowman(BOWMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
			}
			if (i == 0 && j == 3)
			{
				this->gamePieces[i][j] = new Queen(QUEEN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
			}
			if (i == 0 && j == 4)
			{
				this->gamePieces[i][j] = new Wizard(WIZARD, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
			}
			if (i == 1)
			{
				this->gamePieces[i][j] = new Footman(FOOTMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
			}

			//Initiate all the white gamePieces
			if (i == 7 && j == 0 || i == 7 && j == 7)
			{
				this->gamePieces[i][j] = new Tower(TOWER, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
			}
			if (i == 7 && j == 1 || i == 7 && j == 6)
			{
				this->gamePieces[i][j] = new Knight(KNIGHT, 2, 0, 0, j * 100 + 100, i * 100 + 100, "White");
			}
			if (i == 7 && j == 2 || i == 7 && j == 5)
			{
				this->gamePieces[i][j] = new Bowman(BOWMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
			}
			if (i == 7 && j == 3)
			{
				this->gamePieces[i][j] = new Queen(QUEEN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
			}
			if (i == 7 && j == 4)
			{
				this->gamePieces[i][j] = new Wizard(WIZARD, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
			}
			if (i == 6)
			{
				this->gamePieces[i][j] = new Footman(FOOTMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
			}

			//Initiate all empty spaces
			if (i > 1 && i < 6)
			{
				this->gamePieces[i][j] = new Empty(EMPTY, 0, 0, 0, j * 100 + 100, i * 100 + 100, "empty");
			}
		}
	}
	this->whitePlayersTurn = true;
	this->buttonBeenPressed = false;
	this->theBoard = theBoard;
	this->spriteBoardHasBeenExecuted = false;
	this->whiteCheck = false;
	this->blackCheck = false;
	this->whiteCheckmate = false;
	this->blackCheckmate = false;
	this->nrOfBlackCheckingPieces = 0;
	this->nrOfWhiteCheckingPieces = 0;

	for (int i = 0; i < PIECECAP; i++)
	{
		this->whiteCheckingPieces[i] = nullptr;
		this->blackCheckingPieces[i] = nullptr;
	}
}
Game::~Game()
{
	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			delete this->gamePieces[i][j];
		}
	}

	for (int i = 0; i < this->nrOfBlackCheckingPieces; i++)
	{
		delete this->blackCheckingPieces[i];
	}

	for (int i = 0; i < this->nrOfWhiteCheckingPieces; i++)
	{
		delete this->whiteCheckingPieces[i];
	}
}

//Set-function
void Game::setSpriteBoard()
{
	float x = 0.0f;
	float y = 0.0f;

	bool whiteCheckResult = false;
	bool blackCheckResult = false;

	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			
			if (this->spriteBoardHasBeenExecuted == false)
			{
				//Initiate all the black gamePieces
				if (this->logicBoard[i][j] == TOWER && this->gamePieces[i][j]->getTeam() == "Black")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Tower(TOWER, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
				}
				if (this->logicBoard[i][j] == KNIGHT && this->gamePieces[i][j]->getTeam() == "Black")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Knight(KNIGHT, 2, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
				}
				if (this->logicBoard[i][j] == BOWMAN && this->gamePieces[i][j]->getTeam() == "Black")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Bowman(BOWMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
				}
				if (this->logicBoard[i][j] == QUEEN && this->gamePieces[i][j]->getTeam() == "Black")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Queen(QUEEN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
				}
				if (this->logicBoard[i][j] == WIZARD && this->gamePieces[i][j]->getTeam() == "Black")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Wizard(WIZARD, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
				}
				if (this->logicBoard[i][j] == FOOTMAN && this->gamePieces[i][j]->getTeam() == "Black")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Footman(FOOTMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "Black");
				}

				//Initiate all the white gamePieces
				if (this->logicBoard[i][j] == TOWER && this->gamePieces[i][j]->getTeam() == "White")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Tower(TOWER, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
				}
				if (this->logicBoard[i][j] == KNIGHT && this->gamePieces[i][j]->getTeam() == "White")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Knight(KNIGHT, 2, 0, 0, j * 100 + 100, i * 100 + 100, "White");
				}
				if (this->logicBoard[i][j] == BOWMAN && this->gamePieces[i][j]->getTeam() == "White")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Bowman(BOWMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
				}
				if (this->logicBoard[i][j] == QUEEN && this->gamePieces[i][j]->getTeam() == "White")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Queen(QUEEN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
				}
				if (this->logicBoard[i][j] == WIZARD && this->gamePieces[i][j]->getTeam() == "White")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Wizard(WIZARD, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
				}
				if (this->logicBoard[i][j] == FOOTMAN && this->gamePieces[i][j]->getTeam() == "White")
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Footman(FOOTMAN, 1, 0, 0, j * 100 + 100, i * 100 + 100, "White");
				}

				//Initiate all empty spaces
				if (this->logicBoard[i][j] == EMPTY)
				{
					delete this->gamePieces[i][j];
					this->gamePieces[i][j] = new Empty(EMPTY, 0, 0, 0, j * 100 + 100, i * 100 + 100, "empty");
				}
			}

			this->pieceTextures[i][j] = this->gamePieces[i][j]->getTexture();
			if (this->logicBoard[i][j] == EMPTY)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			else if (this->logicBoard[i][j] == FOOTMAN)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			else if (this->logicBoard[i][j] == TOWER)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			else if (this->logicBoard[i][j] == KNIGHT)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			else if (this->logicBoard[i][j] == BOWMAN)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			else if (this->logicBoard[i][j] == QUEEN)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			else if (this->logicBoard[i][j] == WIZARD)
			{
				spritePieces[i][j].setTexture(pieceTextures[i][j]);
				spritePieces[i][j].setPosition(x, y);
			}
			x += 100;
		}

		y += 100;
		x = 0.0f;
	}

	if (this->spriteBoardHasBeenExecuted == false)
	{
		for (int i = 0; i < this->BOARDCAP && whiteCheckResult == false || i < this->BOARDCAP && blackCheckResult == false; i++)
		{
			for (int j = 0; j < this->BOARDCAP && whiteCheckResult == false || j < this->BOARDCAP && blackCheckResult == false; j++)
			{				
				for (int n = 0; n < this->BOARDCAP && whiteCheckResult == false || n < this->BOARDCAP && blackCheckResult == false; n++)
				{
					for (int m = 0; m < this->BOARDCAP && whiteCheckResult == false || m < this->BOARDCAP && blackCheckResult == false; m++)
					{
						if (this->gamePieces[i][j]->getTeam() == "White" && this->gamePieces[i][j]->getId() == WIZARD && this->gamePieces[n][m]->getId() != EMPTY && this->gamePieces[n][m]->getTeam() == "Black")
						{
							if (wizardInCheck(j, i, m, n, false) == true)
							{
								blackCheckResult = true;
							}
						}
						if (this->gamePieces[i][j]->getTeam() == "Black" && this->gamePieces[i][j]->getId() == WIZARD && this->gamePieces[n][m]->getId() != EMPTY && this->gamePieces[n][m]->getTeam() == "White")
						{
							if (wizardInCheck(j, i, m, n, false) == true)
							{
								whiteCheckResult = true;
							}
						}
					}
				}				
			}
		}

		if (whiteCheckResult == true)
		{
			this->blackCheck = true;
		}
		if (blackCheckResult == true)
		{
			this->whiteCheck = true;
		}
	}
}

void Game::update(float dt, sf::Window &window)
{

	float pieceX = 0;
	float pieceY = 0;

	int MouseX = sf::Mouse::getPosition(window).x;
	int MouseY = sf::Mouse::getPosition(window).y;
	int thePieceId = 0;
	int indexY = 0;
	int indexX = 0;
	int newIndexX = 0;
	int newIndexY = 0;
	int deadIndexX = 0;
	int deadIndexY = 0;
	int intTemp = 0;

	Piece* pieceTemp = nullptr;
	Empty* emptyTemp = nullptr;
	Footman* footmanTemp = nullptr;
	Tower* towerTemp = nullptr;
	Knight* knightTemp = nullptr;
	Bowman* bowmanTemp = nullptr;
	Queen* queenTemp = nullptr;
	Wizard* wizardTemp = nullptr;
	
	sf::Sprite spriteTemp;
	
	bool found = false;
	bool newPos = false;
	bool legitMove = true;
	bool self = true;


	if (this->whiteCheckmate != true && this->blackCheckmate != true)
	{
		if (this->whitePlayersTurn == true)
		{
			//Piece movement and checks white player
			if (this->whiteCheck != true && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
			{
				cout << "Piece selected" << endl;
				for (int i = 0; i < this->BOARDCAP && found == false; i++)
				{
					for (int j = 0; j < this->BOARDCAP && found == false; j++)
					{
						if (MouseX <= this->gamePieces[i][j]->getX() && MouseX >= this->gamePieces[i][j]->getX() - 100 && MouseY <= this->gamePieces[i][j]->getY() && MouseY >= this->gamePieces[i][j]->getY() - 100 && found == false /*&& this->gamePieces[i][j]->getId() == FOOTMAN*/)
						{
							if (this->gamePieces[i][j]->getId() != EMPTY && this->gamePieces[i][j]->getTeam() != "Black")
							{
								pieceX = this->gamePieces[i][j]->getX();
								pieceY = this->gamePieces[i][j]->getY();
								thePieceId = this->gamePieces[i][j]->getId();
								indexY = i;
								indexX = j;

								this->buttonBeenPressed = true;

								while (newPos != true)
								{

									MouseX = sf::Mouse::getPosition(window).x;
									MouseY = sf::Mouse::getPosition(window).y;
									if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
									{
										for (int n = 0; n < this->BOARDCAP && newPos != true; n++)
										{
											for (int m = 0; m < this->BOARDCAP && newPos != true; m++)
											{
												newIndexX = m;
												newIndexY = n;
												if (MouseX <= this->gamePieces[n][m]->getX() && MouseX >= this->gamePieces[n][m]->getX() - 100 && MouseY <= this->gamePieces[n][m]->getY() && MouseY >= this->gamePieces[n][m]->getY() - 100 && found == false && this->gamePieces[i][j]->getId() != EMPTY && this->checkIfPossible(pieceX, pieceY, this->gamePieces[n][m]->getX(), this->gamePieces[n][m]->getY(), thePieceId, indexX, indexY, newIndexX, newIndexY) != false)
												{
													cout << gamePieces[i][j]->toString();
													self = false;
													footmanTemp = dynamic_cast<Footman*>(this->gamePieces[i][j]);

													if (footmanTemp != nullptr)
													{
														footmanTemp->setHasBeenMoved(true);
													}

													if (this->gamePieces[n][m]->getId() != EMPTY)
													{
														this->gamePieces[n][m]->setHealth(0);
														deadIndexX = j;
														deadIndexY = i;
													}

													intTemp = this->logicBoard[i][j];
													this->logicBoard[i][j] = this->logicBoard[n][m];
													this->logicBoard[n][m] = intTemp;

													pieceTemp = this->gamePieces[i][j];
													this->gamePieces[i][j] = this->gamePieces[n][m];
													this->gamePieces[n][m] = pieceTemp;

													this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
													this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

													this->gamePieces[i][j]->setX(pieceX);
													this->gamePieces[i][j]->setY(pieceY);

													spriteTemp = this->spritePieces[i][j];
													this->spritePieces[i][j] = this->spritePieces[n][m];
													this->spritePieces[n][m] = spriteTemp;

													this->drawLogicBoard();

													newPos = true;
													this->whitePlayersTurn = false;

													for (int k = 0; k < this->BOARDCAP && this->whiteCheck == false; k++)
													{
														for (int l = 0; l < this->BOARDCAP && this->whiteCheck == false; l++)
														{
															if (this->gamePieces[k][l]->getId() == WIZARD && this->gamePieces[k][l]->getTeam() == "White")
															{
																if (this->nrOfBlackCheckingPieces != 0)
																{
																	for (int p = 0; p < this->nrOfBlackCheckingPieces; p++)
																	{
																		this->whiteCheck = this->checkCheckingPieces(l, k, (this->blackCheckingPieces[p]->getX() - 100) / 100, (this->blackCheckingPieces[p]->getY() - 100) / 100, true);
																	}
																}
																if (this->gamePieces[n][m]->getId() == WIZARD)
																{
																	for (int g = 0; g < this->BOARDCAP && this->whiteCheck == false; g++)
																	{
																		for (int h = 0; h < this->BOARDCAP && this->whiteCheck == false; h++)
																		{
																			if (this->gamePieces[g][h]->getTeam() == "Black" && this->gamePieces[g][h]->getId() != EMPTY)
																			{
																				this->whiteCheck = this->wizardInCheck(l, k, h, g, false);
																			}
																		}
																	}
																}
															}
														}
													}

													if (whiteCheck == true)
													{
														intTemp = this->logicBoard[i][j];
														this->logicBoard[i][j] = this->logicBoard[n][m];
														this->logicBoard[n][m] = intTemp;

														pieceTemp = this->gamePieces[i][j];
														this->gamePieces[i][j] = this->gamePieces[n][m];
														this->gamePieces[n][m] = pieceTemp;

														this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
														this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

														this->gamePieces[i][j]->setX(pieceX);
														this->gamePieces[i][j]->setY(pieceY);

														spriteTemp = this->spritePieces[i][j];
														this->spritePieces[i][j] = this->spritePieces[n][m];
														this->spritePieces[n][m] = spriteTemp;

														this->drawLogicBoard();

														if (footmanTemp != nullptr)
														{
															footmanTemp->setHasBeenMoved(false);
														}
														if (this->gamePieces[n][m]->getId() != EMPTY)
														{
															this->gamePieces[n][m]->setHealth(1);
															deadIndexX = 0;
															deadIndexY = 0;
														}

														this->whiteCheck = false;
														this->whitePlayersTurn = true;
													}
												}
											}
										}
										newPos = true;
									}

									if (this->buttonBeenPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
									{
										this->buttonBeenPressed = false;
									}
								}
								found = true;
							}
						}
					}
				}
				this->buttonBeenPressed = true;
			}
			//If piece is checked
			if (this->whiteCheck == true && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
			{
				for (int i = 0; i < this->BOARDCAP && found == false; i++)
				{
					for (int j = 0; j < this->BOARDCAP && found == false; j++)
					{
						if (MouseX <= this->gamePieces[i][j]->getX() && MouseX >= this->gamePieces[i][j]->getX() - 100 && MouseY <= this->gamePieces[i][j]->getY() && MouseY >= this->gamePieces[i][j]->getY() - 100 && found == false /*&& this->gamePieces[i][j]->getId() == FOOTMAN*/)
						{
							if (this->gamePieces[i][j]->getId() != EMPTY && this->gamePieces[i][j]->getTeam() != "Black")
							{
								pieceX = this->gamePieces[i][j]->getX();
								pieceY = this->gamePieces[i][j]->getY();
								thePieceId = this->gamePieces[i][j]->getId();
								indexY = i;
								indexX = j;

								this->buttonBeenPressed = true;

								while (newPos != true)
								{
									MouseX = sf::Mouse::getPosition(window).x;
									MouseY = sf::Mouse::getPosition(window).y;
									if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
									{
										for (int n = 0; n < this->BOARDCAP && newPos != true; n++)
										{
											for (int m = 0; m < this->BOARDCAP && newPos != true; m++)
											{
												newIndexX = m;
												newIndexY = n;
												if (MouseX <= this->gamePieces[n][m]->getX() && MouseX >= this->gamePieces[n][m]->getX() - 100 && MouseY <= this->gamePieces[n][m]->getY() && MouseY >= this->gamePieces[n][m]->getY() - 100 && found == false && this->gamePieces[i][j]->getId() != EMPTY && this->checkIfPossible(pieceX, pieceY, this->gamePieces[n][m]->getX(), this->gamePieces[n][m]->getY(), thePieceId, indexX, indexY, newIndexX, newIndexY) != false)
												{
													self = false;

													footmanTemp = dynamic_cast<Footman*>(this->gamePieces[i][j]);

													if (footmanTemp != nullptr)
													{
														footmanTemp->setHasBeenMoved(true);
													}

													if (this->gamePieces[n][m]->getId() != EMPTY)
													{
														this->gamePieces[n][m]->setHealth(0);
														deadIndexX = j;
														deadIndexY = i;
													}

													intTemp = this->logicBoard[i][j];
													this->logicBoard[i][j] = this->logicBoard[n][m];
													this->logicBoard[n][m] = intTemp;

													pieceTemp = this->gamePieces[i][j];
													this->gamePieces[i][j] = this->gamePieces[n][m];
													this->gamePieces[n][m] = pieceTemp;

													this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
													this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

													this->gamePieces[i][j]->setX(pieceX);
													this->gamePieces[i][j]->setY(pieceY);

													spriteTemp = this->spritePieces[i][j];
													this->spritePieces[i][j] = this->spritePieces[n][m];
													this->spritePieces[n][m] = spriteTemp;

													this->drawLogicBoard();

													newPos = true;
													this->whitePlayersTurn = false;

													for (int k = 0; k < this->BOARDCAP && this->whiteCheck == true; k++)
													{
														for (int l = 0; l < this->BOARDCAP && this->whiteCheck == true; l++)
														{
															if (this->gamePieces[k][l]->getId() == WIZARD && this->gamePieces[k][l]->getTeam() == "White")
															{
																for (int p = 0; p < this->nrOfBlackCheckingPieces; p++)
																{
																	this->whiteCheck = this->checkCheckingPieces(l, k, (this->blackCheckingPieces[p]->getX() - 100) / 100, (this->blackCheckingPieces[p]->getY() - 100) / 100, true);
																}
															}
														}
													}

													if (this->whiteCheck == true)
													{
														intTemp = this->logicBoard[i][j];
														this->logicBoard[i][j] = this->logicBoard[n][m];
														this->logicBoard[n][m] = intTemp;

														pieceTemp = this->gamePieces[i][j];
														this->gamePieces[i][j] = this->gamePieces[n][m];
														this->gamePieces[n][m] = pieceTemp;

														this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
														this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

														this->gamePieces[i][j]->setX(pieceX);
														this->gamePieces[i][j]->setY(pieceY);

														spriteTemp = this->spritePieces[i][j];
														this->spritePieces[i][j] = this->spritePieces[n][m];
														this->spritePieces[n][m] = spriteTemp;

														this->drawLogicBoard();

														if (footmanTemp != nullptr)
														{
															footmanTemp->setHasBeenMoved(false);
														}
														if (this->gamePieces[n][m]->getId() != EMPTY)
														{
															this->gamePieces[n][m]->setHealth(1);
															deadIndexX = 0;
															deadIndexY = 0;
														}
														this->whitePlayersTurn = true;
													}
												}
											}
										}
										newPos = true;
									}


									if (this->buttonBeenPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
									{
										this->buttonBeenPressed = false;
									}
								}
							}
							found = true;
						}
					}
				}
			}
		}
		else if (this->whitePlayersTurn == false)
		{
			//Piece movement and checks black player
			if (this->blackCheck != true && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
			{
				cout << "Piece selected" << endl;
				for (int i = 0; i < this->BOARDCAP && found == false; i++)
				{
					for (int j = 0; j < this->BOARDCAP && found == false; j++)
					{
						if (MouseX <= this->gamePieces[i][j]->getX() && MouseX >= this->gamePieces[i][j]->getX() - 100 && MouseY <= this->gamePieces[i][j]->getY() && MouseY >= this->gamePieces[i][j]->getY() - 100 && found == false /*&& this->gamePieces[i][j]->getId() == FOOTMAN*/)
						{
							if (this->gamePieces[i][j]->getId() != EMPTY && this->gamePieces[i][j]->getTeam() != "White")
							{
								pieceX = this->gamePieces[i][j]->getX();
								pieceY = this->gamePieces[i][j]->getY();
								thePieceId = this->gamePieces[i][j]->getId();
								indexY = i;
								indexX = j;

								this->buttonBeenPressed = true;

								while (newPos != true)
								{

									MouseX = sf::Mouse::getPosition(window).x;
									MouseY = sf::Mouse::getPosition(window).y;
									if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
									{
										for (int n = 0; n < this->BOARDCAP && newPos != true; n++)
										{
											for (int m = 0; m < this->BOARDCAP && newPos != true; m++)
											{
												newIndexX = m;
												newIndexY = n;
												if (MouseX <= this->gamePieces[n][m]->getX() && MouseX >= this->gamePieces[n][m]->getX() - 100 && MouseY <= this->gamePieces[n][m]->getY() && MouseY >= this->gamePieces[n][m]->getY() - 100 && found == false && this->gamePieces[i][j]->getId() != EMPTY && this->checkIfPossible(pieceX, pieceY, this->gamePieces[n][m]->getX(), this->gamePieces[n][m]->getY(), thePieceId, indexX, indexY, newIndexX, newIndexY) != false)
												{
													cout << gamePieces[i][j]->toString();
													self = false;

													footmanTemp = dynamic_cast<Footman*>(this->gamePieces[i][j]);

													if (footmanTemp != nullptr)
													{
														footmanTemp->setHasBeenMoved(true);
													}

													if (this->gamePieces[n][m]->getId() != EMPTY)
													{
														this->gamePieces[n][m]->setHealth(0);
														deadIndexX = j;
														deadIndexY = i;
													}

													intTemp = this->logicBoard[i][j];
													this->logicBoard[i][j] = this->logicBoard[n][m];
													this->logicBoard[n][m] = intTemp;

													pieceTemp = this->gamePieces[i][j];
													this->gamePieces[i][j] = this->gamePieces[n][m];
													this->gamePieces[n][m] = pieceTemp;

													this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
													this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

													this->gamePieces[i][j]->setX(pieceX);
													this->gamePieces[i][j]->setY(pieceY);

													spriteTemp = this->spritePieces[i][j];
													this->spritePieces[i][j] = this->spritePieces[n][m];
													this->spritePieces[n][m] = spriteTemp;

													newPos = true;
													this->whitePlayersTurn = true;

													for (int k = 0; k < this->BOARDCAP && this->blackCheck == false; k++)
													{
														for (int l = 0; l < this->BOARDCAP && this->blackCheck == false; l++)
														{
															if (this->gamePieces[k][l]->getId() == WIZARD && this->gamePieces[k][l]->getTeam() == "Black")
															{
																if (this->nrOfWhiteCheckingPieces != 0)
																{
																	for (int p = 0; p < this->nrOfWhiteCheckingPieces; p++)
																	{
																		this->blackCheck = this->checkCheckingPieces(l, k, (this->whiteCheckingPieces[p]->getX() - 100) / 100, (this->whiteCheckingPieces[p]->getY() - 100) / 100, true);
																	}
																}
																if (this->gamePieces[n][m]->getId() == WIZARD)
																{
																	for (int g = 0; g < this->BOARDCAP && this->blackCheck == false; g++)
																	{
																		for (int h = 0; h < this->BOARDCAP && this->blackCheck == false; h++)
																		{
																			if (this->gamePieces[g][h]->getTeam() == "White" && this->gamePieces[g][h]->getId() != EMPTY)
																			{
																				this->blackCheck = this->wizardInCheck(l, k, h, g, false);
																			}
																		}
																	}
																}
															}
														}
													}

													if (blackCheck == true)
													{
														intTemp = this->logicBoard[i][j];
														this->logicBoard[i][j] = this->logicBoard[n][m];
														this->logicBoard[n][m] = intTemp;

														pieceTemp = this->gamePieces[i][j];
														this->gamePieces[i][j] = this->gamePieces[n][m];
														this->gamePieces[n][m] = pieceTemp;

														this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
														this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

														this->gamePieces[i][j]->setX(pieceX);
														this->gamePieces[i][j]->setY(pieceY);

														spriteTemp = this->spritePieces[i][j];
														this->spritePieces[i][j] = this->spritePieces[n][m];
														this->spritePieces[n][m] = spriteTemp;

														if (footmanTemp != nullptr)
														{
															footmanTemp->setHasBeenMoved(false);
														}
														if (this->gamePieces[n][m]->getId() != EMPTY)
														{
															this->gamePieces[n][m]->setHealth(1);
															deadIndexX = 0;
															deadIndexY = 0;
														}

														this->whitePlayersTurn = false;
													}
												}
											}
										}
										newPos = true;
									}


									if (this->buttonBeenPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
									{
										this->buttonBeenPressed = false;
									}
								}
							}
							found = true;
						}
					}
				}
			}
			//If piece is checked
			if (this->blackCheck == true && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
			{
				for (int i = 0; i < this->BOARDCAP && found == false; i++)
				{
					for (int j = 0; j < this->BOARDCAP && found == false; j++)
					{
						if (MouseX <= this->gamePieces[i][j]->getX() && MouseX >= this->gamePieces[i][j]->getX() - 100 && MouseY <= this->gamePieces[i][j]->getY() && MouseY >= this->gamePieces[i][j]->getY() - 100 && found == false /*&& this->gamePieces[i][j]->getId() == FOOTMAN*/)
						{
							if (this->gamePieces[i][j]->getId() != EMPTY && this->gamePieces[i][j]->getTeam() != "White")
							{
								pieceX = this->gamePieces[i][j]->getX();
								pieceY = this->gamePieces[i][j]->getY();
								thePieceId = this->gamePieces[i][j]->getId();
								indexY = i;
								indexX = j;

								this->buttonBeenPressed = true;

								while (newPos != true)
								{
									MouseX = sf::Mouse::getPosition(window).x;
									MouseY = sf::Mouse::getPosition(window).y;
									if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->buttonBeenPressed == false)
									{
										for (int n = 0; n < this->BOARDCAP && newPos != true; n++)
										{
											for (int m = 0; m < this->BOARDCAP && newPos != true; m++)
											{
												newIndexX = m;
												newIndexY = n;
												if (MouseX <= this->gamePieces[n][m]->getX() && MouseX >= this->gamePieces[n][m]->getX() - 100 && MouseY <= this->gamePieces[n][m]->getY() && MouseY >= this->gamePieces[n][m]->getY() - 100 && found == false && this->gamePieces[i][j]->getId() != EMPTY && this->checkIfPossible(pieceX, pieceY, this->gamePieces[n][m]->getX(), this->gamePieces[n][m]->getY(), thePieceId, indexX, indexY, newIndexX, newIndexY) != false)
												{
													self = false;

													footmanTemp = dynamic_cast<Footman*>(this->gamePieces[i][j]);

													if (footmanTemp != nullptr)
													{
														footmanTemp->setHasBeenMoved(true);
													}

													if (this->gamePieces[n][m]->getId() != EMPTY)
													{
														this->gamePieces[n][m]->setHealth(0);
														deadIndexX = j;
														deadIndexY = i;
													}

													intTemp = this->logicBoard[i][j];
													this->logicBoard[i][j] = this->logicBoard[n][m];
													this->logicBoard[n][m] = intTemp;

													pieceTemp = this->gamePieces[i][j];
													this->gamePieces[i][j] = this->gamePieces[n][m];
													this->gamePieces[n][m] = pieceTemp;

													this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
													this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

													this->gamePieces[i][j]->setX(pieceX);
													this->gamePieces[i][j]->setY(pieceY);

													spriteTemp = this->spritePieces[i][j];
													this->spritePieces[i][j] = this->spritePieces[n][m];
													this->spritePieces[n][m] = spriteTemp;

													this->drawLogicBoard();

													newPos = true;
													this->whitePlayersTurn = true;

													for (int k = 0; k < this->BOARDCAP && this->blackCheck == true; k++)
													{
														for (int l = 0; l < this->BOARDCAP && this->blackCheck == true; l++)
														{
															if (this->gamePieces[k][l]->getId() == WIZARD && this->gamePieces[k][l]->getTeam() == "Black")
															{
																for (int p = 0; p < this->nrOfWhiteCheckingPieces; p++)
																{
																	this->blackCheck = this->checkCheckingPieces(l, k, (this->whiteCheckingPieces[p]->getX() - 100) / 100, (this->whiteCheckingPieces[p]->getY() - 100) / 100, true);
																}
															}
														}
													}

													if (this->blackCheck == true)
													{
														intTemp = this->logicBoard[i][j];
														this->logicBoard[i][j] = this->logicBoard[n][m];
														this->logicBoard[n][m] = intTemp;

														pieceTemp = this->gamePieces[i][j];
														this->gamePieces[i][j] = this->gamePieces[n][m];
														this->gamePieces[n][m] = pieceTemp;

														this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
														this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

														this->gamePieces[i][j]->setX(pieceX);
														this->gamePieces[i][j]->setY(pieceY);

														spriteTemp = this->spritePieces[i][j];
														this->spritePieces[i][j] = this->spritePieces[n][m];
														this->spritePieces[n][m] = spriteTemp;

														this->drawLogicBoard();

														if (footmanTemp != nullptr)
														{
															footmanTemp->setHasBeenMoved(false);
														}
														if (this->gamePieces[n][m]->getId() != EMPTY)
														{
															this->gamePieces[n][m]->setHealth(1);
															deadIndexX = 0;
															deadIndexY = 0;
														}
														this->whitePlayersTurn = false;
													}
												}
											}
										}
										newPos = true;
									}


									if (this->buttonBeenPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
									{
										this->buttonBeenPressed = false;
									}
								}
							}
							found = true;
						}
					}
				}
			}
			this->buttonBeenPressed = true;
		}


		if (this->buttonBeenPressed == true && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			this->buttonBeenPressed = false;
		}

		if (this->gamePieces[deadIndexY][deadIndexX]->getHealth() == 0)
		{
			footmanTemp = dynamic_cast<Footman*>(this->gamePieces[deadIndexY][deadIndexX]);
			towerTemp = dynamic_cast<Tower*>(this->gamePieces[deadIndexY][deadIndexX]);
			knightTemp = dynamic_cast<Knight*>(this->gamePieces[deadIndexY][deadIndexX]);
			bowmanTemp = dynamic_cast<Bowman*>(this->gamePieces[deadIndexY][deadIndexX]);
			queenTemp = dynamic_cast<Queen*>(this->gamePieces[deadIndexY][deadIndexX]);

			this->logicBoard[deadIndexY][deadIndexX] = EMPTY;

			if (footmanTemp != nullptr)
			{
				footmanTemp->setToDeadTexture();
				this->pieceTextures[deadIndexY][deadIndexX] = footmanTemp->getTexture();
			}
			else if (towerTemp != nullptr)
			{
				towerTemp->setToDeadTexture();
				this->pieceTextures[deadIndexY][deadIndexX] = towerTemp->getTexture();
			}
			else if (knightTemp != nullptr)
			{
				knightTemp->setToDeadTexture();
				this->pieceTextures[deadIndexY][deadIndexX] = knightTemp->getTexture();
			}
			else if (bowmanTemp != nullptr)
			{
				bowmanTemp->setToDeadTexture();
				this->pieceTextures[deadIndexY][deadIndexX] = bowmanTemp->getTexture();
			}
			else if (queenTemp != nullptr)
			{
				queenTemp->setToDeadTexture();
				this->pieceTextures[deadIndexY][deadIndexX] = queenTemp->getTexture();
			}

			this->gamePieces[deadIndexY][deadIndexX]->setId(EMPTY);
		}

		if (newPos == true || this->spriteBoardHasBeenExecuted == false)
		{
			this->setSpriteBoard();
			this->spriteBoardHasBeenExecuted = true;

			if (newPos == true && this->whitePlayersTurn != true && self == false)
			{
				for (int i = 0; i < this->BOARDCAP; i++)
				{
					for (int j = 0; j < this->BOARDCAP; j++)
					{
						if (this->gamePieces[i][j]->getId() == WIZARD && this->gamePieces[i][j]->getTeam() == "Black")
						{
							this->blackCheck = this->wizardInCheck(j, i, newIndexX, newIndexY, false);

							if (this->nrOfWhiteCheckingPieces != 0)
							{
								for (int k = 0; k < this->nrOfWhiteCheckingPieces && blackCheck != true; k++)
								{
									this->blackCheck = this->checkCheckingPieces(j, i, (this->whiteCheckingPieces[k]->getX() - 100) / 100, (this->whiteCheckingPieces[k]->getY() - 100) / 100, false);
								}
							}
						}
					}
				}
			}
			else if (newPos == true && this->whitePlayersTurn == true && self == false)
			{
				for (int i = 0; i < this->BOARDCAP; i++)
				{
					for (int j = 0; j < this->BOARDCAP; j++)
					{
						if (this->gamePieces[i][j]->getId() == WIZARD && this->gamePieces[i][j]->getTeam() == "White")
						{
							this->whiteCheck = this->wizardInCheck(j, i, newIndexX, newIndexY, false);

							if (this->nrOfBlackCheckingPieces != 0)
							{
								for (int k = 0; k < this->nrOfBlackCheckingPieces && whiteCheck != true; k++)
								{
									this->whiteCheck = this->checkCheckingPieces(j, i, (this->blackCheckingPieces[k]->getX() - 100) / 100, (this->blackCheckingPieces[k]->getY() - 100) / 100, false);
								}
							}
						}
					}
				}
			}
		}
		if (this->blackCheck == true)
		{
			cout << "Black is checked" << endl;
			/*for (int i = 0; i < this->BOARDCAP; i++)
			{
				for (int j = 0; j < this->BOARDCAP; j++)
				{
					if (this->gamePieces[i][j]->getId() == WIZARD && this->gamePieces[i][j]->getTeam() == "Black")
					{
						this->blackCheckmate = this->checkmateCheck(j, i, newIndexX, newIndexY);
					}
				}
			}*/
		}
		if (this->whiteCheck == true)
		{
			cout << "White is checked" << endl;
			/*for (int i = 0; i < this->BOARDCAP; i++)
			{
				for (int j = 0; j < this->BOARDCAP; j++)
				{
					if (this->gamePieces[i][j]->getId() == WIZARD && this->gamePieces[i][j]->getTeam() == "White")
					{
						this->whiteCheckmate = this->checkmateCheck(j, i, newIndexX, newIndexY);
					}
				}
			}*/
		}
	}

	
	if (this->whiteCheckmate == true && this->blackCheckmate != true)
	{
		cout << "HAHA, BLACK WINS! YOU'RE A LOSER WHITE!" << endl;
	}
	if (this->whiteCheckmate != true && this->blackCheckmate == true)
	{
		cout << "HAHA, WHITE WINS! YOU'RE A LOSER BLACK!" << endl;
	}

	cout << "Fps: " << 1/dt << endl;
	cout << sf::Mouse::getPosition(window).x << endl;
}


void Game::drawLogicBoard() const
{
	cout << endl << endl;
	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			cout << this->logicBoard[i][j];
		}
		cout << endl;
	}
}

string Game::save() const
{
	stringstream converter;

	converter << this->whitePlayersTurn << endl;
	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			converter << this->logicBoard[i][j] << endl;
			converter << this->gamePieces[i][j]->getTeam() << endl;
		}
	}

	return converter.str();
}

bool Game::gameOver() const
{
	bool result = false;
	if (this->whiteCheckmate == true || this->blackCheckmate == true)
	{
		result = true;
	}
	return result;
}

void Game::setLogicBoard(int indexX, int indexY, int piece)
{
	this->logicBoard[indexY][indexX] = piece;
}
void Game::savedGamePieces(int indexX, int indexY, string team)
{
	this->gamePieces[indexY][indexX]->setTeam(team);
}
void Game::setWhitePlayersTurn(bool whitePlayersTurn)
{
	this->whitePlayersTurn = whitePlayersTurn;
}
//Draw everything
void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	this->theBoard.drawBoard(target, states);
	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			target.draw(this->spritePieces[i][j], states);
		}
	}
}


bool Game::checkIfPossible(float x, float y, float newX, float newY, int thePieceId, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	bool canMakeMove = false;

	switch (thePieceId)
	{
	case 1:
		canMakeMove = this->isFootmanMovePossible(x, y, newX, newY, indexX, indexY, newIndexX, newIndexY);
		break;

	case 2:
		canMakeMove = this->isTowerMovePossible(x, y, newX, newY, indexX, indexY, newIndexX, newIndexY);
		break;

	case 3:
		canMakeMove = this->isKnightMovePossible(x, y, newX, newY, indexX, indexY, newIndexX, newIndexY);
		break;

	case 4:
		canMakeMove = this->isBowmanMovePossible(x, y, newX, newY, indexX, indexY, newIndexX, newIndexY);
		break;

	case 5:
		canMakeMove = this->isQueenMovePossible(x, y, newX, newY, indexX, indexY, newIndexX, newIndexY);
		break;

	case 6:
		canMakeMove = this->isWizardMovePossible(x, y, newX, newY, indexX, indexY, newIndexX, newIndexY);
		break;
	}
	
	return canMakeMove;
}

//Footman check
bool Game::isFootmanMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	Footman* footmanTemp = nullptr;
	bool result = false;

	footmanTemp = dynamic_cast<Footman*>(this->gamePieces[indexY][indexX]);

	if (footmanTemp != nullptr)
	{
		if (footmanTemp->canMakeThatMove(x, newX, y, newY) == true)
		{
			if (footmanTemp->getTeam() == "Black")
			{
				result = true;

				if (this->gamePieces[indexY + 1][indexX]->getId() != EMPTY && x == newX)
				{
					result = false;
				}
				if (footmanTemp->getHasBeenMoved() == false && this->gamePieces[indexY + 2][indexX]->getId() != EMPTY && x == newX)
				{
					result = false;
				}

				if (x == newX + 100 || x == newX - 100 && y < newY)
				{
					if (this->gamePieces[newIndexY][newIndexX]->getId() != EMPTY && this->gamePieces[newIndexY][newIndexX]->getTeam() != "Black")
					{
						result = true;
					}
					else
					{
						result = false;
					}
				}
			}
			else
			{
				result = true;

				if (this->gamePieces[indexY - 1][indexX]->getId() != EMPTY && x == newX)
				{
					result = false;
				}
				if (footmanTemp->getHasBeenMoved() == false && this->gamePieces[indexY - 2][indexX]->getId() != EMPTY && x == newX)
				{
					result = false;
				}

				if (x == newX + 100 || x == newX - 100 && y > newY)
				{
					if (this->gamePieces[newIndexY][newIndexX]->getId() != EMPTY && this->gamePieces[newIndexY][newIndexX]->getTeam() != "White")
					{
						result = true;
					}
					else
					{
						result = false;
					}
				}
			}
		
		
		}
	}
	return result;
}

//Tower check
bool Game::isTowerMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	bool result = false;
	bool pieceInTheWay = false;

	Tower* towerTemp = nullptr;

	towerTemp = dynamic_cast<Tower*>(this->gamePieces[indexY][indexX]);

	if (towerTemp != nullptr)
	{
		if (towerTemp->canMakeThatMove(x, newX, y, newY) == true)
		{
			if (towerTemp->getTeam() == "Black" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "Black")
			{
				//Up movement
				if (x == newX && y > newY)
				{

					for (int i = indexY; i > newIndexY + 1; i--)
					{
						if (this->gamePieces[i - 1][indexX]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
				//Down movement
				else if (x == newX && y < newY)
				{
					for (int i = indexY; i < newIndexY - 1; i++)
					{
						if (this->gamePieces[i + 1][indexX]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
				//Left movement
				if (y == newY && x > newX)
				{
					for (int i = indexX; i > newIndexX + 1; i--)
					{
						if (this->gamePieces[indexY][i - 1]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
				//Right movement
				else if (y == newY && x < newX)
				{
					for (int i = indexX; i < newIndexX - 1; i++)
					{
						if (this->gamePieces[indexY][i + 1]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
			}

			if (towerTemp->getTeam() == "White" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "White")
			{
				//Up movement
				if (x == newX && y > newY)
				{

					for (int i = indexY; i > newIndexY + 1; i--)
					{
						if (this->gamePieces[i - 1][indexX]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
				//Down movement
				else if (x == newX && y < newY)
				{
					for (int i = indexY; i < newIndexY - 1; i++)
					{
						if (this->gamePieces[i + 1][indexX]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
				//Left movement
				if (y == newY && x > newX)
				{
					for (int i = indexX; i > newIndexX + 1; i--)
					{
						if (this->gamePieces[indexY][i - 1]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
				//Right movement
				else if (y == newY && x < newX)
				{
					for (int i = indexX; i < newIndexX - 1; i++)
					{
						if (this->gamePieces[indexY][i + 1]->getId() != EMPTY)
						{
							pieceInTheWay = true;
						}
					}
				}
			}
			if (towerTemp->getTeam() == "White" && this->gamePieces[newIndexY][newIndexX]->getTeam() == "White")
			{
				result = false;
			}
			if (towerTemp->getTeam() == "Black" && this->gamePieces[newIndexY][newIndexX]->getTeam() == "Black")
			{
				result = false;

			}
			if (pieceInTheWay == true)
			{
				result = false;
			}
			if (pieceInTheWay == false && towerTemp->getTeam() == "White" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "White")
			{
				result = true;
			}
			if (pieceInTheWay == false && towerTemp->getTeam() == "Black" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "Black")
			{
				result = true;
			}
		}
		else
		{
			result = false;
		}
	}
	else
	{
		result = false;
	}
	return result;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}

//Knight check
bool Game::isKnightMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	Knight* knightTemp = nullptr;

	bool result = false;

	knightTemp = dynamic_cast<Knight*>(this->gamePieces[indexY][indexX]);

	if (knightTemp != nullptr)
	{
		if (knightTemp->canMakeThatMove(x, newX, y, newY) == true)
		{
			if (this->gamePieces[indexY][indexX]->getTeam() == "Black")
			{
				if (this->gamePieces[newIndexY][newIndexX]->getId() == EMPTY)
				{
					result = true;
				}
				else
				{
					if (this->gamePieces[newIndexY][newIndexX]->getTeam() == "White")
					{
						result = true;
					}
				}
			}
			else
			{
				if (this->gamePieces[newIndexY][newIndexX]->getId() == EMPTY)
				{
					result = true;
				}
				else
				{
					if (this->gamePieces[newIndexY][newIndexX]->getTeam() == "Black")
					{
						result = true;
					}
				}
			}
		}
	}

	return result;
}

//Bowman check
bool Game::isBowmanMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	Bowman* bowmanTemp = nullptr;

	bool result = false;
	bool correctMove = false;
	bool pieceInTheWay = false;

	bowmanTemp = dynamic_cast<Bowman*>(this->gamePieces[indexY][indexX]);

	if (bowmanTemp != nullptr)
	{
		correctMove = bowmanTemp->canMakeThatMove(x, newX, y, newY);
	}

	if (correctMove == true)
	{
		//Black piece
		if (this->gamePieces[indexY][indexX]->getTeam() == "Black" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "Black")
		{
			//Up movement
			if (x < newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			if (x > newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}

			//Down movement
			if (x < newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			if (x > newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
		}
		//White piece
		else if (this->gamePieces[indexY][indexX]->getTeam() == "White" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "White")
		{
			//Up movement
			if (x < newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			if (x > newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}

			//Down movement
			if (x < newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			if (x > newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
		}
	}

	return result;
}

//Queen check
bool Game::isQueenMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	Queen* queenTemp = nullptr;

	bool result = false;
	bool correctMove = false;
	bool pieceInTheWay = false;

	queenTemp = dynamic_cast<Queen*>(this->gamePieces[indexY][indexX]);

	if (queenTemp != nullptr)
	{
		correctMove = queenTemp->canMakeThatMove(x, newX, y, newY);
	}

	if (correctMove == true)
	{
		if (this->gamePieces[indexY][indexX]->getTeam() == "Black" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "Black")
		{
			//Up movement
			if (x == newX && y > newY)
			{

				for (int i = indexY; i > newIndexY + 1; i--)
				{
					if (this->gamePieces[i - 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Down movement
			else if (x == newX && y < newY)
			{
				for (int i = indexY; i < newIndexY - 1; i++)
				{
					if (this->gamePieces[i + 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Left movement
			if (y == newY && x > newX)
			{
				for (int i = indexX; i > newIndexX + 1; i--)
				{
					if (this->gamePieces[indexY][i - 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Right movement
			else if (y == newY && x < newX)
			{
				for (int i = indexX; i < newIndexX - 1; i++)
				{
					if (this->gamePieces[indexY][i + 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}

			//Right up
			if (x < newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left up
			if (x > newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}

			//Right down
			if (x < newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left down
			if (x > newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
		}
		else if (this->gamePieces[indexY][indexX]->getTeam() == "White" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "White")
		{
			//Up movement
			if (x == newX && y > newY)
			{

				for (int i = indexY; i > newIndexY + 1; i--)
				{
					if (this->gamePieces[i - 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Down movement
			else if (x == newX && y < newY)
			{
				for (int i = indexY; i < newIndexY - 1; i++)
				{
					if (this->gamePieces[i + 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Left movement
			if (y == newY && x > newX)
			{
				for (int i = indexX; i > newIndexX + 1; i--)
				{
					if (this->gamePieces[indexY][i - 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Right movement
			else if (y == newY && x < newX)
			{
				for (int i = indexX; i < newIndexX - 1; i++)
				{
					if (this->gamePieces[indexY][i + 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}


			//Right up
			if (x < newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left up
			if (x > newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}

			//Right down
			if (x < newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left down
			if (x > newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
		}
	}
	return result;
}

//wizard check
bool Game::isWizardMovePossible(float x, float y, float newX, float newY, int indexX, int indexY, int newIndexX, int newIndexY) const
{
	Wizard* wizardTemp = nullptr;

	bool result = false;
	bool correctMove = false;
	bool pieceInTheWay = false;

	wizardTemp = dynamic_cast<Wizard*>(this->gamePieces[indexY][indexX]);

	if (wizardTemp != nullptr)
	{
		correctMove = wizardTemp->canMakeThatMove(x, newX, y, newY);
	}

	if (correctMove == true)
	{
		if (this->gamePieces[indexY][indexX]->getTeam() == "Black" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "Black")
		{
			//Up movement
			if (x == newX && y > newY)
			{
				for (int i = indexY; i > newIndexY + 1; i--)
				{
					if (this->gamePieces[i - 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Down movement
			else if (x == newX && y < newY)
			{
				for (int i = indexY; i < newIndexY - 1; i++)
				{
					if (this->gamePieces[i + 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Left movement
			if (y == newY && x > newX)
			{
				for (int i = indexX; i > newIndexX + 1; i--)
				{
					if (this->gamePieces[indexY][i - 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Right movement
			else if (y == newY && x < newX)
			{
				for (int i = indexX; i < newIndexX - 1; i++)
				{
					if (this->gamePieces[indexY][i + 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}

			//Right up
			if (x < newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left up
			if (x > newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}

			//Right down
			if (x < newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left down
			if (x > newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
		}
		else if (this->gamePieces[indexY][indexX]->getTeam() == "White" && this->gamePieces[newIndexY][newIndexX]->getTeam() != "White")
		{
			//Up movement
			if (x == newX && y > newY)
			{

				for (int i = indexY; i > newIndexY + 1; i--)
				{
					if (this->gamePieces[i - 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Down movement
			else if (x == newX && y < newY)
			{
				for (int i = indexY; i < newIndexY - 1; i++)
				{
					if (this->gamePieces[i + 1][indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Left movement
			if (y == newY && x > newX)
			{
				for (int i = indexX; i > newIndexX + 1; i--)
				{
					if (this->gamePieces[indexY][i - 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}
			//Right movement
			else if (y == newY && x < newX)
			{
				for (int i = indexX; i < newIndexX - 1; i++)
				{
					if (this->gamePieces[indexY][i + 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay == false)
				{
					result = true;
				}
			}


			//Right up
			if (x < newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left up
			if (x > newX && y > newY)
			{
				for (int i = indexY - 1; i > newIndexY; i--)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}

			//Right down
			if (x < newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][++indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
			//Left down
			if (x > newX && y < newY)
			{
				for (int i = indexY + 1; i < newIndexY; i++)
				{
					if (this->gamePieces[i][--indexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
				if (pieceInTheWay != true)
				{
					result = true;
				}
			}
		}
	}
	return result;
}

//See if a wizard is checked
bool Game::wizardInCheck(int wizardIndexX, int wizardIndexY, int attackIndexX, int attackIndexY, bool pieceAlreadyInPos)
{
	bool pieceInTheWay = false;
	bool inRange = false;
	bool isPosible = false;
	bool result = false;

	int counter = 1;

	Footman* footmanTemp = nullptr;
	Tower* towerTemp = nullptr;
	Knight* knightTemp = nullptr;
	Bowman* bowmanTemp = nullptr;
	Queen* queenTemp = nullptr;
	Wizard* wizardTemp = nullptr;

	footmanTemp = dynamic_cast<Footman*>(this->gamePieces[attackIndexY][attackIndexX]);
	towerTemp = dynamic_cast<Tower*>(this->gamePieces[attackIndexY][attackIndexX]);
	knightTemp = dynamic_cast<Knight*>(this->gamePieces[attackIndexY][attackIndexX]);
	bowmanTemp = dynamic_cast<Bowman*>(this->gamePieces[attackIndexY][attackIndexX]);
	queenTemp = dynamic_cast<Queen*>(this->gamePieces[attackIndexY][attackIndexX]);
	wizardTemp = dynamic_cast<Wizard*>(this->gamePieces[wizardIndexY][wizardIndexX]);

	//Confirms if a footman is checking the wizard
	if (footmanTemp != nullptr)
	{
		isPosible = footmanTemp->canMakeThatMove(this->gamePieces[attackIndexY][attackIndexX]->getX(), this->gamePieces[wizardIndexY][wizardIndexX]->getX(), this->gamePieces[attackIndexY][attackIndexX]->getY(), this->gamePieces[wizardIndexY][wizardIndexX]->getY());
		if (isPosible == true)
		{
			if (this->gamePieces[attackIndexY][attackIndexX]->getTeam() == "Black")
			{
				if (this->gamePieces[wizardIndexY][wizardIndexX] == this->gamePieces[attackIndexY + 1][attackIndexX + 1] || this->gamePieces[wizardIndexY][wizardIndexX] == this->gamePieces[attackIndexY + 1][attackIndexX - 1])
				{
					inRange = true;
				}
			}
			else
			{
				if (this->gamePieces[wizardIndexY][wizardIndexX] == this->gamePieces[attackIndexY - 1][attackIndexX + 1] || this->gamePieces[wizardIndexY][wizardIndexX] == this->gamePieces[attackIndexY - 1][attackIndexX - 1])
				{
					inRange = true;
				}
			}
		}
	}
	
	//Confirms if a tower is checking the wizard
	if (towerTemp != nullptr)
	{
		isPosible = towerTemp->canMakeThatMove(this->gamePieces[wizardIndexY][wizardIndexX]->getX(), this->gamePieces[attackIndexY][attackIndexX]->getX(), this->gamePieces[wizardIndexY][wizardIndexX]->getY(), this->gamePieces[attackIndexY][attackIndexX]->getY());
		
		if (isPosible == true)
		{
			//Up movement
			if (attackIndexX == wizardIndexX  && attackIndexY > wizardIndexY)
			{

				for (int i = attackIndexY; i > wizardIndexY + 1; i--)
				{
					if (this->gamePieces[i - 1][attackIndexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
			//Down movement
			else if (attackIndexX == wizardIndexX && attackIndexY < wizardIndexY)
			{
				for (int i = wizardIndexY; i < wizardIndexY - 1; i++)
				{
					if (this->gamePieces[i + 1][attackIndexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
			//Left movement
			if (attackIndexY == wizardIndexY && attackIndexX > wizardIndexX)
			{
				for (int i = attackIndexX; i > wizardIndexX + 1; i--)
				{
					if (this->gamePieces[wizardIndexY][i - 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
			//Right movement
			else if (attackIndexY == wizardIndexY && attackIndexX < wizardIndexX)
			{
				for (int i = attackIndexX; i < wizardIndexX - 1; i++)
				{
					if (this->gamePieces[wizardIndexY][i + 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
		}
	}

	//Confirms if a knight is checking the wizard
	if (knightTemp != nullptr)
	{
		isPosible = knightTemp->canMakeThatMove(this->gamePieces[wizardIndexY][wizardIndexX]->getX(), this->gamePieces[attackIndexY][attackIndexX]->getX(), this->gamePieces[wizardIndexY][wizardIndexX]->getY(), this->gamePieces[attackIndexY][attackIndexX]->getY());
	}

	//Confirms if a bowman is checking the wizard
	if (bowmanTemp != nullptr)
	{
		isPosible = bowmanTemp->canMakeThatMove(this->gamePieces[wizardIndexY][wizardIndexX]->getX(), this->gamePieces[attackIndexY][attackIndexX]->getX(), this->gamePieces[wizardIndexY][wizardIndexX]->getY(), this->gamePieces[attackIndexY][attackIndexX]->getY());
		if (isPosible == true)
		{
			//Up-right movement
			if (attackIndexX < wizardIndexX && attackIndexY > wizardIndexY)
			{
				for (int i = attackIndexY - 1; i > wizardIndexY; i--)
				{
					if (this->gamePieces[i][attackIndexX + counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;
						
					}
					counter++;
				}
			}
			//Up-left movement
			if (attackIndexX > wizardIndexX && attackIndexY > wizardIndexY)
			{
				for (int i = attackIndexY - 1; i > wizardIndexY; i--)
				{
					if (this->gamePieces[i][attackIndexX - counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
					counter--;
				}
			}

			//Down-right movement
			if (attackIndexX < wizardIndexX && attackIndexY < wizardIndexY)
			{
				for (int i = attackIndexY + 1; i < wizardIndexY; i++)
				{
					if (this->gamePieces[i][attackIndexX + counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
					counter++;
				}
			}
			//Down-left movement
			if (attackIndexX > wizardIndexX && attackIndexY < wizardIndexY)
			{
				for (int i = attackIndexY + 1; i < wizardIndexY; i++)
				{
					if (this->gamePieces[i][attackIndexX - i]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
		}
	}

	if (queenTemp != nullptr)
	{
		isPosible = queenTemp->canMakeThatMove(this->gamePieces[attackIndexY][attackIndexX]->getX(), this->gamePieces[wizardIndexY][wizardIndexX]->getX(), this->gamePieces[attackIndexY][attackIndexX]->getY(), this->gamePieces[wizardIndexY][wizardIndexX]->getY());
		if (isPosible == true)
		{
			//Up movement
			if (attackIndexX == wizardIndexX  && attackIndexY > wizardIndexY)
			{

				for (int i = attackIndexY; i > wizardIndexY + 1; i--)
				{
					if (this->gamePieces[i - 1][attackIndexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
			//Down movement
			else if (attackIndexX == wizardIndexX && attackIndexY < wizardIndexY)
			{
				for (int i = wizardIndexY; i < wizardIndexY - 1; i++)
				{
					if (this->gamePieces[i + 1][attackIndexX]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
			//Left movement
			if (attackIndexY == wizardIndexY && attackIndexX > wizardIndexX)
			{
				for (int i = attackIndexX; i > wizardIndexX + 1; i--)
				{
					if (this->gamePieces[wizardIndexY][i - 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}
			//Right movement
			else if (attackIndexY == wizardIndexY && attackIndexX < wizardIndexX)
			{
				for (int i = attackIndexX; i < wizardIndexX - 1; i++)
				{
					if (this->gamePieces[wizardIndexY][i + 1]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
				}
			}

			//Up-right movement
			if (attackIndexX < wizardIndexX && attackIndexY > wizardIndexY)
			{
				for (int i = attackIndexY - 1; i > wizardIndexY; i--)
				{
					if (this->gamePieces[i][attackIndexX + counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;

					}
					counter++;
				}
			}
			//Up-left movement
			if (attackIndexX > wizardIndexX && attackIndexY > wizardIndexY)
			{
				for (int i = attackIndexY - 1; i > wizardIndexY; i--)
				{
					if (this->gamePieces[i][attackIndexX - counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
					counter++;
				}
			}

			//Down-right movement
			if (attackIndexX < wizardIndexX && attackIndexY < wizardIndexY)
			{
				for (int i = attackIndexY + 1; i < wizardIndexY; i++)
				{
					if (this->gamePieces[i][attackIndexX + counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
					counter++;
				}
			}
			//Down-left movement
			if (attackIndexX > wizardIndexX && attackIndexY < wizardIndexY)
			{
				for (int i = attackIndexY + 1; i < wizardIndexY; i++)
				{
					if (this->gamePieces[i][attackIndexX - counter]->getId() != EMPTY)
					{
						pieceInTheWay = true;
					}
					counter++;
				}
			}
		}
	}

	if (pieceInTheWay == true)
	{
		result = false;
		if (pieceAlreadyInPos != true)
		{
			if (this->gamePieces[attackIndexY][attackIndexX]->getTeam() == "White")
			{
				if (towerTemp != nullptr)
				{
					if (towerTemp->getIsChecking() == false)
					{
						towerTemp->setIsChecking(true);
						this->whiteCheckingPieces[nrOfWhiteCheckingPieces] = new Tower(*towerTemp);
						this->nrOfWhiteCheckingPieces++;
					}
				}
				if (bowmanTemp != nullptr)
				{
					if (bowmanTemp->getIsChecking() == false)
					{
						bowmanTemp->setIsChecking(true);
						this->whiteCheckingPieces[nrOfWhiteCheckingPieces] = new Bowman(*bowmanTemp);
						this->nrOfWhiteCheckingPieces++;
					}
				}
				if (queenTemp != nullptr)
				{
					if (queenTemp->getIsChecking() == false)
					{
						queenTemp->setIsChecking(true);
						this->whiteCheckingPieces[nrOfWhiteCheckingPieces] = new Queen(*queenTemp);
						this->nrOfWhiteCheckingPieces++;
					}
				}
			}

			if (this->gamePieces[attackIndexY][attackIndexX]->getTeam() == "Black")
			{
				if (towerTemp != nullptr)
				{
					if (towerTemp->getIsChecking() == false)
					{
						towerTemp->setIsChecking(true);
						this->blackCheckingPieces[nrOfBlackCheckingPieces] = new Tower(*towerTemp);
						this->nrOfBlackCheckingPieces++;
					}
				}
				if (bowmanTemp != nullptr)
				{
					if (bowmanTemp->getIsChecking() == false)
					{
						bowmanTemp->setIsChecking(true);
						this->blackCheckingPieces[nrOfBlackCheckingPieces] = new Bowman(*bowmanTemp);
						this->nrOfBlackCheckingPieces++;
					}
				}
				if (queenTemp != nullptr)
				{
					if (queenTemp->getIsChecking() == false)
					{
						queenTemp->setIsChecking(true);
						this->blackCheckingPieces[nrOfBlackCheckingPieces] = new Queen(*queenTemp);
						this->nrOfBlackCheckingPieces++;
					}
				}
			}
		}
	}
	if (pieceInTheWay == false && footmanTemp != nullptr && inRange == true && isPosible == true || pieceInTheWay == false && towerTemp != nullptr && isPosible == true || knightTemp != nullptr && isPosible == true || pieceInTheWay == false && bowmanTemp != nullptr && isPosible == true || pieceInTheWay == false && queenTemp != nullptr && isPosible == true)
	{
		result = true;

		if (pieceAlreadyInPos != true)
		{
			if (this->gamePieces[attackIndexY][attackIndexX]->getTeam() == "White")
			{
				if (towerTemp != nullptr)
				{
					if (towerTemp->getIsChecking() == false)
					{
						towerTemp->setIsChecking(true);
						this->whiteCheckingPieces[nrOfWhiteCheckingPieces] = new Tower(*towerTemp);
						this->nrOfWhiteCheckingPieces++;
					}
				}
				if (bowmanTemp != nullptr)
				{
					if (bowmanTemp->getIsChecking() == false)
					{
						bowmanTemp->setIsChecking(true);
						this->whiteCheckingPieces[nrOfWhiteCheckingPieces] = new Bowman(*bowmanTemp);
						this->nrOfWhiteCheckingPieces++;
					}
				}
				if (queenTemp != nullptr)
				{
					if (queenTemp->getIsChecking() == false)
					{
						queenTemp->setIsChecking(true);
						this->whiteCheckingPieces[nrOfWhiteCheckingPieces] = new Queen(*queenTemp);
						this->nrOfWhiteCheckingPieces++;
					}
				}
			}

			if (this->gamePieces[attackIndexY][attackIndexX]->getTeam() == "Black")
			{
				if (towerTemp != nullptr)
				{
					if (towerTemp->getIsChecking() == false)
					{
						towerTemp->setIsChecking(true);
						this->blackCheckingPieces[nrOfBlackCheckingPieces] = new Tower(*towerTemp);
						this->nrOfBlackCheckingPieces++;
					}
				}
				if (bowmanTemp != nullptr)
				{
					if (bowmanTemp->getIsChecking() == false)
					{
						bowmanTemp->setIsChecking(true);
						this->blackCheckingPieces[nrOfBlackCheckingPieces] = new Bowman(*bowmanTemp);
						this->nrOfBlackCheckingPieces++;
					}
				}
				if (queenTemp != nullptr)
				{
					if (queenTemp->getIsChecking() == false)
					{
						queenTemp->setIsChecking(true);
						this->blackCheckingPieces[nrOfBlackCheckingPieces] = new Queen(*queenTemp);
						this->nrOfBlackCheckingPieces++;
					}
				}
			}
		}
	}

	return result;
}
bool Game::checkCheckingPieces(int wizardIndexX, int wizardIndexY, int attackIndexX, int attackIndexY, bool canPieceMakeAMove)
{
	bool result = false;
	bool isPosible = false;
	Tower* towerTemp = nullptr;
	Bowman* bowmanTemp = nullptr;
	Queen* queenTemp = nullptr;

	int indexNoLongerChecking[32];
	int nrOfPiecesNoLongerChecking = 0;


	towerTemp = dynamic_cast<Tower*>(this->gamePieces[attackIndexY][attackIndexX]);
	bowmanTemp = dynamic_cast<Bowman*>(this->gamePieces[attackIndexY][attackIndexX]);
	queenTemp = dynamic_cast<Queen*>(this->gamePieces[attackIndexY][attackIndexX]);

	if (this->gamePieces[wizardIndexY][wizardIndexX]->getTeam() == "Black")
	{
		for (int i = 0; i < this->nrOfWhiteCheckingPieces && result == false; i++)
		{

			if (this->wizardInCheck(wizardIndexX, wizardIndexY, (this->whiteCheckingPieces[i]->getX() - 100) / 100, (this->whiteCheckingPieces[i]->getY() - 100) / 100, true) == true)
			{
				result = true;
			}
			else
			{
				indexNoLongerChecking[nrOfPiecesNoLongerChecking] = i;
				nrOfPiecesNoLongerChecking++;
			}
		}
		if (result == false)
		{
			if (canPieceMakeAMove == false)
			{
				for (int i = 0; i < nrOfPiecesNoLongerChecking; i++)
				{
					if (towerTemp != nullptr)
					{
						isPosible = towerTemp->canMakeThatMove((this->whiteCheckingPieces[i]->getX() - 100) / 100, wizardIndexX, (this->whiteCheckingPieces[i]->getY() - 100) / 100, wizardIndexY);
					}
					if (bowmanTemp != nullptr)
					{
						isPosible = bowmanTemp->canMakeThatMove((this->whiteCheckingPieces[i]->getX() - 100) / 100, wizardIndexX, (this->whiteCheckingPieces[i]->getY() - 100) / 100, wizardIndexY);
					}
					if (queenTemp != nullptr)
					{
						isPosible = queenTemp->canMakeThatMove((this->whiteCheckingPieces[i]->getX() - 100) / 100, wizardIndexX, (this->whiteCheckingPieces[i]->getY() - 100) / 100, wizardIndexY);
					}

					if (isPosible == false)
					{
						if (towerTemp != nullptr)
						{
							towerTemp->setIsChecking(false);
						}
						if (bowmanTemp != nullptr)
						{
							bowmanTemp->setIsChecking(false);
						}
						if (queenTemp != nullptr)
						{
							queenTemp->setIsChecking(false);
						}
						delete this->whiteCheckingPieces[indexNoLongerChecking[i]];
						this->whiteCheckingPieces[indexNoLongerChecking[i]] = this->whiteCheckingPieces[indexNoLongerChecking[i] + 1];
						this->nrOfWhiteCheckingPieces--;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < this->nrOfBlackCheckingPieces && result == false; i++)
		{
			if (this->wizardInCheck(wizardIndexX, wizardIndexY, (this->blackCheckingPieces[i]->getX() - 100) / 100, (this->blackCheckingPieces[i]->getY() - 100) / 100, true) == true)
			{
				result = true;
			}
			else
			{
				indexNoLongerChecking[nrOfPiecesNoLongerChecking] = i;
				nrOfPiecesNoLongerChecking++;
			}
		}
		if (result == false)
		{
			if (canPieceMakeAMove == false)
			{
				for (int i = 0; i < nrOfPiecesNoLongerChecking; i++)
				{
					if (towerTemp != nullptr)
					{
						isPosible = towerTemp->canMakeThatMove((this->blackCheckingPieces[indexNoLongerChecking[i]]->getX() - 100) / 100, wizardIndexX, (this->blackCheckingPieces[indexNoLongerChecking[i]]->getY() - 100) / 100, wizardIndexY);
					}
					if (bowmanTemp != nullptr)
					{
						isPosible = bowmanTemp->canMakeThatMove((this->blackCheckingPieces[indexNoLongerChecking[i]]->getX() - 100) / 100, wizardIndexX, (this->blackCheckingPieces[indexNoLongerChecking[i]]->getY() - 100) / 100, wizardIndexY);
					}
					if (queenTemp != nullptr)
					{
						isPosible = queenTemp->canMakeThatMove((this->blackCheckingPieces[indexNoLongerChecking[i]]->getX() - 100) / 100, wizardIndexX, (this->blackCheckingPieces[indexNoLongerChecking[i]]->getY() - 100) / 100, wizardIndexY);
					}

					if (isPosible == false)
					{
						if (towerTemp != nullptr)
						{
							towerTemp->setIsChecking(false);
						}
						if (bowmanTemp != nullptr)
						{
							bowmanTemp->setIsChecking(false);
						}
						if (queenTemp != nullptr)
						{
							queenTemp->setIsChecking(false);
						}
						delete this->blackCheckingPieces[indexNoLongerChecking[i]];
						this->blackCheckingPieces[indexNoLongerChecking[i]] = this->blackCheckingPieces[indexNoLongerChecking[i] + 1];
						this->nrOfBlackCheckingPieces--;					
					}
				}
				
			}
		}
	}


	return result;
}

bool Game::checkmateCheck(int wizardIndexX, int wizardIndexY, int attackIndexX, int attackIndexY)
{
	bool result = false;

	Piece* pieceTemp;
	
	bool isCheckmate = true;

	float pieceX = 0.0;
	float pieceY = 0.0;
	int thePieceId = 0;
	int indexY = 0;
	int indexX = 0;

	for (int i = 0; i < this->BOARDCAP; i++)
	{
		for (int j = 0; j < this->BOARDCAP; j++)
		{
			pieceX = this->gamePieces[i][j]->getX();
			pieceY = this->gamePieces[i][j]->getY();
			thePieceId = this->gamePieces[i][j]->getId();
			indexY = i;
			indexX = j;

			for (int n = 0; n < this->BOARDCAP; n++)
			{
				for (int m = 0; m < this->BOARDCAP; m++)
				{
					if (this->gamePieces[i][j]->getId() != EMPTY && this->gamePieces[i][j]->getId() != WIZARD && this->gamePieces[wizardIndexY][wizardIndexX]->getTeam() == this->gamePieces[i][j]->getTeam() && this->checkIfPossible(pieceX, pieceY, this->gamePieces[n][m]->getX(), this->gamePieces[n][m]->getY(), thePieceId, indexX, indexY, m, n) != false)
					{
						pieceTemp = this->gamePieces[i][j];
						this->gamePieces[i][j] = this->gamePieces[n][m];
						this->gamePieces[n][m] = pieceTemp;

						this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
						this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

						this->gamePieces[i][j]->setX(pieceX);
						this->gamePieces[i][j]->setY(pieceY);

						if (this->gamePieces[wizardIndexY][wizardIndexX]->getTeam() == "White")
						{
							if (this->gamePieces[n][m]->getId() == EMPTY || this->gamePieces[n][m]->getId() != EMPTY && this->gamePieces[n][m]->getTeam() == "White")
							{
								this->whiteCheck = this->wizardInCheck(wizardIndexX, wizardIndexY, attackIndexX, attackIndexY, true);
								if (this->whiteCheck == false)
								{
									isCheckmate = false;
								}
								this->whiteCheck = true;
							}
						}
						if (this->gamePieces[wizardIndexY][wizardIndexX]->getTeam() == "Black")
						{
							if (this->gamePieces[n][m]->getId() == EMPTY || this->gamePieces[n][m]->getId() != EMPTY && this->gamePieces[n][m]->getTeam() == "Black")
							{
								this->blackCheck = this->wizardInCheck(wizardIndexX, wizardIndexY, attackIndexX, attackIndexY, true);
								if (this->blackCheck == false)
								{
									isCheckmate = false;
								}
								this->blackCheck = true;
							}
						}

						pieceTemp = this->gamePieces[i][j];
						this->gamePieces[i][j] = this->gamePieces[n][m];
						this->gamePieces[n][m] = pieceTemp;

						this->gamePieces[n][m]->setX(this->gamePieces[i][j]->getX());
						this->gamePieces[n][m]->setY(this->gamePieces[i][j]->getY());

						this->gamePieces[i][j]->setX(pieceX);
						this->gamePieces[i][j]->setY(pieceY);
					}
				}
			}
		}
	}
	if (gamePieces[wizardIndexY][wizardIndexX]->getTeam() == "White")
	{
		if (isCheckmate == false)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}
	if (gamePieces[wizardIndexY][wizardIndexX]->getTeam() == "Black")
	{
		if (isCheckmate == false)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}
	
	return result;
}