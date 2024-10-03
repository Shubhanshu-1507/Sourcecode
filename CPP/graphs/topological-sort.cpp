#include <bits/stdc++.h>

using namespace std;

/// @brief  This function performs a depth-first search on the graph
/// @param v        The current node
/// @param visited  The vector to keep track of visited nodes
/// @param Stack    The stack to store the nodes in topological order
/// @param adj      The graph represented as an adjacency list
void helper(int v, vector<bool> &visited, stack<int> &Stack,
            const vector<vector<int>> &adj) {
    visited[v] = true;

    for (int i : adj[v])
        if (!visited[i])
            helper(i, visited, Stack, adj);

    Stack.push(v);
}

/// @brief  This function performs a topological sort on the graph
/// @param V    vertices in the graph
/// @param adj  adjacency list of the graph
void topologicalSort(int V, const vector<vector<int>> &adj) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            helper(i, visited, Stack, adj);

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort of the given graph: ";
    topologicalSort(V, adj);

    return 0;
}