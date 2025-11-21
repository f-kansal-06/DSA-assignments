#include <iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    cout << "Enter edges (u v w) for an undirected graph:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int src;
    cout << "Enter source vertex for Dijkstra: ";
    cin >> src;

    vector<int> dist(n + 1, INF);
    dist[src] = 0;

    // min-heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d != dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int v = 1; v <= n; ++v) {
        if (dist[v] == INF)
            cout << "Vertex " << v << " : INF (unreachable)\n";
        else
            cout << "Vertex " << v << " : " << dist[v] << "\n";
    }

    return 0;
}
