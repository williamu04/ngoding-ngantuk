#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sort(const vector<int>& arr) {
    vector<int> result;
    if (arr.size() <= 1) {
        return arr;
    }
    int mid = arr.size() / 2;

    vector<int> kiri = merge_sort(vector<int>(arr.begin(), arr.begin() + mid));
    vector<int> kanan = merge_sort(vector<int>(arr.begin() + mid, arr.end()));

    size_t i = 0, j = 0;
    while (i < kiri.size() && j < kanan.size()) {
        if (kiri[i] < kanan[j]) {
            result.push_back(kiri[i]);
            i++;
        } else {
            result.push_back(kanan[j]);
            j++;
        }
    }
    while (i < kiri.size()) {
        result.push_back(kiri[i]);
        i++;
    }
    while (j < kanan.size()) {
        result.push_back(kanan[j]);
        j++;
    }
    return result;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10, 42, 24, 12, 26, 11, 98, 23, 62, 72, 5, 15, 72, 16, 15, 31, 17, 3, 50, 51, 27, 74, 72, 13, 42, 68, 16, 75, 89, 4, 39, 82, 5, 5, 68, 61, 2, 64, 95, 12, 83, 85, 30, 92, 20, 36, 40, 66, 13, 8, 31, 4, 68, 98, 100, 58, 46, 22, 43, 99, 81, 75, 77, 82, 82, 128, 448, 451, 79, 581, 332, 805, 721, 934, 18, 96, 834, 372, 691, 117, 489, 385, 132, 337, 562, 332, 733, 75, 697, 507, 818, 83, 106, 175, 421, 933, 512, 18, 302, 650, 379, 163, 691, 144, 305, 940, 307, 532, 393, 280, 3, 385, 545, 626, 949, 133};
    vector<int> sorted = merge_sort(arr);
    for (size_t i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << endl;
    }
    cout << endl;
    return 0;
}