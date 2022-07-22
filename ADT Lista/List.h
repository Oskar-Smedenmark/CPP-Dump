#ifndef LIST_H
#define LIST_H

#include "IList.h"

template<typename T>
class List : public IList<T>
{
public:
	List();
	virtual ~List();
	List(const List<T> &origObj);
	List<T> operator=(const List<T> &origObj);

	void insertAt(int pos, T element) throw(...);
	T elementAt(int pos) const throw(...);
	T removeAt(int pos) throw(...);
	void showContent() const;
	int size() const;

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

template<typename T>
List<T>::List()
{
	this->first = nullptr;
	this->nrOfNodes = 0;
}
template<typename T>
List<T>::List(const List<T> &origObj)
{
	this->nrOfNodes = 0;

	for (int i = 0; i < origObj.nrOfNodes; i++)
	{
		this->insertAt(i, origObj.elementAt(i));
	}
}
template<typename T>
List<T>::~List()
{
	Node* walker = this->first;

	for (int i = 0; i < this->nrOfNodes; i++)
	{
		walker = this->first->next;
		delete this->first;
		this->first = walker;
	}
}
template<typename T>
T List<T>::elementAt(int pos) const throw(...)
{
	if (pos < 0 || pos > this->nrOfNodes - 1)
	{
		throw "That position is not allowed";
	}
	
	
	Node* walker = this->first;

	for (int i = 0; i < pos; i++)
	{
		walker = walker->next;
	}


	return walker->element;
	
}

template<typename T>
T List<T>::removeAt(int pos) throw(...)
{
	if (this->first == nullptr)
	{
		throw "Empty list";
	}
	if (pos < 0 || pos > this->nrOfNodes - 1)
	{
		throw "That position is not allowed";
	}
	T result;
	Node* walker = this->first;
	if (pos == 0)
	{
		Node* walker = this->first;
		this->first = this->first->next;

		result = walker->element;

		delete walker;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			walker = walker->next;
		}
		Node* toDelete = walker->next;

		walker->next = toDelete->next;

		result = toDelete->element;

		delete toDelete;
	}

	this->nrOfNodes--;

	return result;
}

template<typename T>
void List<T>::insertAt(int pos, T element) throw(...)
{
	if (pos < 0 || pos > this->nrOfNodes)
	{
		throw "That position is not allowed";
	}
	Node* e = new Node(element);
	if (pos == 0)
	{
		e->next = this->first;
		this->first = e;
	}
	else
	{
		Node* walker = this->first;

		for (int i = 0; i < pos - 1; i++)
		{
			walker = walker->next;
		}

		e->next = walker->next;
		walker->next = e;

	}

	this->nrOfNodes++;
}

template<typename T>
void List<T>::showContent() const
{
	for (int i = 0; i < this->nrOfNodes; i++)
	{
		cout << this->elementAt(i) << endl;
	}
}

template<typename T>
int List<T>::size() const
{
	return this->nrOfNodes;
}

//Does not work
template<typename T>
List<T> List<T>::operator=(const List<T> &origObj)
{
	if (this != &origObj)
	{
		Node* walker = this->first;

		for (int i = 0; i < this->nrOfNodes; i++)
		{
			walker = this->first->next;
			delete this->first;
			this->first = walker;
		}

		this->nrOfNodes = 0;

		for (int i = 0; i < origObj.nrOfNodes; i++)
		{
			this->insertAt(i, origObj.elementAt(i));
		}
	}
	return *this;
}

#endif