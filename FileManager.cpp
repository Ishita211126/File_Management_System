#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <direct.h>
#include "File.h"

// A FileManager class  derived from File class, implements file management operations
class FileManager : public File {
private:
    string fileData;
public:
    FileManager(string name) : File(name) {}

    // Function to create a new file
    bool create() {
        ofstream file(fileName.c_str());
        if (file.good()) {
            file.close();
            cout << "File created successfully" << endl;
            return true;
        }
        else {
            cout << "Error creating file" << endl;
            return false;
        }
    }
    // Function to delete a file
    bool deleteFile() {
        if (DeleteFile(fileName.c_str())) {
            cout << "File deleted successfully" << endl;
            return true;
        }
        else {
            cout << "Error deleting file" << endl;
            return false;
        }
    }
    // Function to modify a file
    bool modify() {
        string newData;
        cout << "Enter new data to be written to the file: ";
        cin.ignore();
        getline(cin, newData);
        ofstream file(fileName.c_str());
        if (file.good()) {
            file << newData;
            file.close();
            cout << "File modified successfully" << endl;
            return true;
        }
        else {
            cout << "Error modifying file" << endl;
            return false;
        }
    }

    // Function to view a file
    void view() {
        ifstream file(fileName.c_str());
        if (file.good()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            cout << "Error opening file" << endl;
        }
    }
    // Function to download a file to a specified destination folder
    bool download() {
        string destination;
        cout << "Enter the destination folder path: ";
        getline(cin, destination);
        string newFileName = destination + "\\" + fileName;
        if (CopyFile(fileName.c_str(), newFileName.c_str(), false)) {
            cout << "File downloaded successfully" << endl;
            return true;
        }
        else {
            cout << "Error downloading file" << endl;
            return false;
        }
    }
    // A Function to Copy the file to a specified destination
    bool copy(string destination) {
        string newFileName = destination + "\\" + fileName;
        if (CopyFile(fileName.c_str(), newFileName.c_str(), false)) {
            cout << "File copied successfully" << endl;
            return true;
        }
        else {
            cout << "Error copying file" << endl;
            return false;
        }
    }
    // Move the file to a specified destination
    bool move(string destination) {
        string newFileName = destination + "\\" + fileName;
        if (MoveFile(fileName.c_str(), newFileName.c_str())) {
            cout << "File moved successfully" << endl;
            return true;
        }
        else {
            cout << "Error moving file" << endl;
            return false;
        }
    }
};
