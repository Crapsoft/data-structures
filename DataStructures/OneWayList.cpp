#include "OneWayList.h"

template <class T>
OneWayList<T>::OneWayList()
{
	head = NULL;
	tail = NULL;
}

template <class T>
OneWayList<T>::~OneWayList()
{
	while (!isEmpty()) { delete_first(); }
}

template <class T>
bool OneWayList<T>::isEmpty()
{
	return (this->head == NULL);
}

template <class T>
void OneWayList<T>::insert_tail(T value)
{
	node *temp = new node;
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
		tail->next = temp;
		tail = temp;
	}
}

template <class T>
void OneWayList<T>::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
}

template <class T>
void OneWayList<T>::insert_start(T value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

template <class T>
void OneWayList<T>::insert_position(int pos, T value)
{
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
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

template <class T>
void OneWayList<T>::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

template <class T>
void OneWayList<T>::delete_last()
{
	node *current = new node;
	node *previous = new node;
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

template <class T>
void OneWayList<T>::delete_position(int pos)
{
	node *current = new node;
	node *previous = new node;
	current = head;
	for (int i = 1; i<pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}

template<class T>
T OneWayList<T>::get_last()
{
	return tail->data;
}

template<class T>
T OneWayList<T>::get_first()
{
	return head->data;
}

template<class T>
T OneWayList<T>::get_postion(int pos)
{
	node *current = new node;
	current = head;
	for (int i = 1; i<pos; i++)
	{
		current = current->next;
	}
	return current->data;
}
