#include "Heap.h"
#include <crtdbg.h>

template <typename T>
void heapSort(T theArray[], int nrOfElements)
{
	Heap<T> theHeap;

	for (int i = 0; i < nrOfElements; i++)
	{
		theHeap.insert(theArray[i]);
	}
	for (int i = 0; i < nrOfElements; i++)
	{
		theArray[i] = theHeap.deleteMax();
	}

	for (int i = 0; i < nrOfElements; i++)
	{
		cout << theArray[i] << " ";
	}
	cout << endl;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int anArray[10] = { 6, 2, 72, 658, 12, 456, 1, 10, 76, 43 };

	heapSort(anArray, 10);


	return 0;
}