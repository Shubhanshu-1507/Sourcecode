#include <bits/stdc++.h>

using namespace std;

/// @brief  This function performs a depth-first search on the graph
/// @param node The current node
/// @param st   The stack to store the nodes in topological order
/// @param vis  The vector to keep track of visited nodes
/// @param adj  The graph represented as an adjacency list
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

/// @brief  This function performs a depth-first search on the transpose of the
/// @param node         The current node
/// @param vis          The vector to keep track of visited nodes
/// @param transpose    The transpose of the graph
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    vis[node] = 1;
    cout << node << " ";
    for (auto it : transpose[node]) {
        if (!vis[it]) {
            revDfs(it, vis, transpose);
        }
    }
}

/// @brief  This function finds the strongly connected components in a graph
/// @param V    vertices in the graph
/// @param adj  adjacency list of the graph
void kosaraju(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[V];
    for (int i = 0; i < V; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }
}

int main() {

    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    kosaraju(V, adj);

    return 0;
}