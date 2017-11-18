#include "WindowOfPlay.h"

WindowOfPlay::WindowOfPlay(RenderWindow *handleToRenderWindow):
	textForGameOver("GameOver", 300, 110, 140),
	IItextForGameOver("Press X to exit", 360, 320, 60)	
{
	mainWindow = handleToRenderWindow;
	backgroundForGameOver.setFillColor(Color(0, 0, 0, 150));
	backgroundForGameOver.setSize(Vector2f(1136, 640));
	loadMap();
	myDeck = new Deck(1);
	
}

void WindowOfPlay::giveSomethink()
{
	printf("--------nothing--------\n");
}

Sprite WindowOfPlay::loadMap(string addres )
{
	tableTexture.loadFromFile(addres);
	backgrounfPicture.setTexture(tableTexture);
	backgrounfPicture.setPosition(Vector2f(0,0));

	return backgrounfPicture;
}


int WindowOfPlay::whoIsTheWinner()
{
	if (player.getPoints() > 21 && croupierPlayer.getPoints() > 21)
	{
			return 3;		
	}else
	if (player.getPoints() > 21 && croupierPlayer.getPoints() <= 21)
	{
			return 2;	
	}else
	if (player.getPoints() <= 21 && croupierPlayer.getPoints() > 21)
	{
			return 1;
	}else
	if(player.getPoints() > croupierPlayer.getPoints())
	{
		return 1;
	}else
	if(player.getPoints() == croupierPlayer.getPoints())
	{
		return 3;
	}else
	if (player.getPoints() < croupierPlayer.getPoints())
	{
		return 2;
	}
	else
	{
		std::cout << "ERROR: game can't chose the winner" << endl;
		return 5;
	}
	return 0;
}


