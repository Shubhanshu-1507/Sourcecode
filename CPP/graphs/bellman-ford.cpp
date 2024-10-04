#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, weight;
};

/// @brief  This function implements the Bellman-Ford algorithm to find the
/// @param vertices  The number of vertices in the graph
/// @param edges  The number of edges in the graph
/// @param graph  The graph represented as an adjacency list
/// @param source  The source node from which the shortest distances are to be
/// calculated
/// @return A vector containing the shortest distances from the source node to
/// all other nodes in the graph or an empty vector if the graph contains a
/// negative weight cycle
vector<int> bellmanFord(int vertices, int edges, vector<Edge> &graph,
                        int source) {

    vector<int> distances(vertices, INT_MAX);
    distances[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = graph[j].u;
            int v = graph[j].v;
            int weight = graph[j].weight;

            if (distances[u] != INT_MAX &&
                distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    for (int i = 0; i < edges; i++) {
        int u = graph[i].u;
        int v = graph[i].v;
        int weight = graph[i].weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return {};
        }
    }

    for (int i = 0; i < vertices; i++) {
        cout << "Distance from source to " << i << " is " << distances[i]
             << endl;
    }

    return distances;
}

int main() {

    int vertices = 5;
    int edges = 8;

    vector<Edge> graph;
    graph.push_back({0, 1, -1});
    graph.push_back({0, 2, 4});
    graph.push_back({1, 2, 3});
    graph.push_back({1, 3, 2});
    graph.push_back({1, 4, 2});
    graph.push_back({3, 2, 5});
    graph.push_back({3, 1, 1});
    graph.push_back({4, 3, -3});

    vector<int> distances = bellmanFord(vertices, edges, graph, 0);

    return 0;
}
