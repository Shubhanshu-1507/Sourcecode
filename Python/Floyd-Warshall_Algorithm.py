def floyd_warshall(graph):
    dist = {v: {u: float('infinity') for u in graph} for v in graph}
    for v in graph:
        dist[v][v] = 0
        for u, w in graph[v].items():
            dist[v][u] = w

    for k in graph:
        for i in graph:
            for j in graph:
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

graph = {
    'A': {'B': 3, 'C': 8, 'E': -4},
    'B': {'D': 1, 'E': 7},
    'C': {'B': 4},
    'D': {'A': 2, 'C': -5},
    'E': {'D': 6}
}

print(floyd_warshall(graph))
