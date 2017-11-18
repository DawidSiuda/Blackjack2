#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class GenText
{
public:
	void show(RenderWindow *window, int number, string words);
	void show(RenderWindow *window, string words, int number);
	void show(RenderWindow *window, string words);
	void show(RenderWindow *window, int tre);
	void show(RenderWindow *window);

	GenText(wstring countent ,int x, int y, int size, Color color = Color(255, 255, 255), string font = "Arial.ttf");
	GenText(string countent, int x, int y, int size, Color color = Color(255, 255, 255), string font = "Draconian.ttf");
	~GenText();
private:
	Font font;
	Text text;
};

