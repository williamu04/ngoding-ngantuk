#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

stack<int> tumpukan; // Create a stack data structure named 'tumpukan'
queue<int> antrian;   // Create a queue data structure named 'antrian'

// Function to convert user input to a corresponding code number
int condition(string s) {
    if (s == "PUSH 0") {
        return 1;
    } else if (s == "PUSH 1") {
        return 2;
    } else if (s == "TOP") {
        return 3;
    } else if (s == "POP") {
        return 4;
    } else {
        return 0;
    }
}

int main() {
    string input;

    // Request user input and display available commands
    cout << "Masukkan perintah ke komputer Pak Dengklek" << endl;
    cout << "1. PUSH 0 untuk menambahkan 0 ke stack \n2. PUSH 1 untuk menambahkan 1 ke stack \n3. TOP untuk menampilkan elemen teratas stack \n4. POP untuk mengeluarkan elemen teratas stack" << endl;

    int jumlah;
    cout << "Masukkan jumlah perintah: "; // Request the number of commands
    cin >> jumlah;
    cin.ignore(); // Ignore the remaining newline character

    while (jumlah > 0) { // Loop to process each command
        getline(cin, input);
        jumlah--;

        switch (condition(input)) {
            case 1:
                tumpukan.push(0); // Add 0 to the stack
                break;
            case 2:
                tumpukan.push(1); // Add 1 to the stack
                break;
            case 3:
                antrian.push(tumpukan.top()); // Add the top element of the stack to the queue
                break;
            case 4:
                tumpukan.pop(); // Remove the top element from the stack
                break;
            default:
                break;
        }
    }

    // Display the contents of the queue
    cout << "isi: ";
    while (!antrian.empty()) {
        cout << antrian.front(); // Print the front element of the queue
        antrian.pop(); // Remove the front element from the queue
    }

    return 0;
}