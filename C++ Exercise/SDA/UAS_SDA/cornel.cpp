/*
Djikstra                15
Kruskal                 15
Queue                   5
Set                     5
Graph                   5
Binary Tree             10
BFS                     15
Bubble Sort             5
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <list>

#if defined(__WIN32)
    #define CLEAR "cls"
#elif defined(__linux__)
    #define CLEAR "clear";
#elif defined(__APPLE__)
    #define CLEAR "clear";
#endif

using namespace std;

struct Book {
    string title;
    string author;

    bool operator<(const Book& other) const {
        if (title != other.title)
            return title < other.title;
        return author < other.author;
    }

    bool operator>(const Book& other) const {
        if (title != other.title)
            return title > other.title;
        return author > other.author;
    }

    bool operator==(const Book& other) const {
        return title == other.title && author == other.author;
    }
};

struct BookNode {
    Book book;
    BookNode* left;
    BookNode* right;

    BookNode(Book book): book(book), left(nullptr), right(nullptr) {}
};

struct BookBST {
    BookNode* root;
    BookBST() : root(nullptr) {}

    void insert(Book book) {
        root = insert(root, book);
    }

    BookNode* insert(BookNode* node, Book book) {
        if (node == nullptr) {
            return new BookNode(book);
        }
        if (book < node->book)
            node->left = insert(node->left, book);
        else if (book > node->book)
            node->right = insert(node->right, book);

        return node;
    }
};

struct BookShelf {
    BookBST bst;
};

struct Node {
    BookShelf bookShelf;
    Node* left;
    Node* right;
};

map<Book, string> bookDetails;
queue<Book> borrowedBooks;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<Node*> nodes;

    Graph(int V) : V(V), adj(V), nodes(V, nullptr) {}

    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    void addNode(int u, BookShelf bookShelf) {
        nodes[u] = new Node();
        nodes[u]->bookShelf = bookShelf;
    }
};

vector<int> dijkstra(const Graph& graph, int start) {
    vector<int> dist(graph.V, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph.adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
            parent[u] = v;
        else {
            parent[v] = u;
            if (rank[u] == rank[v])
                rank[u]++;
        }
    }
};

void bubbleSort(vector<tuple<int, int, int>>& edges) {
    int n = edges.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (get<0>(edges[i]) > get<0>(edges[i + 1])) {
                swap(edges[i], edges[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

vector<tuple<int, int, int>> kruskal(const Graph& graph) {
    vector<tuple<int, int, int>> result;
    vector<tuple<int, int, int>> edges;

    for (int u = 0; u < graph.V; ++u) {
        for (const auto& neighbor : graph.adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            edges.emplace_back(weight, u, v);
        }
    }

    bubbleSort(edges);

    DisjointSet ds(graph.V);
    for (const auto& edge : edges) {
        int u = get<1>(edge);
        int v = get<2>(edge);
        if (ds.find(u) != ds.find(v)) {
            result.push_back(edge);
            ds.unite(u, v);
        }
    }
    return result;
}

void printMST(const Graph &graph, int& energy) {
    energy -= 3;
    system(CLEAR);
    vector<tuple<int, int, int>> mst = kruskal(graph);
    cout << "===========================================" << endl;
    cout << "===== Minimum Spanning Tree Antar Rak =====" << endl;
    cout << "===========================================" << endl;
    for (const auto& edge : mst) {
        int jarak = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        cout << u << " - " << v << " => jarak: " << jarak << endl;
    }
    cout << "===========================================" << endl;
}

BookShelf createBookShelf() {
    BookShelf bookShelf;
    bookShelf.bst.root = nullptr;
    return bookShelf;
}

void addBookToShelf(BookShelf& bookShelf, Book book, string desc){
    bookDetails[book] = desc;
    bookShelf.bst.insert(book);
}


void printBookShelf(BookNode* node) {
    if (node == nullptr) return;

    queue<BookNode*> q;
    q.push(node);

    while (!q.empty()) {
        BookNode* current = q.front();
        q.pop();

        cout << "- " << current->book.title << " by " << current->book.author << endl;

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

void printBooksInRack(const Graph& graph, int rak) {
    if (rak < 0 || rak >= graph.V) {
        cout << "Invalid rak number." << endl;
        return;
    }

    Node* node = graph.nodes[rak];
    if (node == nullptr) {
        cout << "Rak kosong." << endl;
        return;
    }

    cout << "Buku di rak " << rak << ":" << endl;
    printBookShelf(node->bookShelf.bst.root);
}

bool findBook(BookNode* current, string input, Book& book) {
    if (current == nullptr) {
        return false;
    }
    if (current->book.title == input || current->book.author == input) {
        book = current->book;
        return true;
    }
    if (findBook(current->left, input, book)) {
        return true;
    }
    return findBook(current->right, input, book);
}

void displayBorrowedBooks() {
    system(CLEAR);
    cout << "=================================================" << endl;
    cout << "Buku yang dipinjam: " << endl;
    queue<Book> terpinjam = borrowedBooks;
    while (!terpinjam.empty()) {
        Book book = terpinjam.front();
        terpinjam.pop();
        cout << "- " << book.title << " by " << book.author << endl;
    }
    cout << "=================================================" << endl;
}

void rak_n(const Graph& graph, int rak){
    system(CLEAR);
    cout << "=================================================" << endl;
    cout << "Saat ini anda di rak " << rak << endl;
    cout << "=================================================" << endl;
    printBooksInRack(graph, rak);
    cout << "=================================================" << endl;
    
    cout << "Aksi yang bisa anda lakukan: " << endl;
    cout << "1. Lihat detail buku" << endl;
    cout << "2. Pinjam buku" << endl;
    cout << "3. Kembalikan buku" << endl;

    int choice;
    cout << "Masukkan pilihan: ";
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Input invalid.\nSilakan coba lagi: ";
        cin.clear(); 
        cin.ignore();
    }
    
    if (choice == 1) {
        string input;
        cout << "============================================" << endl;
        cout << "Masukkan judul atau penulis buku: ";
        cin.ignore();
        getline(cin, input);

        Node* node = graph.nodes[rak];

        if (node!= nullptr) {
            Book book;
            cout << "============================================" << endl;
            if (findBook(node->bookShelf.bst.root, input, book)) {
                cout << "Detail: \n" << bookDetails[book] << endl;
            } else {
                cout << "Buku tidak ditemukan" << endl;
            }
            cout << "============================================" << endl;
        }
    }else if (choice == 2) {
        string input;
        cout << "============================================" << endl;
        cout << "Masukkan judul atau penulis buku: ";
        cin.ignore();
        getline(cin, input);

        Node* node = graph.nodes[rak];

        if (node != nullptr) {
            Book book;
            if (findBook(node->bookShelf.bst.root, input, book)) {
                if (bookDetails.find(book) != bookDetails.end()) {
                    bool isAlreadyBorrowed = false;
                    queue<Book> terpinjam = borrowedBooks;
                    while (!terpinjam.empty()) {
                        if (terpinjam.front() == book) {
                            isAlreadyBorrowed = true;
                            break;
                        }
                        terpinjam.pop();
                    }
                    if (!isAlreadyBorrowed) {
                        borrowedBooks.push(book);
                        cout << "Buku berhasil dipinjam" << endl;
                    } else {
                        cout << "Buku sudah dipinjam" << endl;
                    }
                } else {
                    cout << "Buku tidak ditemukan" << endl;
                }
            } else {
                cout << "Buku tidak ditemukan" << endl;
            }
        }
    } else if (choice == 3) {
        cout << "============================================" << endl;
        queue<Book> terpinjam = borrowedBooks;
        if (!terpinjam.empty()) {
            cout << "Buku yang dipinjam: " << endl;
            while (!terpinjam.empty()) {
                Book book = terpinjam.front();
                terpinjam.pop();
                cout << "- " << book.title << " by " << book.author << endl;
            }
        } else {
            cout << "Tidak ada buku yang dipinjam" << endl;
            cout << "============================================" << endl;
            return;
        }
        cout << "============================================" << endl;

        string input;
        cout << "Masukkan judul atau penulis buku yang ingin dikembalikan: ";
        cin.ignore();
        getline(cin, input);

        queue<Book> cek = borrowedBooks;
        Book book = cek.front();
        bool found = false;

        if (book.title == input || book.author == input)
        {
            Node* node = graph.nodes[rak];
            if (findBook(node->bookShelf.bst.root, input, book))
            {
                borrowedBooks.pop();
                cout << "Buku berhasil dikembalikan" << endl;
                found = true;
            } else {
                cout << "Buku bukan dari rak ini!" << endl;
                found = true;
            }
        } else {
            cout << "Kembalikan buku sesuai urutan!" << endl;
            found = true;
        }
        
        if (!found) {
            cout << "Buku tidak ditemukan!" << endl;
        }
    }
}

void rak(const Graph& graph, int& energy) {
    system(CLEAR);
    int current_rak = rand() % 5 + 1;
    cout << "=================================================" << endl;
    cout << "Saat ini anda berada di Rak " << current_rak << endl;
    cout << "=================================================" << endl;
    cout << "Berikut adalah rak yang dapat anda kunjungi: " << endl;

    vector<int> shortestPath = dijkstra(graph, current_rak);

    for (int i = 0; i < 6; ++i)
        cout << "Rak " << i << " => jarak: " << shortestPath[i] << endl;

    cout << "=================================================" << endl;


    int rak;
    cout << "Rak yang ingin anda kunjungi [0-5]: ";
    while (!(cin >> rak) || rak < 0 || rak > 5) {
        cout << "Input invalid. Rak harus berada dalam range 0-5 \nSilakan coba lagi: ";
        cin.clear(); 
        cin.ignore();
    }
    
    char lanjut;
    cout << "\nKunjungi rak " << rak << " akan mengurangi energi anda sebesar " << shortestPath[rak] << ", anda yakin melanjutkan? (y/n): ";
    cin >> lanjut;
    if (lanjut == 'y' || lanjut == 'Y'){
        rak_n(graph, rak);
        energy -= shortestPath[rak];
    }
}


void menu(int energy){
    system(CLEAR);
    cout << "============================================" << endl;
    cout << "============ LIBRARY MANAGEMENT ============" << endl;
    cout << "============================================" << endl;
    cout << "Saat ini anda ada di sistem perpustakaan, ada 6 rak buku yang tiap rak menyediakan buku dengan genre yang sama" << endl;
    cout << "Rak 0 : Fiksi" << endl;
    cout << "Rak 1 : Non Fiksi" << endl;
    cout << "Rak 2 : Komik" << endl;
    cout << "Rak 3 : Buku Pelajaran" << endl;
    cout << "Rak 4 : Buku Referensi" << endl;
    cout << "Rak 5 : Buku Koleksi" << endl;
    cout << "============================================" << endl;
    cout << "Energy anda: " << energy << endl;
    cout << "============================================" << endl;
    cout << "1. Kunjungi Rak" << endl;
    cout << "2. Tampilkan MST" << endl;
    cout << "3. Keluar" << endl;
    if (!borrowedBooks.empty()) cout << "4. Tampilkan Buku yang Dipinjam" << endl;
}

int main() {
    srand(time(0));

    int numNodes = 6;
    Graph graph(numNodes);
    graph.addEdge(0, 1, rand() % 5 + 1);
    graph.addEdge(0, 3, rand() % 5 + 1);
    graph.addEdge(1, 2, rand() % 5 + 1);
    graph.addEdge(1, 4, rand() % 5 + 1);
    graph.addEdge(2, 5, rand() % 5 + 1);
    graph.addEdge(3, 4, rand() % 5 + 1);
    graph.addEdge(4, 5, rand() % 5 + 1);
    
    BookShelf rakBuku_0 = createBookShelf();
    addBookToShelf(rakBuku_0, {"Buku 1", "Penulis 1"}, "This is a description of Buku 1");
    addBookToShelf(rakBuku_0, {"Buku 2", "Penulis 2"}, "This is a description of Buku 2");
    addBookToShelf(rakBuku_0, {"Buku 3", "Penulis 3"}, "This is a description of Buku 3");
    addBookToShelf(rakBuku_0, {"Buku 4", "Penulis 4"}, "This is a description of Buku 4");
    graph.addNode(0, rakBuku_0);

    BookShelf rakBuku_1 = createBookShelf();
    addBookToShelf(rakBuku_1, {"Buku 5", "Penulis 5"}, "This is a description of Buku 5");
    addBookToShelf(rakBuku_1, {"Buku 6", "Penulis 6"}, "This is a description of Buku 6");
    addBookToShelf(rakBuku_1, {"Buku 7", "Penulis 7"}, "This is a description of Buku 7");
    addBookToShelf(rakBuku_1, {"Buku 8", "Penulis 8"}, "This is a description of Buku 8");
    graph.addNode(1, rakBuku_1);

    BookShelf rakBuku_2 = createBookShelf();
    addBookToShelf(rakBuku_2, {"Buku 9", "Penulis 9"}, "This is a description of Buku 9");
    addBookToShelf(rakBuku_2, {"Buku 10", "Penulis 10"}, "This is a description of Buku 10");
    addBookToShelf(rakBuku_2, {"Buku 11", "Penulis 11"}, "This is a description of Buku 11");
    addBookToShelf(rakBuku_2, {"Buku 12", "Penulis 12"}, "This is a description of Buku 12");
    graph.addNode(2, rakBuku_2);

    BookShelf rakBuku_3 = createBookShelf();
    addBookToShelf(rakBuku_3, {"Buku 13", "Penulis 13"}, "This is a description of Buku 13");
    addBookToShelf(rakBuku_3, {"Buku 14", "Penulis 14"}, "This is a description of Buku 14");
    addBookToShelf(rakBuku_3, {"Buku 15", "Penulis 15"}, "This is a description of Buku 15");
    addBookToShelf(rakBuku_3, {"Buku 16", "Penulis 16"}, "This is a description of Buku 16");
    graph.addNode(3, rakBuku_3);

    BookShelf rakBuku_4 = createBookShelf();
    addBookToShelf(rakBuku_4, {"Buku 17", "Penulis 17"}, "This is a description of Buku 17");
    addBookToShelf(rakBuku_4, {"Buku 18", "Penulis 18"}, "This is a description of Buku 18");
    addBookToShelf(rakBuku_4, {"Buku 19", "Penulis 19"}, "This is a description of Buku 19");
    addBookToShelf(rakBuku_4, {"Buku 20", "Penulis 20"}, "This is a description of Buku 20");
    graph.addNode(4, rakBuku_4);

    BookShelf rakBuku_5 = createBookShelf();
    addBookToShelf(rakBuku_5, {"Buku 21", "Penulis 21"}, "This is a description of Buku 21");
    addBookToShelf(rakBuku_5, {"Buku 22", "Penulis 22"}, "This is a description of Buku 22");
    addBookToShelf(rakBuku_5, {"Buku 23", "Penulis 23"}, "This is a description of Buku 23");
    addBookToShelf(rakBuku_5, {"Buku 24", "Penulis 24"}, "This is a description of Buku 24");
    graph.addNode(5, rakBuku_5);

    int energy = 20;  

    char lanjut;
    do
    {
        menu(energy);
        if (energy > 0)
        {
            int pilih;
            cout << "Pilih: ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                rak(graph, energy);
                break;
            case 2:
                char cetak;
                cout << "Mencetak Minimum Spanning Tree akan mengurangi energy sebesar 3." << endl;
                cout << "Cetak Minimum Spanning Tree? (y/n): ";
                cin >> cetak;
                if (cetak == 'y' || cetak == 'Y') printMST(graph, energy);
                break;
            case 3: 
                char conf;
                cout << "Akhiri program? (y/n): ";
                cin >> conf;
                if (conf == 'y' || conf == 'Y') return 0;
                break;
            case 4:
                if (!borrowedBooks.empty()) displayBorrowedBooks();
                else cout << "Pilihan tidak valid" << endl;
                break;                
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        } else {
            cout << "Energy anda hari ini habis, kembali lagi besok!" << endl;
            return 0;
        }
        cout << "Kembali ke menu utama dan lanjutkan program? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}
