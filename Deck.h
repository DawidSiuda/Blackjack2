#pragma once
#include "CardColor.cpp"
#include "CardFigure.cpp"
#include "PlayingCard.h"
#include "LinkedList.h"

#include <cstdlib>
#include <ctime>


using namespace std;

class Deck
{
public:
	PlayingCard getCard();//rand card from deck of cards and give it in return, secectded card is delete from list
	bool isEmpty();
	bool cardShuffle();
	void showDeck();
	Deck(unsigned short numberOfDeckCard = 1);
	~Deck();
private:
	LinkedList *listOfCard;
	 unsigned short numberOfDeck;
};

