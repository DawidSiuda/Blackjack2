#include "GenText.h"

void GenText::show(RenderWindow * window, int number, string words)
{
	string score = to_string(number) + words;
	text.setString(score);
	window->draw(text);
}

void GenText::show(RenderWindow * window, string words, int number)
{
	string score = words + to_string(number);
	text.setString(score);
	window->draw(text);
}

void GenText::show(RenderWindow *window, string words)
{
	text.setString(words);
	window->draw(text);
}

void GenText::show(RenderWindow *window, int chars)
{
	string score = to_string(chars);
	text.setString(score);
	window->draw(text);
}

void GenText::show(RenderWindow *window)
{
	window->draw(text);
}

GenText::GenText(wstring countent,int x, int y, int size, Color color, string newFont)
{
	if (!font.loadFromFile(newFont))
	{
		std::cout << "ERROR: class:GetText font not found" << std::endl;
	}

	text.setFont(font);
	text.setCharacterSize(size);
	text.setPosition(Vector2f(x, y));
	text.setFillColor(color);
	text.setString(countent);
}

GenText::GenText(string countent, int x, int y, int size, Color color, string newFont)
{
	if (!font.loadFromFile(newFont))
	{
		std::cout << "ERROR: class:GetText font not found" << std::endl;
	}

	text.setFont(font);
	text.setCharacterSize(size);
	text.setPosition(Vector2f(x, y));
	text.setFillColor(color);
	text.setString(countent);
}

GenText::~GenText()
{
}
