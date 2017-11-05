//#include "OneWayList.h"
#include "OneWayList.cpp"
#include "Queue.h"
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

void oneWayListTest();

int main()
{
	oneWayListTest();

	system("pause");
	return 0;
}

void oneWayListTest()
{
	cout << "Creating OneWayList<int> : \n";
	OneWayList<int> IntList = OneWayList<int>();
	IntList.insert_tail(1);
	IntList.insert_start(2);
	IntList.insert_tail(3);
	IntList.display();
	IntList.delete_pos(2);
	IntList.delete_pos(0);
	IntList.delete_pos(0);
	IntList.display();
}