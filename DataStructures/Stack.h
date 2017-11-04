#pragma once
#include "OneWayList.cpp"
#include <exception>
using namespace std;

template <typename T>
class Stack
{
private:
	node<T>* top;
	int size;
public:
	Stack();
	~Stack();
	void push(T el);
	T pop();
	int getSize();
	T getTop();
	bool isempty();
};

