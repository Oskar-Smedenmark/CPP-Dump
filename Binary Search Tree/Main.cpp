#include "BinarySearchTree.h"
#include <crtdbg.h>
#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	BinarySearchTree<int> bst;

	int anArray[10];

	bool exists = false;

	bst.insert(61);
	bst.insert(235);
	bst.insert(1);
	bst.insert(49);
	bst.insert(4563);
	bst.insert(234634);
	bst.insert(245);
	bst.insert(3457);
	bst.insert(9234);
	bst.insert(23);

	exists = bst.contains(23);
	try
	{
		bst.getContentSorted(anArray, 10);
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << anArray[i] << " ";
	}
	cout << endl;

	if (exists == true)
	{
		cout << "It exists!" << endl;
	}
	else
	{
		cout << "It doesn't exists!" << endl;
	}

	return 0;
}