#pragma once

#include <cstdlib>
#include <iostream>

struct node
{
	int data;
	node *next;
};

class OneWayList
{
private:
	node *head, *tail;
public:
	OneWayList();
	~OneWayList();
	bool isEmpty();
	void createnode(int value);
	void display();
	void insert_start(int value);
	void insert_position(int pos, int value);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
};

