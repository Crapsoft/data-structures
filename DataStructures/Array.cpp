#include "Array.h"


template <typename T>
Array<T>::Array(int size)
{
	this->size = size;
	this->array = new T[size];
}
template <typename T>
Array<T>::Array(int size, T* array) {
	this->array = array;
	this->size = size;
}
template <typename T>
void Array<T>::Reverse() {

}
template <typename T>
void Array<T>::BubbleSort() {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j+1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}


template <typename T>
Array::~Array()
{
}
