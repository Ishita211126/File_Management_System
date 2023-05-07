#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <direct.h>
#include "User.h"
#include "File.h"
#include "FileManager.cpp"
#include "Directory.cpp"


int main() {

    User user("username", "password");

    string choice;
    string filename;
    string  dirname;
    FileManager file("C:\\Users\\Dell\\Desktop\\final_file_manager\\default_file.txt");
    Directory directory("C:\\Users\\Dell\\Desktop\\final_file_manager");


    cout << "Enter your username: ";
    string username;
    getline(cin, username);

    cout << "Enter your password: ";
    string password;
    getline(cin, password);

    if (user.authenticate(username, password))
        {
        cout << "Authentication successful" << endl;

    string choice;
    while (true) {
        cout << endl;
        cout << "1. Create file" << endl;
        cout << "2. Delete file" << endl;
        cout << "3. Modify file" << endl;
        cout << "4. View file" << endl;
        cout << "5. Download file" << endl;
        cout << "6. Copy file" << endl;
        cout << "7. Move file" << endl;
        cout << "8. Create directory" << endl;
        cout << "9. Delete directory" << endl;
        cout << "10. Rename directory" << endl;
        cout << "11. Move directory" << endl;
        cout << "12. Count files "<<endl;
        cout << "13. directory exist"<<endl;
        cout << "14. Search files in directory" << endl;
        cout << "15. List files in directory " <<endl;
        cout << "16. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            FileManager file(fileName);
            if (user.authenticate(username, password)) {
                file.create();
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "2") {
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            FileManager file(fileName);
            if (user.authenticate(username, password)) {
                file.deleteFile();
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "3") {
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            FileManager file(fileName);
            if (user.authenticate(username, password)) {
                file.modify();
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "4") {
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            FileManager file(fileName);
            file.view();
        }
        else if (choice == "5") {
            string fileName, destination;
            cout << "Enter file name: ";
            cin >> fileName;
            FileManager file(fileName);
            if (user.authenticate(username, password)) {
                file.download();
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "6") {
            string fileName, destination;
            cout << "Enter file name: ";
            cin >> fileName;
            cout << "Enter destination path: ";
            cin >> destination;
            FileManager file(fileName);
            if (user.authenticate(username, password)) {
                file.copy(destination);
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "7") {
            string fileName, destination;
            cout << "Enter file name: ";
            cin >> fileName;
            cout << "Enter destination path: ";
            cin >> destination;
            FileManager file(fileName);
            if (user.authenticate(username, password)) {
                file.move(destination);
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice== "8") {
            string dirName;
            cout << "Enter directory name: ";
            cin >> dirName;
            Directory directory(dirName);
            if (user.authenticate(username, password)) {
            directory.create();
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "9") {
            string dirName;
            cout << "Enter directory name: ";
            cin >> dirName;
            Directory directory(dirName);
            if (user.authenticate(username, password)) {
            directory.deleteDirectory();
            }
            else {
                cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "10") {
            string dirName, newDirName;
            cout << "Enter directory name: ";
            cin >> dirName;
            cout << "Enter new directory name: ";
            cin >> newDirName;
            FileManager file(dirName);
            if (user.authenticate(username, password)) {
            directory.Rename(newDirName);
            }
            else {
            cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "11") {
            string dirName, destination;
            cout << "Enter directory name: ";
            cin >> dirName;
            cout << "Enter destination path: ";
            cin >> destination;
            Directory directory(dirName);
            if (user.authenticate(username, password)) {
            directory.moveDirectory(destination);
            }
            else {
            cout << "Invalid username or password" << endl;
            }
        }
        else if (choice == "12") {
            string dirName;
    cout << "Enter directory name: ";
    cin >> dirName;
    Directory directory(dirName);
    if (user.authenticate(username, password)) {
        int numFiles = directory.CountFiles();
        cout << "Number of files in the directory: " << numFiles << endl;
    }
    else {
        cout << "Invalid username or password" << endl;
    }
}


        else if (choice == "13") {
            string dirName;
    cout << "Enter directory name: ";
    cin >> dirName;
    Directory directory(dirName);
    if (user.authenticate(username, password)) {
        if (directory.Exists()) {
            cout << "The directory exists" << endl;
        }
        else {
            cout << "The directory does not exist" << endl;
        }
    }
    else {
        cout << "Invalid username or password" << endl;
    }
}

        else if(choice=="14"){
            string dirName, fileName;
            cout << "Enter directory name: ";
            cin >> dirName;
            cout << "Enter file name: ";
            cin >> fileName;
            Directory directory(dirName);
            if (user.authenticate(username, password)) {
            directory.searchFiles(fileName);
    }
            else {
            cout << "Invalid username or password" << endl;
    }

        }

        else if (choice == "15")
            {
            string dirName;
            cout << "Enter directory name: ";
            cin >> dirName;
            Directory directory(dirName);
            directory.listFiles();
}
        else if (choice == "14") {
            break;
            }
    }
    }        else {
            cout << "Invalid choice" << endl;
            }

        return 0;
        }
