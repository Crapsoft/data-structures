#pragma once
#include "OneWayList.cpp"

template <class T>
class Queue
{
private:
	int size;
	OneWayList<T> foo;
public:
	Queue();
	~Queue();
	bool isEmpty()const;
	int getSize()const;
	T dequeue();
	void enqueue(T _member);
	int search(T _key)const;		// return the position of the first _key element
};

