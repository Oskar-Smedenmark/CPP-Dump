#include "folder.h"
#include "file.h"
#include <sstream>

//Constructors
Folder::Folder() : FileItem()
{
	this->size = 0;
}
Folder::Folder(string name, string path, int size) : FileItem(name, path)
{
	this->size = size;
}
Folder::Folder(const Folder &other)
{
	this->path = other.path;
	this->name = other.name;
	this->size = other.size;
	for (unsigned int i = 0; i < this->items.size(); i++)
	{
		*this->items[i] = *other.items[i];
	}
}
Folder::~Folder()
{
	if (this->items.empty() == false)
	{
		cleanUp();
	}
}

//Getters
string Folder::getName() const
{
	return this->name;
}
string Folder::getPath() const
{
	return this->path;
}
int Folder::getSize() const
{
	return size;
}
FileItem* Folder::getItem(string name) const
{
	FileItem* theItem = nullptr;
	if (this->items.empty() == false)
	{
		for (unsigned int i = 0; i < this->items.size(); i++)
		{
			if (this->items[i]->getName() == name)
			{
				theItem = this->items[i];
			}
		}
	}
	return theItem;
}

//Setters
void Folder::setName(string name)
{
	this->name = name;
}
void Folder::setPath(string path)
{
	this->path = path;
}

//Create functions
#pragma region createFile(string)
/// <summary> Creates a folder </summary>
/// <param name="bar"> String nameOfFolder </param>
/// <returns> Path of the created folder </returns>
string Folder::createFolder(string name)
{
	Folder* newFolder = new Folder(name, this->getPath() + "/" + name, this->getSize());
	this->items.insert(this->items.begin(), newFolder);
	return this->items.back()->getPath();
}
#pragma endregion
string Folder::createFile(string name, int blockNr)
{
	File* newFile = new File(name, this->getPath() + "/" + name, blockNr);
	this->items.push_back(newFile);
	return this->items.back()->getPath();
}

//Deletes a single item(folder or file)
int Folder::deleteItem(string name, vector<int>& blockNrs)
{
	int result = 0;
	Folder* folderPtr = nullptr;
	folderPtr = dynamic_cast<Folder*>(this->getItem(name));

	if (folderPtr != nullptr)
	{
		result = folderPtr->clearContent(blockNrs, *folderPtr);
	}
	else
	{
		File* file = nullptr;
		file = dynamic_cast<File*>(this->getItem(name));
		if (file != nullptr)
		{
			blockNrs.push_back(file->getBlockNr());
			delete file;

			result = 1;
		}
	}
	return result;
}

//Clears content from a map with user input
int Folder::clearContent(vector<int>& blockNrs, Folder folderToDelete)
{
	Folder* folderPtr = nullptr;
	int result = 0;
	if (this->items.empty() == false)
	{
		for (int i = this->items.size() - 1;  0 <= i; i--)
		{
			folderPtr = dynamic_cast<Folder*>(this->getItem(this->items[i]->getName()));
			if (folderPtr != nullptr)
			{
				folderPtr->clearContent(blockNrs, *folderPtr);
				delete this->items[i];
				this->items.pop_back();
				result = 1;
			}
			else
			{
				File* file = nullptr;
				file = dynamic_cast<File*>(this->getItem(this->items[i]->getName()));
				if (file != nullptr)
				{
					blockNrs.push_back(file->getBlockNr());
					delete this->items[i];
					this->items.pop_back();
					result = 1;
				}
			}
		}
		
	}
	return result;
}

//Displays the content of a map
string Folder::getContentIndicators() const
{
	stringstream converter;

	for (unsigned int i = 0; i < this->items.size(); i++)
	{
		converter << this->items[i]->getName() << endl;
	}

	return converter.str();
}

//To string
string Folder::toStringSpecific() const
{
	stringstream converter;
	
	converter << "-----FOLDER-----" << endl;
	converter << "Folder data" << endl << "size: " << this->size << endl;
	converter << "Name: " << this->name << endl << "Path: " << this->path << endl << endl << "Contains: " << endl;
	for (unsigned int i = this->items.size(); i > 0; i--)
	{
		converter << this->items[i - 1]->toString() << endl;
	}
	
	converter << "End of contain list." << endl;
	return converter.str();
}

//Operators
Folder& Folder::operator=(const Folder &other)
{
	if (this != &other)
	{
		this->path = other.path;
		this->name = other.name;
		this->size = other.size;
		for (unsigned int i = 0; i < this->items.size(); i++)
		{
			*this->items[i] = *other.items[i];
		}
	}
	return *this;
}

FileItem* Folder::operator[](const string &itemName) const throw(...)
{
	FileItem* ptr = nullptr;

	ptr = this->getItem(itemName);
	if (ptr == nullptr)
	{
		throw "That item dosen't exist.";
	}
	return ptr;
}

//Help functions
void Folder::cleanUp()
{
	Folder* folderPtr = nullptr;

	for (int i = this->items.size() - 1; 0 <= i; i--)
	{
		folderPtr = dynamic_cast<Folder*>(this->getItem(this->items[i]->getName()));
		if (folderPtr != nullptr)
		{
			folderPtr->cleanUp();
			delete this->items[i];
			this->items.pop_back();
		}
		else
		{		
			delete this->items[i];
			this->items.pop_back();
		}
	}

}