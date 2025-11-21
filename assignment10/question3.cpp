#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// ------------ DSU for Kruskal ------------
struct DSU {
    vector<int> parent, rnk;
    DSU(int n = 0) {
        parent.resize(n + 1);
        rnk.assign(n + 1, 0);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) mat[i][i] = 0;

    cout << "Enter edges (u v w) for an undirected graph:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        // for Prim adjacency matrix
        mat[u][v] = min(mat[u][v], w);
        mat[v][u] = min(mat[v][u], w);
    }

    // ------------ Kruskal's MST ------------
    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) { return a.w < b.w; });

    DSU dsu(n);
    int weightK = 0;
    vector<Edge> mstK;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mstK.push_back(e);
            weightK += e.w;
        }
    }

    cout << "\nKruskal's MST edges:\n";
    for (auto &e : mstK) {
        cout << e.u << " -- " << e.v << "  weight = " << e.w << "\n";
    }
    cout << "Total weight (Kruskal) = " << weightK << "\n";

    // ------------ Prim's MST ------------
    int start = 1; // you can change this
    vector<int> key(n + 1, INF), parent(n + 1, -1);
    vector<bool> inMST(n + 1, false);

    key[start] = 0;

    for (int count = 1; count <= n; ++count) {
        int u = -1, best = INF;
        for (int v = 1; v <= n; ++v) {
            if (!inMST[v] && key[v] < best) {
                best = key[v];
                u = v;
            }
        }
        if (u == -1) break; // disconnected
        inMST[u] = true;

        for (int v = 1; v <= n; ++v) {
            if (!inMST[v] && mat[u][v] < key[v]) {
                key[v] = mat[u][v];
                parent[v] = u;
            }
        }
    }

    int weightP = 0;
    cout << "\nPrim's MST edges:\n";
    for (int v = 1; v <= n; ++v) {
        if (parent[v] != -1) {
            cout << parent[v] << " -- " << v
                 << "  weight = " << mat[parent[v]][v] << "\n";
            weightP += mat[parent[v]][v];
        }
    }
    cout << "Total weight (Prim) = " << weightP << "\n";

    return 0;
}
