#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bubblesort(vector<pair<string, pair<int, string>>>& list) {
    int n = list.size();
    for(int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (list[j].first > list[j+1].first) {
                swap(list[j], list[j+1]);
            }
        }
    }
}

void selectionsort(vector<pair<string, pair<int, string>>>& list) {
    int n = list.size();
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (list[j].first < list[min_idx].first) {
                min_idx = j;
            }
        }
        swap(list[min_idx], list[i]);
    }
}

void insertionsort(vector<pair<int, pair<string, string>>>& list) {
    int n = list.size();
    for (int i = 1; i < n; i++) {
        pair<int, pair<string, string>> key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j].first > key.first) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}

int main(){
    vector<string> judul = {"Indonesia Raya", "Never Gonna Give You Up", "Everything Is Awesome", "I Want It That Way", "Balonku"};
    vector<string> artis = {"Wage Rudolf Supratman", "Rick Asley", "Tegann and Sara", "Backstreet Boys", "Abdullanh Totong Mahmud"};
    vector<int> durasi = {111, 213, 164, 220, 180};

    vector<pair<int, pair<string, string>>> list_durasi;
    vector<pair<string, pair<int, string>>> list_judul;
    vector<pair<string, pair<int, string>>> list_artis;

    for(unsigned int i = 0; i < judul.size(); i++) {
        list_judul.push_back(make_pair(judul[i], make_pair(durasi[i], artis[i])));
        list_artis.push_back(make_pair(artis[i], make_pair(durasi[i], judul[i])));
        list_durasi.push_back(make_pair(durasi[i], make_pair(judul[i], artis[i])));
    }
    
    bubblesort(list_judul);
    selectionsort(list_artis);
    insertionsort(list_durasi);

    cout << "Terurut Judul (bubblesort): " << endl;
    for(auto& song : list_judul) {
        cout << song.first << "  --  " << song.second.second << "  --  " << song.second.first << " detik" << endl;
    }

    cout << "\nTerurut Artis (selectionsort): " << endl;
    for(auto& song : list_artis) {
        cout << song.first << "  --  " << song.second.second << "  --  " << song.second.first << " detik" << endl;
    }

    cout << "\nTerurut Durasi (insertionsort): " << endl;
    for(auto& song : list_durasi) {
        cout << song.second.first << "  --  " << song.second.second << "  --  " << song.first << " detik" << endl;
    }

    return 0;
}
