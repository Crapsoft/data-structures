//#include "OneWayList.h"
#include "OneWayList.cpp"
#include "Queue.h"
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int main()
{
	OneWayList<int> IntList = OneWayList<int>();
	IntList.insert_tail(1);
	IntList.insert_tail(2);
	IntList.insert_tail(3);
	IntList.display();
	IntList.delete_first();
	IntList.delete_first();
	IntList.delete_first();
	IntList.display();

	system("pause");
	return 0;
}