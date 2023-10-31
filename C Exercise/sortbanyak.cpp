#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    srand(time(NULL));
    vector<int> yes;

    for (int i = 0; i < 10; i++)
    {        
        yes[i] = rand() % 1000 + 1;
    }
    
    sort(yes.begin(), yes.end());

    cout << yes[2];
}