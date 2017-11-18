#include "Deck.h"

PlayingCard Deck::getCard()
{
	PlayingCard selectedCard;
	int numberOfSelectedCard;

	numberOfSelectedCard = (std::rand() % listOfCard->getLength(false) ) ;

	try
	{
		selectedCard = listOfCard->getCard(numberOfSelectedCard);
		listOfCard->delElement(numberOfSelectedCard);
	}
	catch(int error)
	{
		std::cout << "ERROR::number of selected card is huge" << std::endl;
		int errorCode = 2;
		throw errorCode;
	}
	return selectedCard;
}

bool Deck::isEmpty()
{
	if (listOfCard->getLength(false) == 0)
		return true;
	else
		return false;
}

bool Deck::cardShuffle()
{
	delete listOfCard;


	numberOfDeck = numberOfDeck;
	listOfCard = new LinkedList();

	for (int i = 0; i < numberOfDeck; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 2; k < 15; k++)
			{
				PlayingCard *cad = new PlayingCard(k, j);
				listOfCard->addElement(cad);
			}
		}
	}
	return false;
}

void Deck::showDeck()
{
	listOfCard->getElements(true);
}

Deck::Deck(unsigned short numberOfDeckCard )
{
	if (numberOfDeckCard < 1)
		numberOfDeckCard = 1;

	srand(time(NULL));
	numberOfDeck = numberOfDeckCard;
	listOfCard = new LinkedList();

	for (int i = 0; i < numberOfDeckCard; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 2; k < 15; k++)
			{
				PlayingCard *cad = new PlayingCard(k, j);
				listOfCard->addElement(cad);
			}
		}
	}
	listOfCard->getElements();
}

Deck::~Deck()
{
	delete listOfCard;
}
