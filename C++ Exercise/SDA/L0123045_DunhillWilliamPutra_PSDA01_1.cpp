#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Define a vector of strings named 'daftar' containing fruit names
    vector<string> daftar = {
        "Rambutan", "Jambu", "Jeruk", "Melon", "Semangka", "Durian"
    };

    // Create two new vectors using the 'daftar' vector's iterators
    // 'list1' contains the first three elements of 'daftar'
    vector<string> list1(daftar.begin(), daftar.begin()+3);
    // 'list2' contains the remaining elements of 'daftar'
    vector<string> list2(daftar.begin()+3, daftar.end());

    // Remove the last element of both 'list1' and 'list2'
    list1.pop_back();
    list2.pop_back();

    // Print the entire 'daftar' vector
    cout << "Seluruh List: " << endl;
    for (string i : daftar) {
        cout << i << endl;
    }

    // Print the 'list1' vector
    cout << "List 1: " << endl;
    for (string i : list1) {
        cout << i << endl;
    }

    // Print the 'list2' vector
    cout << "List 2: " << endl;
    for (string i : list2) {
        cout << i << endl;
    }
}