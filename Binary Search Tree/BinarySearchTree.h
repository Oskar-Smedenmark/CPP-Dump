#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
	class Node
	{
	public:
		T info;
		Node *leftChild;
		Node *rightChild;
		Node(T info) { this->info = info; this->leftChild = nullptr; this->rightChild = nullptr; }
		~Node() {};
	};
	Node *root;
	int nrOfNodes;
	// helper functions
	void freeMemory(Node* root);
	void traversInOrder(Node* root, T theArray[], int &counter) const;
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void insert(T info);
	bool contains(T info) const;
	int getNrOfNodes() const;
	void getContentSorted(T result[], int n) const throw(...); // throws exception when n is smaller than the the number of elements/nodes in the tree
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	this->root = nullptr;
	this->nrOfNodes = 0;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	this->freeMemory(this->root);
}
template <typename T>
void BinarySearchTree<T>::freeMemory(Node* root)
{
	if (root != nullptr)
	{
		this->freeMemory(root->leftChild);

		this->freeMemory(root->rightChild);

		delete root;
	}
}

template <typename T>
void BinarySearchTree<T>::insert(T info)
{
	Node* e = new Node(info);
	if (this->root == nullptr)
	{
		this->root = e;
	}
	else
	{
		Node* walker = this->root;
		Node* parentWalker = nullptr;
		
		while (walker != nullptr)
		{
			parentWalker = walker;
			if (info < walker->info)
			{
				walker = walker->leftChild;
			}
			else
			{
				walker = walker->rightChild;
			}
		}
		if (info < parentWalker->info)
		{
			parentWalker->leftChild = e;
		}
		else
		{
			parentWalker->rightChild = e;
		}
	}
	this->nrOfNodes++;
}

template <typename T>
bool BinarySearchTree<T>::contains(T info) const
{
	bool result = false;

	Node* walker = this->root;

	while (walker != nullptr && result == false)
	{
		if (info == walker->info)
		{
			result = true;
		}
		if (info < walker->info)
		{
			walker = walker->leftChild;
		}
		else
		{
			walker = walker->rightChild;
		}
	}

	return result;
}

template <typename T>
int BinarySearchTree<T>::getNrOfNodes() const
{
	return this->nrOfNodes;
}

template <typename T>
void BinarySearchTree<T>::getContentSorted(T result[], int n) const throw(...)
{
	if (this->nrOfNodes < n)
	{
		throw "Array is to small!";
	}
	int k = 0;
	traversInOrder(this->root, result, k);
	
}

template <typename T>
void BinarySearchTree<T>::traversInOrder(Node* root, T theArray[], int &counter) const
{
	
	if (root != nullptr)
	{
		this->traversInOrder(root->leftChild, theArray, counter);

		theArray[counter++] = root->info;

		this->traversInOrder(root->rightChild, theArray, counter);
	}
}
#endif