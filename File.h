#ifndef FILE_H
#define FILE_H


#include <string>

using namespace std;

//  An abstract base class for file management operations
class File {
protected:
    string fileName;
public:
    File(string name)
    {
        fileName = name;
    }
    virtual bool create() = 0;
    virtual bool deleteFile() = 0;
    virtual bool modify() = 0;
    virtual void view() = 0;
    virtual bool download() = 0;
    virtual bool copy(string destination) = 0;
    virtual bool move(string destination) = 0;
};
#endif // FILE_H

