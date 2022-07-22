
#include "List.h"
#include <iostream>
#include <string>
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	List<int> list1;

	try
	{
		list1.insertAt(0, 0);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	try
	{
		list1.insertAt(1, 1);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	try
	{
		list1.insertAt(2, 2);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	
	list1.showContent();

	List<int> list2 = list1;

	cout << endl;

	list2.showContent();

	try
	{
		list2.insertAt(0, 15);
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << endl;
	list2.showContent();

	List<int> list3;

	cout << endl << "The size of list 2 is: " << list2.size() << endl;

	list1 = list2 = list3;

	list1.showContent();

	cout << endl << "The size of list 2 is: " << list2.size() << endl;

	return 0;
}