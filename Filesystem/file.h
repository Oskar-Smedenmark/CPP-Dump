#ifndef FILE_H
#define FILE_H

#include <string>
#include "fileItem.h"

using namespace std;

class File : public FileItem
{
public:
	File();
	File(string name, string path, int blockNr);
	File(const File &other);
	~File();

	string getName() const;
	string getPath() const;
	int getSize() const;
	int getBlockNr() const;

	void setName(string name);
	void setPath(string path);
	void setBlockNr(int blockNr);

	string toStringSpecific() const;

	File& operator=(const File &other);

private:
	int size;
	int blockNr;

};

#endif