#ifndef FILEITEM_H
#define FILEITEM_H
#include <string>
using namespace std;

class FileItem
{
protected:
	string path;
	string name;
public:
    FileItem();
	FileItem(string name, string path);
    FileItem(const FileItem &other);
    virtual ~FileItem();

    virtual string getName()const = 0;
    virtual string getPath()const = 0;

    /* Operators */
    FileItem& operator=(const FileItem &other);

    string toString()const;
	virtual string toStringSpecific() const = 0;
};

#endif // FILEITEM_H
