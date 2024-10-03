#include <bits/stdc++.h>

using namespace std;

/// @brief  This function performs a breadth-first search on the graph
/// @param graph    The graph represented as an adjacency list
/// @param source   The source node from which the traversal starts
void bfs(vector<vector<int>> &graph, int source) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    vector<vector<int>> graph(5);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);
    graph[4].push_back(4);

    cout << "Breadth First Traversal starting from node 2: ";
    bfs(graph, 2);

    return 0;
}