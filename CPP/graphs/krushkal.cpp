#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, weight;
};

/// @brief This function compares two edges based on their weights
/// @param a    The first edge
/// @param b    The second edge
/// @return True if the weight of the first edge is less than the weight of the
bool compareEdges(Edge a, Edge b) { return a.weight < b.weight; }

int findParent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

/// @brief This function merges two nodes into the same set
/// @param parent   The parent array representing the disjoint set
/// @param rank     The rank array representing the disjoint set
/// @param u        The first node
/// @param v        The second node
void unionNodes(vector<int> &parent, vector<int> &rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

/// @brief  This function implements the Kruskal algorithm to find the minimum
/// @param edges    The edges of the graph
/// @param n        The number of vertices in the graph
/// @return         A vector containing the edges of the minimum spanning tree
vector<Edge> kruskal(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    for (Edge &edge : edges) {
        if (findParent(parent, edge.u) != findParent(parent, edge.v)) {
            mst.push_back(edge);
            unionNodes(parent, rank, edge.u, edge.v);
        }
    }
    return mst;
}

int main() {

    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    vector<Edge> mst = kruskal(edges, n);

    for (Edge &edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    return 0;
}