#include "Array.h"


template <typename T>
Array<T>::Array(int size)
{
	this->size = size;
	this->array = new T[size];
}

template <typename T>
Array<T>::Array(int size, T* arr) {
	this->size = size;
	array = new T[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = arr[i];
	}
}


template <typename T>
void Array<T>::Print() {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}


template <typename T>
void Array<T>::Reverse() {
	T temp;
	for (int i = 0; i < size / 2; ++i) {
		temp = array[size - i - 1];
		array[size - i - 1] = array[i];
		array[i] = temp;
	}
}


template <typename T>
void Array<T>::BubbleSort() {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j+1])
			{
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


template <typename T>
void Array<T>::QuickSort(int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = array[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSort(left, j);
	if (i < right)
		QuickSort(i, right);
}


template <typename T>
void Array<T>::merge(int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//T L[n1], R[n2];
	T* L = new T[n1];
	T* R = new T[n2];
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}


template <typename T>
void Array<T>::MergeSort(int l, int r) {
	if (l < r)
	{
		int m = l + (r - l) / 2;
		MergeSort(l, m);
		MergeSort(m + 1, r);

		merge(l, m, r);
	}
}


template <typename T>
int Array<T>::BinarySearch(int l, int r, T target) {
	int high = r;
	int low = l;
	int mid;
	if (array[l] == target)
	{
		return 0;
	}
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (array[mid] == target)
		{
			return mid;
		}
		else if (array[mid]>target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}

	}
	return -1;
}


template <typename T>
int Array<T>::LinearSearch(int l, int r, T target) {
	for (int i = 0; i < size; i++)
	{
		if (array[i] == target)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& arr)
{
	int nsize = arr.size + size;
	T* buffer = new T[nsize];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		buffer[k] = array[i];
		k++;
	}
	for (int i = 0; i < arr.size; i++)
	{
		buffer[k] = arr.array[i];
		k++;
	}
	Array<T>t_res(nsize, buffer);
	return t_res;

}

template <typename T>
Array<T>& Array<T>::operator+=(const Array<T>& el) {
	int nsize = el.size + size;
	T* buffer = new T[nsize];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		buffer[k] = array[i];
		k++;
	}

	for (int i = 0; i < el.size; i++)
	{
		buffer[k] = el.array[i];
		k++;
	}
	array = new T[nsize];
	for (int i = 0; i < nsize; i++)
	{
		array[i] = buffer[i];
	}
	size = nsize;
	return *this;
}

template<typename T>
T& Array<T>::get(int i) {
	return &array[i];
}


template <typename T>
Array<T>::~Array()
{
	//delete array;

}
