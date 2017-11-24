#include "OneWayList.h"
#include "OneWayList.cpp"
#include "TwoWayList.h"
#include "TwoWayList.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Array.h"
#include "Array.cpp"

using namespace std;

void OneWayListTest();
void QueueTest();
void ArrayTest();
void StackTest();
void TwoWayListTest();

int main()
{
	OneWayListTest();
	cout << endl << endl;

	TwoWayListTest();
	cout << endl << endl;

	QueueTest();
	cout << endl << endl;

	ArrayTest();
	cout << endl << endl;

	 StackTest();
	 cout << endl << endl;

	system("pause");
	return 0;
}

void OneWayListTest()
{
	cout << "Creating OneWayList<int> : \n";
	OneWayList<int> IntList = OneWayList<int>();
	IntList.insert_tail(1);
	IntList.insert_start(2);
	IntList.insert_tail(3);
	IntList.display();

	cout << "IntList.search(2): " << IntList.search(2) << endl;
	cout << "IntList.search(1): " << IntList.search(1) << endl;
	cout << "IntList.search(3): " << IntList.search(3) << endl << endl;

	cout << "IntList.delete_pos(2)" << endl;
	cout << "IntList.delete_pos(0)" << endl;
	cout << "IntList.delete_pos(0)" << endl;
	IntList.delete_pos(2);
	IntList.delete_pos(0);
	IntList.delete_pos(0);
	IntList.display();
}

void QueueTest()
{
	cout << "Creating Queue<int> : \n";
	Queue<int> IntQueue = Queue<int>();
	IntQueue.enqueue(2);
	IntQueue.enqueue(4);
	IntQueue.enqueue(8);
	IntQueue.enqueue(16);
	IntQueue.display();

	cout << "IntQueue.search(8): " << IntQueue.search(8) << endl;
	cout << "IntQueue.dequeue(): " << endl;
	IntQueue.dequeue();
	IntQueue.display();
	cout << "IntQueue.dequeue():" << endl;
	IntQueue.dequeue();
	IntQueue.display();
	cout << "IntQueue.enqueue(32): " << endl;
	IntQueue.enqueue(32);
	IntQueue.display();
	cout << "IntQueue.search(8): " << IntQueue.search(8) << endl;

	cout << endl << "Thank you for watching! \n\n";	
}

void ArrayTest() {
	int * mass = new int[10];
	for (int i = 0; i < 10; i++) {
		mass[i] = rand() % 10 + 1;
	}
	//BubbleSort and Reverse

	cout << "BubbleSort and Reverse:\n";
	Array<int> *arr1 = new Array<int>(10, mass);
	cout << "Your array:" << endl;
	arr1->Print();
	cout << endl;
	arr1->BubbleSort();
	arr1->Reverse();
	arr1->Print();
	//QuickSort

	cout << endl;
	cout << "QuickSort:\n";
	Array<int> *arr2 = new Array<int>(10, mass);
	arr2->QuickSort(0, 9);
	arr2->Print();
	//MergeSort
	cout << endl;
	cout << "MergeSort:\n";
	Array<int> *arr3 = new Array<int>(10, mass);
	arr3->MergeSort(0, 9);
	arr3->Print();
	cout << endl;
	//BinarySearch
	cout << "->BinarySearch(3)" << endl;
	cout << arr3->BinarySearch(0, 9, 3) << endl;
	//LinearSearch
	cout << "LinearSearch(4)" << endl;
	cout << arr3->LinearSearch(0, 9, 4) << endl;
	//+ and +=
	cout << "Operators + and +=" << endl;
	int * mass1 = new int[5];
	int * mass2 = new int[5];
	for (int i = 0; i < 5; i++) {
		mass1[i] = rand() % 10 + 1;
		mass2[i] = rand() % 10 + 1;
	}
	Array<int> a(5, mass1);
	Array<int> b(5, mass2);
	cout << "Array a:" << endl;
	a.Print();
	cout << endl;
	cout << "Array b:" << endl;
	b.Print();
	cout << endl;
	cout << "c = a+b:" << endl;
	Array<int> c = a + b;
	c.Print();
	cout << endl;
	cout << "a+=b:" << endl;
	a += b;
	a.Print();
}

void StackTest() {
	Stack<int>* stack = new Stack<int>();
	cout << "Stack Demo: \n";
	cout << "Pushing el" << endl;
	stack->push(3);
	stack->push(2);
	stack->push(40);
	stack->display();
	stack->pop();
	cout << "Stack->pop()" << endl;
	stack->display();
	cout << "Stack->pop()" << endl;
	stack->pop();
	stack->display();
	cout << "Stack->pop()" << endl;
	stack->pop();
	cout << "Stack->getTop()" << endl;
	cout << stack->getTop() << endl;
}

void TwoWayListTest()
{
	cout << "Creating TwoWayList<char> : \n";
	TwoWayList<char> CharList = TwoWayList<char>();
	CharList.insert_tail('a');
	CharList.insert_tail('i');
	CharList.insert_tail('d');
	CharList.insert_tail('s');
	CharList.display();

	cout << "CharList.display_reverse() : " << endl;
	CharList.display_reverse();

	cout << endl;

	cout << "CharList.search('d'): " << CharList.search('d') << endl;
	cout << "CharList.search('i'): " << CharList.search('i') << endl;
	cout << "CharList.search('a'): " << CharList.search('a') << endl << endl;

	cout << "CharList.delete_pos(0)" << endl;
	cout << "CharList.delete_first()" << endl;
	cout << "CharList.delete_last()" << endl;
	CharList.delete_pos(0);
	CharList.delete_first();
	CharList.delete_last();
	cout << "List: " << endl;
	CharList.display();
}