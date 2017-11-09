#pragma once
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
	int size;
public:
	OneWayList();
	~OneWayList();
	bool isEmpty()const;
	void insert_tail(T value);
	void display()const;
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

