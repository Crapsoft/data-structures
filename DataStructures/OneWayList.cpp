#include "OneWayList.h"


OneWayList::OneWayList()
{
	head = NULL;
	tail = NULL;
}


OneWayList::~OneWayList()
{
	while (!isEmpty()) { delete_first(); }
}

bool OneWayList::isEmpty()
{
	return (this->head == NULL);
}

void OneWayList::createnode(int value)
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

void OneWayList::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
}

void OneWayList::insert_start(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

void OneWayList::insert_position(int pos, int value)
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

void OneWayList::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

void OneWayList::delete_last()
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

void OneWayList::delete_position(int pos)
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