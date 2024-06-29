#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class SocialGraph {
private:
    map<string, vector<string>> adjList;

public:
    // Menambahkan mahasiswa baru beserta daftar teman-temannya
    void addStudent(const string& name, const vector<string>& friends) {
        adjList[name] = friends;
        for (const auto& friendName : friends) {
            adjList[friendName].push_back(name);
        }
    }

    // Menambahkan hubungan pertemanan antara dua mahasiswa yang sudah terdaftar
    void addFriendship(const string& student1, const string& student2) {
        adjList[student1].push_back(student2);
        adjList[student2].push_back(student1);
    }

    // Menghapus mahasiswa beserta seluruh hubungan pertemanannya
    void removeStudent(const string& name) {
        for (auto& friendName : adjList[name]) {
            adjList[friendName].erase(remove(adjList[friendName].begin(), adjList[friendName].end(), name), adjList[friendName].end());
        }
        adjList.erase(name);
    }

    // Mencari teman bersama antara dua mahasiswa yang sudah terdaftar
    vector<string> findMutualFriends(const string& student1, const string& student2) {
        vector<string> mutualFriends;
        vector<string> friendsOfStudent1 = adjList[student1];
        vector<string> friendsOfStudent2 = adjList[student2];

        sort(friendsOfStudent1.begin(), friendsOfStudent1.end());
        sort(friendsOfStudent2.begin(), friendsOfStudent2.end());

        set_intersection(friendsOfStudent1.begin(), friendsOfStudent1.end(), friendsOfStudent2.begin(), friendsOfStudent2.end(), back_inserter(mutualFriends));

        return mutualFriends;
    }

    // Menampilkan daftar teman dari seorang mahasiswa tertentu
    void displayFriends(const string& name) {
        if (adjList.find(name) != adjList.end()) {
            cout << "Daftar teman " << name << ": ";
            for (const auto& friendName : adjList[name]) {
                cout << friendName << " ";
            }
            cout << endl;
        } else {
            cout << name << " tidak ditemukan dalam jaringan." << endl;
        }
    }
};

int main() {
    SocialGraph graph;

    // Contoh penggunaan
    graph.addStudent("Andi", {"Budi", "Citra"});
    graph.addFriendship("Andi", "Dedi");
    graph.addFriendship("Budi", "Edi");
    graph.addFriendship("Citra", "Dedi");
    // graph.removeStudent("Budi");
    graph.displayFriends("Andi");
    graph.displayFriends("Budi");
    vector<string> mutualFriends = graph.findMutualFriends("Andi", "Citra");
    cout << "Teman mutual Andi dan Citra: ";
    for (const auto& friendName : mutualFriends) {
        cout << friendName << " ";
    }

    return 0;
}
