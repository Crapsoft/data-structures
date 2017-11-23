#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Array
{
private:
	T* array;
	int size;
	void merge(int l, int m, int r);
public:
	Array(int size);
	T& get(int i);
	void Reverse();
	void BubbleSort();
	void Print();
	void QuickSort(int left, int right);
	void MergeSort(int l, int r);
	int BinarySearch(int l, int r, T target);
	int LinearSearch(int l, int r, T target);
	Array<T> operator+(const Array<T>& arr);
	void operator+=(const Array<T>&);
	~Array();
};

