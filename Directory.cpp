#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <direct.h>
#include "User.h"

// A class representing a directory
class Directory {
private:
    string path;
public:
     Directory(string dirName) {
    path = "C:\\Users\\Dell\\Desktop\\final_file_manager\\Directory_" + dirName;
}

    // A Function to Create the directory
    bool create() {
        if (CreateDirectory(path.c_str(), NULL)) {
            cout << "Directory created successfully" << endl;
            return true;
        }
        else {
            cout << "Error creating directory" << endl;
            return false;
        }
    }
    // A Function to Delete the directory
    bool deleteDirectory() {
        if (RemoveDirectory(path.c_str())) {
            cout << "Directory deleted successfully." << endl;
            return true;
        }
        else {
            cout << "Failed to delete directory. Error code: " << GetLastError() << endl;
            return false;
        }
    }
    // A Function to Rename the directory
    bool Rename(string newName) {
    string newPath = path.substr(0, path.find_last_of("\\/")) + "\\" + newName;
    if (MoveFileEx(path.c_str(), newPath.c_str(), MOVEFILE_REPLACE_EXISTING)) {
        path = newPath;
        cout << "Folder renamed successfully." << endl;
        return true;
    }
    else {
        cout << "Failed to rename folder. Error code: " << GetLastError() << endl;
        return false;
    }
    }


    // A Function to Move the directory to the given destination
    bool moveDirectory(string destination) {
        if (MoveFileEx(path.c_str(), destination.c_str(), MOVEFILE_REPLACE_EXISTING)) {
            path = destination;
            cout << "Directory moved successfully." << endl;
            return true;
        }
        else {
            cout << "Failed to move directory. Error code: " << GetLastError() << endl;
            return false;
        }
    }
    // A Function to check if the directory exists or not
    bool Exists() {
        DWORD attributes = GetFileAttributesA(path.c_str());
        if (attributes == INVALID_FILE_ATTRIBUTES) {
            return false;
        }
        return (attributes & FILE_ATTRIBUTE_DIRECTORY);
    }
    // A Function to list all the files inside the directory
    void listFiles() {
        WIN32_FIND_DATAA fileData;
        HANDLE hFind;
        string searchPath = path + "\\*";
        hFind = FindFirstFileA(searchPath.c_str(), &fileData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                cout << fileData.cFileName << endl;
            } while (FindNextFileA(hFind, &fileData));
            FindClose(hFind);
        }
        else {
            cout << "Failed to list files. Error code: " << GetLastError() << endl;
        }
    }   // A Function to search a file present in the directory
        void searchFiles(string fileName) {
    WIN32_FIND_DATAA fileData;
    HANDLE hFind;
    string searchPath = path + "\\*.*";
    hFind = FindFirstFileA(searchPath.c_str(), &fileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (strstr(fileData.cFileName, fileName.c_str()) != NULL) {
                cout << "File found: " << fileData.cFileName << endl;
                FindClose(hFind);
                return;
            }
        } while (FindNextFileA(hFind, &fileData) != 0);
        cout << "File not found" << endl;
        FindClose(hFind);
    }
    else {
        cout << "Error searching for file" << endl;
    }
}

    // A Function to Count the number of files
    int CountFiles() {
        int count = 0;
        WIN32_FIND_DATAA fileData;
        HANDLE hFind;
        string searchPath = path + "\\*";
        hFind = FindFirstFileA(searchPath.c_str(), &fileData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (!(fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    count++;
                }
            } while (FindNextFileA(hFind, &fileData));
            FindClose(hFind);
        }
        else {
            cout << "Failed to count files. Error code: " << GetLastError() << endl;
        }
        return count;
    }
};
