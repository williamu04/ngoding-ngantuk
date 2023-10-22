#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> vek = {4, 6, 3, 8, 1, 9, 7, 2, 5};
    sort(vek.begin(), vek.end());

    for (unsigned int i = 0; i < vek.size(); i++) {
        cout << vek[i];
    }
    return 0;
}
