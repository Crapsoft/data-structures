#pragma once
#include "OneWayList.h"
using namespace std;
struct node2
{
	int data;
	node2 *next;
};

class Stack
{
private:
	node2* top;
	int size;
public:
	Stack();
	~Stack();
	void push(int el);
	int pop();
	int getSize();
	int getTop();
	bool isempty();
};

