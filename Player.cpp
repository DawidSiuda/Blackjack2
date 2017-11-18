#include "Player.h"

void Player::giveCard(PlayingCard card)
{
	if (numberOfCards >= 22)
	{
		std::cout << "ERROR: player have too many cards" << std::endl;
		return;
	}
	playersCard[numberOfCards++] = card;

}

void Player::loseAllCard()
{
	numberOfCards = 0;
}

void Player::showCards()
{
	for (int i = 0; i< numberOfCards; i++)
		std::cout << playersCard[i].getName() << std::endl;
}

int Player::getPoints()
{
	int sum = 0;
	for (int i = 0; i < numberOfCards; i++)
	{
		switch (playersCard[i].getFigure())
		{
		case _2:
			sum += 2;
			break;
		case _3:
			sum += 3;
			break;
		case _4:
			sum += 4;
			break;
		case _5:
			sum += 5;
			break;
		case _6:
			sum += 6;
			break;
		case _7:
			sum += 7;
			break;
		case _8:
			sum += 8;
			break;
		case _9:
			sum += 9;
			break;
		case _10:
			sum += 10;
			break;
		case _J:
		case _Q:
		case _K:
			sum += 10;
			break;
		case _A:
			sum += 11;
			break;
		}

	}
	return sum;
}

PlayingCard * Player::getCardTable()
{
	return playersCard;
}

unsigned short Player::getNumberOfCards()
{
	return numberOfCards;
}

void Player::drawCards(int x, int y, RenderWindow * currentWindow, bool topOrBottom)
{
	/*Texture backgroundTexture;
	Texture shapeTexture;
	Sprite paintedCard;*/
	int firstX = x, firstY = y;
	
	if (topOrBottom == BUTTOM)
	{
		for (int i = 0; i < numberOfCards; i++)
		{
			playersCard[i].drawThisCard(x, y, currentWindow);
			x += 120;
			if (i % 7 == 0 && i > 2)
			{
				x = firstX + 30;
				firstX = x;
				y += 30;
			}
		}
	}
	if (topOrBottom == TOP)
	{
			for (int i = 0; i < numberOfCards; i++)
			{
				playersCard[i].drawThisCard(x, y, currentWindow);
				x -= 120;
				if (i % 7 == 0 && i > 2)
				{
					x = firstX - 90;
					firstX = x;
					y += 30;
				}
			}
		
	}
}
	
Player::Player()
{
	numberOfCards = 0;
}

Player::~Player()
{
}
