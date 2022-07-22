#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>
#include "fileItem.h"

using namespace std;

class Folder : public FileItem
{
public:
	Folder();
	Folder(string name, string path, int size);
	Folder(const Folder &other);
	~Folder();

	string getName() const;
	string getPath() const;
	int getSize() const;
	FileItem* getItem(string name) const;

	void setName(string name);
	void setPath(string path);

	string createFolder(string name);
	string createFile(string name, int blockNr);
	
	int deleteItem(string name, vector<int>& blockNrs);

	int clearContent(vector<int>& blockNrs, Folder folderToDelete);

	string getContentIndicators() const;
	string toStringSpecific() const;

	Folder& operator=(const Folder &other);
	FileItem* operator[](const string &itemName) const throw(...);

private:
	int size;
	vector<FileItem*> items;

	void cleanUp();
};

#endif