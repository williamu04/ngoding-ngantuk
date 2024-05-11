#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> createRandomArray(int size, int min, int max) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }

    return arr;
}

void randomizeArray(vector<int>& arr) {
    random_device rd;
    mt19937 g(rd());

    for (int i = arr.size() - 1; i > 0; i--) {
        uniform_int_distribution<> dis(0, i);
        int j = dis(g);
        swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> randomArray = createRandomArray(15, 1, 10);
    for (int i = 0; i < randomArray.size(); i++) {
        cout << randomArray[i] << " ";
    }
    randomizeArray(randomArray);
    cout << endl;
    for (int i = 0; i < randomArray.size(); i++) {
        cout << randomArray[i] << " ";
    }
    return 0;
}