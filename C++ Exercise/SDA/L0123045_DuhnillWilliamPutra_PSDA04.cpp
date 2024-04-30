#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> usernames;
map<string, string> passwords;

void signUp(string username, string password) {
    if (usernames.find(username) == usernames.end()) {
        usernames.insert(username);
        passwords[username] = password;
        cout << "Sign Up success." << endl;
    } else {
        cout << "Sign Up failed. Username already exists." << endl;
    }
}

void login(string username, string password) {
    if (usernames.find(username)!= usernames.end()) {
        if (passwords[username] == password) {
            cout << "Login success." << endl;
        } else {
            cout << "Login failed. Password is not correct." << endl;
        }
    } else {
        cout << "Login failed. Username not found." << endl;
    }
}

int main() {
    signUp("user1", "password123"); // SignUp success.
    signUp("user2", "hello456"); // SignUp success.
    login("user1", "password123"); // Login success.
    login("user1", "wrongpassword"); // Login failed. Password is not correct.
    login("user3", "password789"); // Login failed. Username not found.
    return 0;
}