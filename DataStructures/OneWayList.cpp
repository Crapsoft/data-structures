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


template <typename T>
OneWayList<T>::OneWayList()
{
	this->head = NULL;
	this->tail = NULL;
}

template <typename T>
bool OneWayList<T>::isEmpty()
{
	return (this->head == NULL);
}

template <typename T>
OneWayList<T>::~OneWayList()
{
	while (!isEmpty()) { delete_first(); }
}

template <typename T>
void OneWayList<T>::insert_tail(T value)
{
	node<T> *temp = new node<T>();
	temp->data = value;
	temp->next = NULL;
	if (this->head == NULL)
	{
		this->head = temp;
		this->tail = temp;
		temp = NULL;
	}
	else
	{
		this->tail->next = temp;
		this->tail = temp;
	}
}

template <typename T>
void OneWayList<T>::display()
{
		node<T> *temp = new node<T>();
		temp = NULL;
		if (!isEmpty()) {
			temp = head;
			while (temp != NULL)
			{
				std::cout << temp->data << "\t";
				temp = temp->next;
			}
			std::cout << endl << "zz";
		}
		delete temp;
}

template <typename T>
void OneWayList<T>::insert_start(T value)
{
	node<T> *temp = new node<T>();
	temp->data = value;
	temp->next = head;
	head = temp;
}

template <typename T>
void OneWayList<T>::insert_position(int pos, T value)
{
	node<T> *pre = new node<T>();
	node<T> *cur = new node<T>();
	node<T> *temp = new node<T>();
	cur = head;
	for (int i = 1; i<pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

template <typename T>
void OneWayList<T>::delete_first()
{
	if (!isEmpty()) {
		node<T> *temp = new node<T>();
		temp = head;
		if (head->next != NULL) {
			head = head->next;
		}
		delete temp;
	}
}

template <typename T>
void OneWayList<T>::delete_last()
{
	node<T> *current = new node<T>();
	node<T> *previous = new node<T>();
	current = head;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
}

template <typename T>
void OneWayList<T>::delete_position(int pos)
{
	node<T> *current = new node<T>();
	node<T> *previous = new node<T>();
	current = head;
	for (int i = 0; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}

template <typename T>
T OneWayList<T>::get_last()
{
	return tail->data;
}

template <typename T>
T OneWayList<T>::get_first()
{
	return head->data;
}

template <typename T>
T OneWayList<T>::get_postion(int pos)
{
	node<T> *current = new node<T>();
	current = head;
	for (int i = 1; i<pos; i++)
	{
		current = current->next;
	}
	return current->data;
}
