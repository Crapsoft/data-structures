#include <cstdlib>
#include <iostream>

template <typename T>
struct node
{
	T data;
	node<T> *next;
};

template <typename T>
class OneWayList
{
private:
	node<T> *head;
	node<T> *tail;
public:
	OneWayList();
	~OneWayList();
	bool isEmpty();
	void insert_tail(T value);
	void display();
	void insert_start(T value);
	void insert_position(int pos, T value);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
	T get_last();
	T get_first();
	T get_postion(int pos);
};
