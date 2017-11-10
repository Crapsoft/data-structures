#include "Queue.h"


template <class T>
Queue<T>::Queue()
{
	foo = OneWayList<T>();
	this->size = 0;
}


template <class T>
Queue<T>::~Queue()
{
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return (this->size == 0);
}

template <class T>
int Queue<T>::getSize() const
{
	return this->size;
}

template <class T>
T Queue<T>::dequeue()
{
	T member = foo.get_first();
	foo.delete_first();
	this->size--;
	return member;
}

template <class T>
void Queue<T>::enqueue(T _member)
{
	foo.insert_tail(_member);
	this->size++;
}

template <class T>
int Queue<T>::search(T _key) const
{
	return foo.search(_key);
}

template<class T>
void Queue<T>::display() const
{
	foo.display();
}
