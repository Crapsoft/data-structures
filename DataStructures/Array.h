#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Array
{
private:
	T* array;
	int size;
public:
	Array(int size);
	Array(int size, T* array);
	void Reverse();
	void BubbleSort();
	~Array();
};

