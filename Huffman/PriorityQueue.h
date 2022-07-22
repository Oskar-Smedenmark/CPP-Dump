#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "IPriorityQueue.h"

using namespace std;

template <typename T>
class PriorityQueue : public IPriorityQueue<T>
{
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue<T> &origObj);
	virtual ~PriorityQueue();

	void enqueue(const T &element);
	T dequeue() throw(...);

	T peek() const throw(...);
	int size() const;

	PriorityQueue<T> operator=(const PriorityQueue<T> &origObj);
	
private:
	class Node
	{
	public:
		T element;
		Node* next;
		Node(T element) {this->element = element; this->next = nullptr;}
		~Node(){}
	};
	int nrOfNodes;
	Node* first;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	this->nrOfNodes = 0;
	this->first = nullptr;
}
template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &origObj)
{
	Node* walker = origObj.first;

	this->nrOfNodes = 0;

	for (int i = 0; i < origObj.nrOfNodes; i++)
	{
		this->enqueue(walker->element);
		walker = walker->next;
	}
}
template <typename T>
PriorityQueue<T>::~PriorityQueue()
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
void PriorityQueue<T>::enqueue(const T &element)
{
	Node* e = new Node(element);
	if (this->nrOfNodes == 0)
	{
		this->first = e;
	}
	else
	{
		if (element < this->first->element)
		{
			e->next = this->first;
			this->first = e;
		}
		else
		{
			Node* walker = this->first;
			while (walker->next != nullptr && element > walker->next->element)
			{
				walker = walker->next;
			}
			e->next = walker->next;
			walker->next = e;
		}
	}
	this->nrOfNodes++;
}
template <typename T>
T PriorityQueue<T>::dequeue() throw(...)
{
	if (this->nrOfNodes == 0)
	{
		throw "The list is empty";
	}
	T theElement = this->first->element;
	Node* toDelete = this->first;

	this->first = this->first->next;

	delete toDelete;

	this->nrOfNodes--;

	return theElement;
}
template <typename T>
T PriorityQueue<T>::peek() const throw(...)
{
	if (this->nrOfNodes == 0)
	{
		throw "The list is empty";
	}

	return this->first->element;
}

template <typename T>
int PriorityQueue<T>::size() const
{
	return this->nrOfNodes;
}

template <typename T>
PriorityQueue<T> PriorityQueue<T>::operator=(const PriorityQueue<T> &origObj)
{
	if (this != &origObj)
	{
		Node* walker = this->first;

		for (int i = 0; i < this->nrOfNodes; i++)
		{
			/*walker = this->first->next;
			delete this->first;
			this->first = walker;*/
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