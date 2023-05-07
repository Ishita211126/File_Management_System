#ifndef USER_H
#define USER_H
#include <string>

using namespace std;


// User class for user authentication
class User {
private:
    string username;
    string password;
public:
    User(string u = "default_username", string p = "default_password") { // Function to authenticate user with a given username and password
        username = u;
        password = p;
    }
    bool authenticate(string u, string p) {
        return (username == u && password == p);
    }
};
#endif
