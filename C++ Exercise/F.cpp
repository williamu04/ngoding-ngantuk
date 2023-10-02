#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  int to; 
  int len; 
  Edge(int t, int l) : to(t), len(l) {} 
};

int find_min_cable(int V, int E, int a, int b, vector<vector<Edge>> &adj) {
  vector<int> dist(V + 1, -1); 
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, a});
  dist[a] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    int d = p.first;
    int u = p.second;

    if (u == b) break;
    if (d > dist[u]) continue;

    for (Edge e : adj[u]) {
      int v = e.to;
      int w = e.len;

      if (dist[v] == -1 || dist[v] > max(dist[u], w)) {
        dist[v] = max(dist[u], w);
        pq.push({dist[v], v});
      }
    }
  }

  return dist[b];
}

int main() {
  int V, E, a, b;
  cin >> V >> E >> a >> b;

  vector<vector<Edge>> adj(V + 1);

  for (int i = 0; i < E; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back(Edge(y, z));
    adj[y].push_back(Edge(x, z));
  }

  cout << find_min_cable(V, E, a, b, adj) << endl;

  return 0;
}
