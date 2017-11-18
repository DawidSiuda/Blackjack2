#pragma once
#include "WindowOfPlay.h"
#include "PlayingCard.h"
#include "Deck.h"
#include "Player.h"
#include "GenText.h"
#include "constVairable.cpp"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class WindowOfPlay
{
public:
	
	short play();	
	RenderWindow *mainWindow;
	Deck *myDeck;
	void giveSomethink();// usun¹æ 

	WindowOfPlay(RenderWindow *handleToRenderWindow);
	~WindowOfPlay();


private:

	PlayingCard computersCard[22];
	unsigned short numberOfPlayersCard;
	unsigned short numberOfComputersCard;

	Player croupierPlayer;
	Player player;

	Texture tableTexture;

	Sprite backgrounfPicture;
	Sprite loadMap(string addres = "table.png");

	RectangleShape backgroundForGameOver;

	GenText textForGameOver;
	GenText IItextForGameOver;

	int whoIsTheWinner();
};

