#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void merge(vector<pair<int, pair<string, string>>>& list_durasi, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, pair<string, string>>> left_list, right_list;

    for (int i = 0; i < n1; i++) {
        left_list.push_back(list_durasi[left + i]);
    }

    for (int i = 0; i < n2; i++) {
        right_list.push_back(list_durasi[mid + 1 + i]);
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (left_list[i].first <= right_list[j].first) {
            list_durasi[k] = left_list[i];
            i++;
        } else {
            list_durasi[k] = right_list[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list_durasi[k] = left_list[i];
        i++;
        k++;
    }

    while (j < n2) {
        list_durasi[k] = right_list[j];
        j++;
        k++;
    }
}

void merge_sort(vector<pair<int, pair<string, string>>>& list_durasi, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(list_durasi, left, mid);
        merge_sort(list_durasi, mid + 1, right);

        merge(list_durasi, left, mid, right);
    }
}

int main(){
    vector<string> judul = {"Indonesia Raya", "Never Gonna Give You Up", "Everything Is Awesome", "I Want It That Way", "Balonku"};
    vector<string> artis = {"Wage Rudolf Supratman", "Rick Asley", "Tegann and Sara", "Backstreet Boys", "Abdullanh Totong Mahmud"};
    vector<int> durasi = {111, 213, 164, 220, 180};

    vector<pair<int, pair<string, string>>> list_durasi;

    for(unsigned int i = 0; i < judul.size(); i++) {
        list_durasi.push_back(make_pair(durasi[i], make_pair(judul[i], artis[i])));
    }

    merge_sort(list_durasi, 0, list_durasi.size() - 1);

    cout << "Sorted list Lagu menggunakan Merge Sort:" << endl;
    for (auto& item : list_durasi) {
        cout << "Durasi: " << item.first << "    Title: " << item.second.first << "    Artist: " << item.second.second << endl;
    }

    return 0;
}