#include "Stack.h"


template <typename T>
Stack<T>::Stack()
{
	top = NULL;
	size = 0;
}
template <typename T>
void Stack<T>::push(T el) {
	try
	{
		if (top != NULL)
		{
			node<T> *temp = new node<T>();
			temp->data = el;
			temp->next = this->top;
			this->top = temp;
		}
		else
		{
			this->top = new node<T>();
			this->top->data = el;
		}
		this->size++;
	}
	catch (const std::bad_alloc)
	{
		cout << "std::bad_alloc" << endl;
	}
}
template <typename T>
T Stack<T>::pop() {
	try
	{
		if (top != NULL)
		{
			node<T>* temp = top;
			int elem = top->data;
			top = top->next;
			delete temp;
			size--;
			return elem;
		}
		else
		{
			throw std::out_of_range("Error: Out of range");
			return NULL;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
template <typename T>
int Stack<T>::getSize() {
	return size;
}
template <typename T>
T Stack<T>::getTop() {
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
template <typename T>
bool Stack<T>::isempty() {
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
Stack<T>::~Stack()
{
}
