#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

using namespace std;

template <typename T>
class Queue : public IQueue<T>
{
public:
	Queue();
	Queue(const Queue<T> &origObj);
	virtual ~Queue();

	void enqueue(const T& element);
	T dequeue() throw(...);

	T peek() const throw(...);
	bool isEmpty() const;

	Queue<T> operator=(const Queue<T> &origObj);

private:
	//static const int CAP = 4;
	//T theQueue[CAP];
	//int nrOfElements;
	//T firstElement;
	class Node
	{
	public:
		T element;
		Node* next;
		Node(T element) { this->element = element; this->next = nullptr; }
		~Node(){}
	};
	int nrOfNodes;
	Node* first;
};

template <typename T>
Queue<T>::Queue()
{
	/*this->nrOfElements = 0;*/
	this->nrOfNodes = 0;
	this->first = nullptr;
}
template <typename T>
Queue<T>::Queue(const Queue<T> &origObj)
{
	/*this->nrOfElements = origObj.nrOfElements;
	for (int i = 0; i < origObj.nrOfElements; i++)
	{
		this->theQueue[i] = origObj.theQueue[i];
	}*/
	Node* walker = origObj.first;

	this->nrOfNodes = 0;

	for (int i = 0; i < origObj.nrOfNodes; i++)
	{
		this->enqueue(walker->element);
		walker = walker->next;
	}
}
template <typename T>
Queue<T>::~Queue()
{
	Node* walker = this->first;

	for (int i = 0; i < this->nrOfNodes; i++)
	{
		walker = this->first->next;
		delete this->first;
		this->first = walker;
	}
}

template <typename T>
void Queue<T>::enqueue(const T &element)
{
	//if (this->nrOfElements == this->CAP)
	//{
	//	this->dequeue();
	//}
	//this->theQueue[this->nrOfElements] = element;
	//this->firstElement = this->theQueue[0];
	Node* e = new Node(element);
	if (this->nrOfNodes == 0)
	{
		this->first = e;
	}
	else
	{
		Node* walker = this->first;
		while (walker->next != nullptr)
		{
			walker = walker->next;
		}
		e->next = walker->next;
		walker->next = e;
	}
	this->nrOfElements++;
}

template <typename T>
T Queue<T>::dequeue() throw(...)
{
	/*T theElement;
	theElement = this->theQueue[0];
	for (int i = 0; i < this->nrOfElements; i++)
	{
		this->theQueue[i] = this->theQueue[i + 1];
	}
	this->firstElement = this->theQueue[0];*/

	if (this->nrOfNodes == 0)
	{
		throw "The queue is empty";
	}
	T theElement = this->first->element;
	Node* toDelete = this->first;

	this->first = this->first->next;

	delete toDelete;

	this->nrOfNodes--;

	return theElement;
}
template <typename T>
T Queue<T>::peek() const throw(...)
{
	if (this->nrOfNodes == 0)
	{
		throw "The queue is empty";
	}
	return this->first->element;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	bool result = false;
	if (this->nrOfNodes == 0)
	{
		result = true;
	}
	return result;
}

template <typename T>
Queue<T> Queue<T>::operator=(const Queue<T> &origObj)
{
	if (this != &origObj)
	{
		Node* walker = this->first;

		for (int i = 0; i < this->nrOfNodes; i++)
		{
			this->dequeue();
		}

		walker = origObj.first;

		for (int i = 0; i < origObj.nrOfNodes; i++)
		{
			this->enqueue(walker->element);
			walker = walker->next;
		}
	}

	return *this;
}
#endif