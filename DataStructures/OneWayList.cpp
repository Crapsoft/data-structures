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
	bool isEmpty();
	void insert_tail(T value);
	void display();
	void insert_start(T value);
	void insert_position(int pos, T value);
	void delete_first();
	void delete_last();
	void delete_pos(int pos);			// Beginning from List[0]
	T get_last();
	T get_first();
	T get_postion(int pos);
};


template <typename T>
OneWayList<T>::OneWayList()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template <typename T>
bool OneWayList<T>::isEmpty()
{
	return (this->size == 0);
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
	
	this->size++;
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
			std::cout << endl;
		}
		else {
			std::cout << "List is empty! \n";
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

	this->size++;
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

	this->size++;
}

template <typename T>
void OneWayList<T>::delete_first()
{
	if (this->size > 1) {
		node<T> *temp = new node<T>();
		temp = head;
		this->head = this->head->next;
		delete temp;
	}
	else if(this->size == 1)
	{
		delete head;
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		cout << "List is already empty! \n";
	}

	this->size--;
}

template <typename T>
void OneWayList<T>::delete_last()
{
	if (this->size == 1) {
		delete tail;
		this->head = NULL;
		this->tail = NULL;
	}
	else {
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

	this->size--;
}

template <typename T>
void OneWayList<T>::delete_pos(int pos)
{
	if (this->size == 1)
	{
		delete head;
		delete tail;
	}
	else
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

	this->size--;
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
