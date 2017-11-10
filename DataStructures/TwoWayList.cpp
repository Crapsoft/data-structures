#pragma once
#include "TwoWayList.h"

template <class T>
TwoWayList<T>::TwoWayList()
{
	this->size = 0;
	head = NULL;
	tail = NULL;
}


template <class T>
TwoWayList<T>::~TwoWayList()
{
}


template <class T>
bool TwoWayList<T>::isEmpty()const
{
	return (this->size == 0);
}


template <class T>
void TwoWayList<T>::insert_tail(T value)
{
	nodek<T> *temp = new nodek<T>();
	temp->data = value;
	temp->next = NULL;
	temp->prev = tail;
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


template <class T>
void TwoWayList<T>::display()const
{
	nodek<T> *temp = new nodek<T>();
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

template <class T>
void TwoWayList<T>::display_reverse()const
{
	nodek<T> *temp = new nodek<T>();
	temp = NULL;
	if (!isEmpty()) {
		temp = tail;
		while (temp != NULL)
		{
			std::cout << temp->data << "\t";
			temp = temp->prev;
		}
		std::cout << endl;
	}
	else {
		std::cout << "List is empty! \n";
	}
	delete temp;
}


template <class T>
void TwoWayList<T>::insert_start(T value)
{
	nodek<T> *temp = new nodek<T>();
	temp->data = value;
	temp->next = head;
	head->prev = temp;
	head = temp;

	this->size++;
}


template <class T>
void TwoWayList<T>::insert_position(int pos, T value)
{
	nodek<T> *pre = new nodek<T>();
	nodek<T> *cur = new nodek<T>();
	nodek<T> *temp = new nodek<T>();
	cur = head;
	for (int i = 1; i<pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
	temp->prev = pre;
	next->prev = temp;

	this->size++;
}


template <class T>
void TwoWayList<T>::delete_first()
{
	if (this->size > 1) {
		nodek<T> *temp = new nodek<T>();
		temp = head;
		this->head = this->head->next;
		delete temp;
	}
	else if (this->size == 1)
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


template <class T>
void TwoWayList<T>::delete_last()
{
	if (this->size == 1) {
		delete tail;
		this->head = NULL;
		this->tail = NULL;
	}
	else {
		nodek<T> *current = new nodek<T>();
		nodek<T> *previous = new nodek<T>();
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


template <class T>
void TwoWayList<T>::delete_pos(int pos)
{
	if (this->size == 1)
	{
		delete head;
		delete tail;
	}
	else if (pos == 0)
	{
		delete_first();
		return;
	}
	else
	{
		nodek<T> *current = new nodek<T>();
		nodek<T> *previous = new nodek<T>();
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


template <class T>
int TwoWayList<T>::search(T _key)const
{
	if (isEmpty())
	{
		cout << "The list is empty!";
		return -1;
	}
	else if (head->data == _key)
	{
		return 0;
	}
	else
	{
		nodek<T> *temp = head;
		int pos = 0;
		while (temp->data != _key)
		{
			pos++;
			if (pos > this->size) {
				return -1;
			}
			temp = temp->next;
			if (temp->data == _key) {
				return pos;
			}
		}
	}
	return -1;
}

template <class T>
T TwoWayList<T>::get_last()
{
	return tail->data;
}


template <class T>
T TwoWayList<T>::get_first()
{
	return head->data;
}


template <class T>
T TwoWayList<T>::get_postion(int pos)
{
	nodek<T> *current = new nodek<T>();
	current = head;
	for (int i = 1; i<pos; i++)
	{
		current = current->next;
	}
	return current->data;
}
