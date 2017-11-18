#pragma once
#include "CardColor.cpp"
#include "CardFigure.cpp"

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayingCard
{
public:
	CardColor getColor();
	CardFigure getFigure();
	std::string getName();
	void drawThisCard(int x, int y, RenderWindow *window);
	PlayingCard(int setFigure,int setColor);
	PlayingCard(CardFigure setFigure, CardColor setColor);
	
	PlayingCard();
	~PlayingCard();

private:
	Font font;
	Texture mybackgroundTexture;
	Image _backgrountImage;
	Text value;
	RectangleShape paintedCard;
	CardColor color;
	CardFigure figure;
};

