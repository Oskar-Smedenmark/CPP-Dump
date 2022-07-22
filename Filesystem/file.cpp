#include "file.h"
#include <sstream>
#include <fstream>

//Constructors
File::File()
{
	this->size = 0;
	this->blockNr = -1;
}
File::File(string name, string path, int blockNr) : FileItem(name, path)
{
	this->size = 0;
	this->blockNr = blockNr;
}
File::File(const File &other)
{
	this->path = other.path;
	this->name = other.name;
	this->size = other.size;
	this->blockNr = other.blockNr;
}
File::~File()
{

}

//Getters
string File::getName() const
{
	return this->name;
}
string File::getPath() const
{
	return this->path;
}
int File::getSize() const
{
	return size;
}
int File::getBlockNr() const
{
	return this->blockNr;
}

//Setters
void File::setName(string name)
{
	this->name = name;
}
void File::setPath(string path)
{
	this->path = path;
}
void File::setBlockNr(int blockNr)
{
	this->blockNr = blockNr;
}

//To string
string File::toStringSpecific() const
{
	stringstream converter;
	converter << "-----FILE-----" << endl << "Name: " << this->name << endl << "Path: " << this->path << endl << "Size: " << this->size << endl << "BlockNr: " << this->blockNr << endl;

	return converter.str();
}

//Operators
File& File::operator=(const File &other)
{
	if (this != &other)
	{
		this->path = other.path;
		this->name = other.name;
		this->size = other.size;
		this->blockNr = other.blockNr;
	}
	return *this;
}