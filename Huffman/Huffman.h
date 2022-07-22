#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "PriorityQueue.h"
#include <string>

using namespace std;

class Huffman
{
public:
	Huffman();
	virtual ~Huffman();

	void insert(string aString);

	void compress();

private:
	PriorityQueue<char> theQueue;

	class Node
	{
	public:
		int value;
		char character;
		Node* leftChild;
		Node* rightChild;
		Node(int value) { this->value = value; this->leftChild = nullptr; this->rightChild = nullptr;}
		Node(int value, char character) { this->value = value; this->character = character; this->leftChild = nullptr; this->rightChild = nullptr;}
		virtual ~Node() {}
	};
	int nrOfNodes;
	Node* root;

	void freeMemory(Node* root);
	bool exists(Node* root, char character) const;
};

#endif