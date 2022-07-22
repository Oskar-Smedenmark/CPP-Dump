#include "folder.h"
#include "file.h"
#include <iostream>
#include <crtdbg.h>
#include <fstream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Folder testFolder("Root", "C://Root", 0);
	string name = "";
	FileItem* findItem = nullptr;
	vector<int> test;
	int blockNr = 6;
	string fileName = "";
	testFolder.createFile("test1.txt", 1);
	testFolder.createFile("test2.txt", 2);
	testFolder.createFile("test3.txt", 3);
	testFolder.createFile("test4.txt", 4);
	testFolder.createFolder("NewFolder1");
	testFolder.createFolder("NewFolder2");
	testFolder.createFolder("NewFolder3");
	testFolder.createFile("test5.txt", 5);
	
	try
	{
		cout << testFolder["NewFolder1"]->toString() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	testFolder.deleteItem("test3.txt", test);

	testFolder.getContentIndicators();
	//cout << /*testFolder.getContentIndicators()*/ testFolder.toString() << endl;

	Folder* folderPtr = nullptr;
	
	while (name != "stop")
	{
		cout << "Write a folder name in which you would like to create a new file in: ";
		cin >> name;

		folderPtr = nullptr;

		folderPtr = dynamic_cast<Folder*>(testFolder.getItem(name));

		if (folderPtr != nullptr)
		{
			cout << "What is the files name?: ";
			cin >> fileName;
			folderPtr->createFile(fileName, blockNr);
			blockNr++;
		}
		cout << endl << endl;
	}


	try
	{
		cout << testFolder["NewFolder1"]->toString() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	//string result = testFolder.getContentIndicators();
	

	//findItem = dynamic_cast<Folder*>(testFolder.getItem(name));
	//if (findItem != nullptr)
	//{
	//	cout << findItem->toString() << endl;
	//}
	//findItem = dynamic_cast<File*>(testFolder.getItem(name));
	//if (findItem != nullptr)
	//{
	//	cout << findItem->toString() << endl;
	//}


	for (unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}



	system("pause");
	return 0;
}