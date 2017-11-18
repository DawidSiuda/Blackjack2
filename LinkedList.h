#pragma once
#include "PlayingCard.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void getElements(bool getOnConsole = false);//show all cards in console
	PlayingCard getCard(int numberOfCard);//select card from deck of cards and give it in return
	void addElement(PlayingCard *data);
	unsigned int getLength(bool onConsole = false);
	bool delElement(int index);

private:
	class Node
	{
	public:
		Node* next;
		Node* previous;
		PlayingCard *data;
	};

	int length;
	Node* head;
	Node* back;
};
