#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"
#include <iostream>
#include <crtdbg.h>
#include <fstream>

int main()
{
	//SPARAR INTE SCHACKANDE PJÄSER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(800, 800), "Magic Chess");
	Board theBoard;
	theBoard.loadBoard();
	Game theGame(theBoard);
	int savedPiece = 0;
	string team = "";
	bool whitesTurn = false;

	sf::Music bgMusic;

	if (!bgMusic.openFromFile("../assets/music/aCelticLore.ogg"))
	{
		cout << "Can't load music file" << endl;
	}

	sf::Clock gameTime;

	bgMusic.play();
	bgMusic.setLoop(true);

	ifstream inFile;

	inFile.open("../assets/save.txt");

	if (inFile.is_open())
	{
		inFile >> whitesTurn;
		theGame.setWhitePlayersTurn(whitesTurn);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				inFile >> savedPiece;
				theGame.setLogicBoard(j, i, savedPiece);

				inFile.ignore();
				inFile >> team;
				theGame.savedGamePieces(j, i, team);
			}
		}
		theGame.setSpriteBoard();
	}
	inFile.close();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				ofstream outFile;
				outFile.open("../assets/save.txt");

				outFile << theGame.save();

				outFile.close();
				if (theGame.gameOver() == true)
				{
					if (remove("../assets/save.txt") != 0)
					{
						perror("Error deleting file");
					}
					else
					{
						puts("File successfully deleted");
					}
				}
				window.close();
			}

		}
		theGame.update(gameTime.restart().asSeconds(), window);
		window.clear();
		window.draw(theGame);
		window.display();


	}
	return 0;
}