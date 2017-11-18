#include "PlayingCard.h"

CardColor PlayingCard::getColor()
{
	return color;
}

CardFigure PlayingCard::getFigure()
{
	return figure;
}

std::string PlayingCard::getName()
{
	std::string name;

	switch (color)
	{
	case HEARTS:
		name = "serce ";
		break;
	case TILES:
		name = "karo ";
		break;
	case CLOVERS:
		name = "trefl ";
		break;
	case PICKES:
		name = "pik ";
		break;
	}

	switch (figure)
	{
	case _2:
		name += "_2";
		break;
	case _3:
		name += "_3";
		break;
	case _4:
		name += "_4";
		break;
	case _5:
		name += "_5";
		break;
	case _6:
		name += "_6";
		break;
	case _7:
		name += "_7";
		break;
	case _8:
		name += "_8";
		break;
	case _9:
		name += "_9";
		break;
	case _10:
		name += "_10";
		break;
	case _J:
		name += "_J";
		break;
	case _Q:
		name += "_Q";
		break;
	case _K:
		name += "_K";
		break;
	case _A:
		name += "_A";
		break;
	}
	return name;
}

void PlayingCard::drawThisCard(int x, int y, RenderWindow * window)
{
	paintedCard.setPosition(Vector2f(x, y));
	paintedCard.setTexture(&mybackgroundTexture);
	value.setPosition(Vector2f(x + 8, y + 8));
	window->draw(paintedCard);
	window->draw(value);
}

PlayingCard::PlayingCard(int setFigure, int setColor):PlayingCard(CardFigure(setFigure), CardColor(setColor))
{
	
}

PlayingCard::PlayingCard(CardFigure setFigure, CardColor setColor)
{
	color = setColor;
	figure = setFigure;

	Texture tempBackgroundTexture;
	tempBackgroundTexture.loadFromFile("TwhiteBack.png");

	Texture colorTexture;

	switch (color)
	{
	case HEARTS:
		colorTexture.loadFromFile("_heart.png");
		break;
	case TILES:
		colorTexture.loadFromFile("_karo.png");
		break;
	case CLOVERS:
		colorTexture.loadFromFile("_trefl.png");
		break;
	case PICKES:
		colorTexture.loadFromFile("_pik.png");
		break;
	}

	RenderTexture newTexture;

	Sprite backgrountImage(tempBackgroundTexture);
	Sprite color(colorTexture);

	newTexture.create(105, 150);
	newTexture.clear(Color::Transparent);

	newTexture.draw(backgrountImage);
	newTexture.draw(color);

	mybackgroundTexture = newTexture.getTexture();	
	
	paintedCard.setTexture(&mybackgroundTexture);
	paintedCard.setSize(Vector2f(105, 150));
	
	std::string nameOfCard;
	switch (figure)
	{
	case _2:
		nameOfCard = "2";
		break;
	case _3:
		nameOfCard = "3";
		break;
	case _4:
		nameOfCard = "4";
		break;
	case _5:
		nameOfCard = "5";
		break;
	case _6:
		nameOfCard = "6";
		break;
	case _7:
		nameOfCard = "7";
		break;
	case _8:
		nameOfCard = "8";
		break;
	case _9:
		nameOfCard = "9";
		break;
	case _10:
		nameOfCard = "10";
		break;
	case _J:
		nameOfCard = "J";
		break;
	case _Q:
		nameOfCard = "Q";
		break;
	case _K:
		nameOfCard = "K";
		break;
	case _A:
		nameOfCard = "A";
		break;
	}

	font.loadFromFile("CARDC___.TTF");
	value.setFont(font);
	value.setCharacterSize(40);
	value.setStyle(Text::Bold);
	value.setFillColor(Color::Black);
	value.setString(nameOfCard);
	
	
}

PlayingCard::PlayingCard()
{
	PlayingCard(0,0);
}

PlayingCard::~PlayingCard()
{
}
