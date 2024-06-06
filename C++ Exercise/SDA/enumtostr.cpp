#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

enum nama {
    Andi, 
    Bobi, 
    Caca
};

int main(){
    string namaStr = to_string(static_cast<enum nama>(0));

    cout << namaStr;

}