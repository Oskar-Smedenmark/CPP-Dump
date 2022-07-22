#include "Huffman.h"

Huffman::Huffman()
{
	this->root = nullptr;
	this->nrOfNodes = 0;
}
Huffman::~Huffman()
{
	this->freeMemory(this->root);
}
void Huffman::freeMemory(Node* root)
{
	if (root != nullptr)
	{
		this->freeMemory(root->leftChild);

		this->freeMemory(root->rightChild);

		delete root;
	}
}

void Huffman::insert(string aString)
{
	int stringLength = aString.length();
	int frequency = 0;
	char theChar = ' ';

	bool alreadyExists = false;
	
	Node* walker = this->root;
	Node* parentWalker = this->root;

	for (int i = 0; i < stringLength; i++)
	{
		if (aString[i] != theChar)
		{
			theChar = aString[i];
		}

		if (!this->exists(this->root, theChar))
		{
			for (int j = 0; j < stringLength; j++)
			{
				if (aString[j] == theChar)
				{
					frequency++;
				}
			}
			Node* e = new Node(frequency, theChar);

			if (root == nullptr)
			{
				this->root = e;
			}
			else
			{
				//Inget binärt sökträd Oskar!
				while (walker != nullptr)
				{
					parentWalker = walker;
					if (frequency < parentWalker->value)
					{
						walker = walker->leftChild;
					}
					else
					{
						walker = walker->rightChild;
					}
				}
				if (frequency < parentWalker->value)
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
	}
}
bool Huffman::exists(Node* root, char character) const
{
	bool result = false;

	if (root != nullptr)
	{
		this->exists(root->leftChild, character);
		if (root->leftChild->character == character)
		{
			result = true;
		}

		this->exists(root->rightChild, character);
		if (root->rightChild->character == character)
		{
			result = true;
		}
	}
	return result;
}

void Huffman::compress()
{

}