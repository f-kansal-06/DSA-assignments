#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    cout << "Enter edges (u v w) for an undirected graph:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // weight ignored
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    vector<bool> visited(n + 1, false);

    cout << "DFS traversal: ";
    dfsUtil(start, adj, visited);
    cout << endl;

    return 0;
}
