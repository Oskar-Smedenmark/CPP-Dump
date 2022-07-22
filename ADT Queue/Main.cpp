#include "Queue.h"
#include <iostream>

int main()
{
	Queue<int> aQueue;

	aQueue.enqueue(1);
	aQueue.enqueue(2);
	aQueue.enqueue(3);

	Queue<int> aQueue2 = aQueue;

	aQueue2.enqueue(3);
	aQueue2.enqueue(2);
	aQueue2.enqueue(1);

	cout << aQueue2.peek() << endl;

	aQueue = aQueue2;

	aQueue.dequeue();

	cout << aQueue.peek() << endl;

	return 0;
}