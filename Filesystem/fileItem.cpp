#include "fileItem.h"
#include <sstream>

using namespace std;

//Constructors
FileItem::FileItem()
{
	this->path = "";
	this->name = "";
}
FileItem::FileItem(string name, string path)
{
	this->name = name;
	this->path = path;
}
FileItem::FileItem(const FileItem &other)
{
	this->path = other.path;
	this->name = other.name;
}
FileItem::~FileItem()
{

}
//Getters
string FileItem::getName() const
{
	return this->name;
}
string FileItem::getPath() const
{
	return this->path;
}

//To string
string FileItem::toString()const
{
	stringstream converter;
	converter << this->toStringSpecific() << endl;

	return converter.str();
}

/* Operators */
FileItem& FileItem::operator=(const FileItem &other)
{
	if (this != &other)
	{
		this->path = other.path;
		this->name = other.name;
	}
	return *this;
}