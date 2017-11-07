#include "TwoWayList.h"



template <class T>
TwoWayList::TwoWayList()
{
	this->size = 0;
	head = NULL;
	tail = NULL;
}


template <class T>
TwoWayList::~TwoWayList()
{
}


template <class T>
bool OneWayList<T>::isEmpty()const
{
	return (this->size == 0);
}


template <class T>
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


template <class T>
void OneWayList<T>::display()const
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


template <class T>
void OneWayList<T>::insert_start(T value)
{
	node<T> *temp = new node<T>();
	temp->data = value;
	temp->next = head;
	head = temp;

	this->size++;
}


template <class T>
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


template <class T>
void OneWayList<T>::delete_first()
{
	if (this->size > 1) {
		node<T> *temp = new node<T>();
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


template <class T>
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


template <class T>
int OneWayList<T>::search(T _key)const
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
		node<T> *temp = head;
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
}

template <class T>
T OneWayList<T>::get_last()
{
	return tail->data;
}


template <class T>
T OneWayList<T>::get_first()
{
	return head->data;
}


template <class T>
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
