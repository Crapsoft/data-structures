#include "Stack.h"



Stack::Stack()
{
}
void Stack::push(int el) {
	if (top != NULL)
	{
		node2* temp = new node2();
		temp->data = el;
		temp->next = this->top;
		this->top = temp;
	}
	else
	{
		this->top = new node2;
		this->top->data = el;
	}
}
int Stack::pop() {
	if (top != NULL)
	{
		node2* temp = top;
		int elem = top->data;
		top = top->next;
		delete temp;
		size--;
		return elem;
	}
	else
	{
		cout << "Stack is empty";
		return NULL;
	}
}
int Stack::getSize() {
	return size;
}
int Stack::getTop() {
	if (top == NULL)
	{
		cout << "Stack is empty";
		return NULL;
	}
	else
	{
		return top->data;
	}
}
bool Stack::isempty() {
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Stack::~Stack()
{
}
