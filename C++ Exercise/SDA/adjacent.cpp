#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> perwakilan;

string find(string X) {
    if (perwakilan[X] == X)
        return X;
    return find(perwakilan[X]);
}

void merge(string A, string B) {
    string perwA = find(A);
    string perwB = find(B);
    perwakilan[perwA] = perwB;
}

int main() {
    perwakilan["A"] = "A";
    perwakilan["B"] = "B";
    perwakilan["C"] = "C";
    perwakilan["D"] = "D";
    perwakilan["E"] = "E";

    merge("A", "B");
    merge("B", "C");
    merge("D", "E");
    merge("D", "C");

    if (find("A") == find("D"))
        cout << "A dan C dalam satu jaringan";
    else
        cout << "A dan C tidak dalam satu jaringan";

    return 0;
}
