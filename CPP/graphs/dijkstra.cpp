#include <bits/stdc++.h>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int vertex;
    int weight;
};

/// @brief This it the Dijkstra Algorithm to find the shortest path from a
/// source node to all other nodes in the graph.
/// @param graph The graph represented as an adjacency list
/// @param source The source node from which the shortest distances are to be
/// calculated
/// @return A vector containing the shortest distances from the source node to
/// all other nodes
vector<int> dijkstra(vector<vector<Node>> &graph, int source) {
    int numNodes = graph.size();
    vector<int> distances(numNodes, INT_MAX);
    vector<bool> visited(numNodes, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    // Distance of source node is 0
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // If the node is already visited, skip it
        if (visited[currentNode])
            continue;

        visited[currentNode] = true;

        // Update the distances of adjacent nodes
        for (auto neighbor : graph[currentNode]) {
            int neighborNode = neighbor.vertex;
            int weight = neighbor.weight;

            if (!visited[neighborNode] &&
                currentDistance + weight < distances[neighborNode]) {
                distances[neighborNode] = currentDistance + weight;
                pq.push({distances[neighborNode], neighborNode});
            }
        }
    }

    return distances;
}

int main() {

    vector<vector<Node>> graph(5);

    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({3, 6});
    graph[1].push_back({2, 2});
    graph[2].push_back({4, 4});
    graph[2].push_back({3, 7});
    graph[3].push_back({4, 1});

    vector<int> distances = dijkstra(graph, 0);

    for (int i = 0; i < distances.size(); i++) {
        cout << "Shortest distance from node 0 to node " << i << " is "
             << distances[i] << endl;
    }

    return 0;
}
