#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    // adjacency list for unweighted BFS (we ignore weights)
    vector<vector<int>> adj(n + 1);

    cout << "Enter edges (u v w) for an undirected graph:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;   // read w but don't use it
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;

    return 0;
}
