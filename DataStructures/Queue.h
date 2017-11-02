#pragma once

#include <vector>

class Queue
{
private:
	int size;
	std::vector<int> arr;
public:
	Queue();
	~Queue();
	bool isEmpty()const;
	int getSize()const;
	int dequeue();
	void enqueue(int _member);
	int search(int _key)const;		// return the position of the first _key element
};

