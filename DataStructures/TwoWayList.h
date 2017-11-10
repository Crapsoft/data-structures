#pragma once
#include <cstdlib>
#include <iostream>

template <class T>
struct nodek
{
	T data;
	nodek<T> *prev, *next;
};

template <class T>
class TwoWayList
{
private:
	int size;
	nodek<T> *head;
	nodek<T> *tail;
public:
	TwoWayList();
	~TwoWayList();
	bool isEmpty()const;
	void insert_tail(T value);
	void display()const;
	void display_reverse()const;
	void insert_start(T value);
	void insert_position(int pos, T value);
	void delete_first();
	void delete_last();
	void delete_pos(int pos);			// Beginning from List[0]
	int search(T _key)const;
	T get_last();
	T get_first();
	T get_postion(int pos);
};

