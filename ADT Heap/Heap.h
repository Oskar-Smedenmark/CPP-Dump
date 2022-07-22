#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;

template <typename T>
class Heap
{
public:
	Heap();
	Heap(const Heap &origObj);
	virtual ~Heap();

	void insert(T element);
	T deleteMax() throw(...);

	int size() const;
	T root() const throw(...);

private:
	T* elements;
	int nrOfElements;
	int capacity;

	void expand();
};

template <typename T>
Heap<T>::Heap()
{
	this->nrOfElements = 0;
	this->capacity = 10;
	this->elements = new T[this->capacity];
}
template <typename T>
Heap<T>::Heap(const Heap &origObj)
{
	this->capacity = origObj.capacity;
	this->nrOfElements = origObj.nrOfElements;

	this->elements = new T[origObj.capacity];

	for (int i = 0; i < origObj.nrOfElements; i++)
	{
		this->elements[i] = origObj.elements[i];
	}
}
template <typename T>
Heap<T>::~Heap()
{
	delete[]this->elements;
}

template <typename T>
void Heap<T>::insert(T element)
{
	int parentPos = 0;
	int currentPos = 0;

	if (this->nrOfElements == this->capacity)
	{
		this->expand();
	}
	this->elements[this->nrOfElements++] = element;

	currentPos = this->nrOfElements - 1;
	parentPos = (currentPos - 1) / 2;

	while (currentPos > 0 && this->elements[parentPos] < element)
	{
		this->elements[currentPos] = this->elements[parentPos];
		
		currentPos = parentPos;
		parentPos = (currentPos - 1) / 2;
	}
	this->elements[currentPos] = element;

	for (int i = 0; i < this->nrOfElements; i++)
	{
		cout << this->elements[i] << " ";
	}
	cout << endl;
}

template <typename T>
T Heap<T>::deleteMax() throw(...)
{
	if (this->nrOfElements == 0)
	{
		throw "The heap is empty";
	}

	int parentPos = 0;
	int currentPos = 0;
	int leftChildPos = 0;
	int rightChildPos = 0;

	T theElement;
	
	theElement = this->elements[0];

	this->elements[0] = this->elements[--this->nrOfElements];
	T currentElement = this->elements[0];

	while (parentPos < this->nrOfElements/ 2 && currentElement < this->elements[currentPos] || currentPos == 0)
	{
		leftChildPos = 2 * currentPos + 1;
		rightChildPos = leftChildPos + 1;

		if (rightChildPos < this->nrOfElements && this->elements[leftChildPos] < this->elements[rightChildPos])
		{
			currentPos = rightChildPos;
		}
		else
		{
			currentPos = leftChildPos;
		}

		if (currentElement < this->elements[currentPos])
		{
			this->elements[parentPos] = this->elements[currentPos];
			parentPos = currentPos;
		}
		
	}
	this->elements[currentPos] = currentElement;

	for (int i = 0; i < this->nrOfElements; i++)
	{
		cout << this->elements[i] << " ";
	}
	cout << endl;

	return theElement;
}

template <typename T>
void Heap<T>::expand()
{
	this->capacity += 10;
	T* temp = new T[capacity];

	for (int i = 0; i < this->nrOfElements; i++)
	{
		temp[i] = this->elements[i];
	}
	delete[]this->elements;

	this->elements = temp;

	temp = nullptr;
}

#endif