#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, weight;
};

/// @brief  This function implements the Prim's algorithm to find the minimum
/// @param n    The number of vertices in the graph
/// @param adj  The graph represented as an adjacency list
/// @return     A vector containing the edges of the minimum spanning tree
vector<Edge> primsAlgorithm(int n, vector<vector<pair<int, int>>> &adj) {
    vector<Edge> result;
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            result.push_back({parent[i], i, key[i]});
        }
    }

    return result;
}

int main() {

    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    vector<Edge> mst = primsAlgorithm(n, adj);

    for (Edge &edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    return 0;
}