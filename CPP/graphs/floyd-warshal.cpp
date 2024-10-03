#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> floydWarshall(int vertices, vector<vector<int>> &graph) {

    vector<vector<int>> dist = graph;

    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return dist;
}

int main() {

    int vertices = 4;

    vector<vector<int>> graph = {{0, 5, INT_MAX, 10},
                                 {INT_MAX, 0, 3, INT_MAX},
                                 {INT_MAX, INT_MAX, 0, 1},
                                 {INT_MAX, INT_MAX, INT_MAX, 0}};

    floydWarshall(vertices, graph);

    return 0;
}
