#include "WindowOfPlay.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

void main()
{
	RenderWindow myWindow(VideoMode(1136, 640), "BlackJack");// tworzy okno
	RectangleShape background;
	RectangleShape backgroundSecondLevel;
	Texture texture;
	Event event;
	GenText title("BlackJack", 80, 50, 110);
	GenText menu("Press X to start game",200, 250, 50);
	GenText aboutMe("Dawid Siuda", 1050, 610, 10 , Color(200, 200,  200), "arial.ttf");
	GenText loading("Loading...", 480, 280, 30);

	/////////////////////////////////////////////////
	//set attribute of window
	myWindow.setFramerateLimit(60); // limit FPS 60
	myWindow.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow¹

	/////////////////////////////////////////////////
	//set attribute of background 
	texture.loadFromFile("table.png");
	background.setTexture(&texture);
	background.setPosition(Vector2f(0, 0));
	background.setSize(Vector2f(1136, 640));
	backgroundSecondLevel.setPosition(Vector2f(0, 0));
	backgroundSecondLevel.setSize(Vector2f(1136, 640));
	backgroundSecondLevel.setFillColor(Color(0, 0, 0, 70));

	

	while (myWindow.isOpen())
	{


		while (myWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case (Event::Closed):
				{
					myWindow.close();
				}
				case (Event::KeyPressed):
				{
					switch (event.key.code)
					{
						case(Keyboard::X):
						{
							
							///////////////////////////////////////////////
							//loading window
							myWindow.draw(background);
							loading.show(&myWindow);
							myWindow.display();

							WindowOfPlay windowOfPlay(&myWindow);
							windowOfPlay.play();
						}
					}
				}
			}
		}


		myWindow.draw(background);
		myWindow.draw(backgroundSecondLevel);
		title.show(&myWindow);
		menu.show(&myWindow);
		aboutMe.show(&myWindow);

		myWindow.display();
	}
}