short WindowOfPlay::play()
{

	int sumOfFrames=0;
	int temp = 0;
	int timeToWait = 0;

	Event event;
	Clock clock;
	

	GenText drawYourScore("Your Score: ", 100, 250, 40);
	GenText drawCroupierScore("Croupier score: ", 800, 250, 40);
	GenText textMoneyPool("", 500, 260, 25);
	GenText playersMoney("", 50, 570, 30);
	GenText keysMessage("", 420, 560, 40, Color(255, 255, 255), "Queen of Clubs.otf");
	

	int money;
	int moneyPool;

	bool flag_wait = false;
	bool flag_getCard = false;
	bool flag_setMoney = false;
	bool flag_computersTour = false;
	bool flag_firstTourOfCroupier= false;
	bool flag_playersTour = false;
	bool flag_firstTourOfPlayer = false;
	bool flag_playerMoreThan21p = false;
	bool flag_croupierSecondTour = false;
	bool flag_croupierLessThan17p = false;
	bool flag_croupierMoreThan17p = false;
	bool flag_showScore = false;
	bool flag_endOfGame = false;
	bool flag_playerWon = false;
	bool flag_gameOver = false;


	///////////////////////////////////////////////
	//set started flags
	flag_croupierLessThan17p = true;
	flag_setMoney = true;

	money = 2500;
	moneyPool = 0;

	/*
		std::cout << "flag_wait:----------------" << flag_wait <<
					"\nflag_getCard:-------------" << flag_getCard <<
					"\nflag_setMoney:------------" << flag_setMoney <<
					"\nflag_computersTour:-------" << flag_computersTour <<
					"\nflag_firstTourOfCroupier:-" << flag_firstTourOfCroupier <<
					"\nflag_playersTour:---------" << flag_playersTour <<
					"\nflag_firstTourOfPlayer:---" << flag_firstTourOfPlayer <<
					"\nflag_playerMoreThan21p:---" << flag_playerMoreThan21p <<
					"\nflag_croupierLessThan17p:-" << flag_croupierLessThan17p <<
					"\nflag_croupierMoreThan17p:-" << flag_croupierMoreThan17p
					<< std::endl;
	*/
	
	while (mainWindow->isOpen())
	{
		while (mainWindow->pollEvent(event))// event loop
		{
			switch (event.type)
			{
				case (Event::Closed):
				{
					mainWindow->close();
				}
				case (Event::KeyPressed):
				{
					switch (event.key.code)
					{
						case(Keyboard::X):
						{
							giveSomethink();
							return 0;
							break;
						}
						case(Keyboard::Space): //players get card
						{
							if (flag_setMoney && moneyPool == 0)
							{
								if (money >= 100)
								{
									moneyPool += 100;
									money -= 100;
								}
							}else
							if (flag_setMoney && moneyPool != 0)
							{
								if (money >= 100)
								{
									moneyPool += 100;
									money -= 100;
								}
							}else
							if (flag_playersTour && !flag_playerMoreThan21p)
							{
								flag_playersTour = false;
								flag_computersTour = true;
							}else
							if (flag_endOfGame)
							{
								
								switch (whoIsTheWinner())
								{
								case 1:
									money += moneyPool * 2;
									moneyPool = 0;
									break;
								case 2:
									moneyPool = 0;
									break;
								case 3:
									money += moneyPool;
									moneyPool = 0;
									break;
								}
								
								if (money == 0)
								{
									flag_gameOver = true;
								}

								player.loseAllCard();
								croupierPlayer.loseAllCard();

								flag_wait = true;
								clock.restart();
								timeToWait = 600;

								flag_playerWon = false;
								flag_wait = false;
								flag_getCard = false;
								flag_setMoney = true;
								flag_computersTour = false;
								flag_firstTourOfCroupier = false;
								flag_playersTour = false;
								flag_firstTourOfPlayer = false;
								flag_playerMoreThan21p = false;
								flag_croupierLessThan17p = true;
								flag_showScore = false;
								flag_endOfGame = false;
								flag_croupierSecondTour = false;
							}
							break;
						}
						case(Keyboard::Return): //players get card
						{
							if (flag_setMoney && moneyPool != 0)
							{
								flag_setMoney = false;
								flag_computersTour = true;
								flag_firstTourOfCroupier = true;
								flag_showScore = true;

								flag_wait = true;
								clock.restart();
								timeToWait = 400;
							}else
							if (flag_playersTour && !flag_playerMoreThan21p)
							{
								player.giveCard(myDeck->getCard());
								if (player.getPoints() > 21)
								{
									flag_playerMoreThan21p = true;
									flag_wait = true;
									clock.restart();
									timeToWait = 400;
								}
							}
							break;
						}
						case(Keyboard::C): // show all players card in console
						{
							player.showCards();
							std::cout <<" -------------------- - "<< std::endl;
							std::cout << "point: "<< player.getPoints() << std::endl;
							break;

						}
					}
				}
				case(Event::MouseButtonPressed)://mouse, left button
				{
					std::cout << Mouse::getPosition(*mainWindow).x << " " << Mouse::getPosition(*mainWindow).y << std::endl;
					break;
				}
			}
		}

		/////////////////////////////////////////////////
		//draw background
		mainWindow->draw(backgrounfPicture);

		/////////////////////////////////////////////////
		//AI of game

		if(flag_wait == false && flag_gameOver == false)
		{ 
			if(flag_setMoney && moneyPool ==0 )
			{
				keysMessage.show(mainWindow, "SPACE:  give money");
			}
			else
			if (flag_setMoney && moneyPool != 0)
			{
				keysMessage.show(mainWindow, "SPACE:  give money	ENTER: deal");

			}
			if (flag_computersTour && flag_firstTourOfCroupier)
			{
				//std::cout << "im here 2 " << std::endl;

				croupierPlayer.giveCard(myDeck->getCard());

				flag_computersTour = false;
				flag_firstTourOfCroupier = false;
				flag_croupierSecondTour = true;

				flag_playersTour = true;
				flag_firstTourOfPlayer = true;

				flag_wait = true;
				clock.restart();
				timeToWait = 400;
			}
			else
			if (flag_playersTour && flag_firstTourOfPlayer)
			{
				//std::cout << "im here 3" << std::endl;

				player.giveCard(myDeck->getCard());
				
				flag_playersTour = true;
				flag_firstTourOfPlayer = false;
				
				
			}
			else
			if (flag_croupierSecondTour && flag_playerMoreThan21p)
			{
				croupierPlayer.giveCard(myDeck->getCard());

				flag_endOfGame = true;
				flag_croupierSecondTour = false;
				flag_playersTour = false;
			}else
			if (flag_playersTour && !flag_playerMoreThan21p)
			{
			
				
				//std::cout << "im here 5 " << std::endl;
				keysMessage.show(mainWindow, "SPACE: stand	     ENTER: hit");
			}
			else
			if (flag_playersTour && flag_playerMoreThan21p && !flag_getCard)
			{
				//std::cout << "im here 6 " << std::endl;
			}
			else
			if (flag_playersTour && flag_playerMoreThan21p && flag_getCard)
			{
				//std::cout << "im here 7" << std::endl;
			}
			else
			if (flag_computersTour && flag_croupierLessThan17p && !flag_firstTourOfCroupier)
			{
				//std::cout << "im here 8" << std::endl;

				croupierPlayer.giveCard(myDeck->getCard());

				if(croupierPlayer.getPoints() >=17)
				{
					flag_croupierLessThan17p = false;
					flag_computersTour = false;
					flag_endOfGame = true;
				}
				
				flag_wait = true;
				clock.restart();
				timeToWait = 500;
			}
			else
			if (flag_endOfGame)
			{
				//std::cout << "im here 9" << std::endl;
				keysMessage.show(mainWindow, "Press SPACE to continue");
			}
		}
		else
		{
			if (clock.getElapsedTime().asMilliseconds() > timeToWait)
			{
				flag_wait = false;
				timeToWait = 0;
			}
		}

		//////////////////////////////////////////////////////////////
		//end of desk
		if (myDeck->isEmpty() == true)
		{
			myDeck->cardShuffle();
		}

		//////////////////////////////////////////////////////////////
		//write texts no frame
		if (flag_showScore)
		{
			drawYourScore.show(mainWindow, "Your score: ", player.getPoints());
			drawCroupierScore.show(mainWindow, "Croupier score: ", croupierPlayer.getPoints());
		}
		textMoneyPool.show(mainWindow, "Pool:", moneyPool);
		playersMoney.show(mainWindow, "Money:", money);

		//////////////////////////////////////////////////////////////
		//draw cards
		player.drawCards(110,310, mainWindow, BUTTOM);
		croupierPlayer.drawCards(1000, 30, mainWindow, TOP);

		//////////////////////////////////////////////////////////////
		//draw frame for GameOver 
		if (flag_gameOver)
		{
			mainWindow->draw(backgrounfPicture);
			mainWindow->draw(backgroundForGameOver);
			textForGameOver.show(mainWindow);
			IItextForGameOver.show(mainWindow);
		}

		//////////////////////////////////////////////////////////////
		//display frame
		mainWindow->display();
	}
	
	return 0;
}

WindowOfPlay::~WindowOfPlay()
{
	delete myDeck;
}
