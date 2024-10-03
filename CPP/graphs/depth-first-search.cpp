#include <bits/stdc++.h>

using namespace std;

/// @brief  This function performs a depth-first search on the graph
/// @param node     The current node
/// @param vis      The vector to keep track of visited nodes
/// @param adj      The graph represented as an adjacency list
/// @param storeDfs The vector to store the nodes in DFS order
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
    storeDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, storeDfs);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> storeDfs;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, storeDfs);
        }
    }

    for (auto i : storeDfs) {
        cout << i << " ";
    }

    return 0;
}