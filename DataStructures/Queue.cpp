#include "Queue.h"



Queue::Queue()
{
	this->size = 0;
}


Queue::~Queue()
{
}

bool Queue::isEmpty() const
{
	return (this->size == 0);
}

int Queue::getSize() const
{
	return this->size;
}

//int Queue::dequeue()
//{
//	arr.()
//	this->size--;
//	return member;
//}

void Queue::enqueue(int _member)
{
}

int Queue::search(int _key) const
{
	return 0;
}
