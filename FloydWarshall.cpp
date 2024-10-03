#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define V 4 // Number of vertices in the graph

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = { {0, 3, INF, 7},
                        {8, 0, 2, INF},
                        {5, INF, 0, 1},
                        {2, INF, INF, 0} };

    floydWarshall(graph);
    return 0;
}
