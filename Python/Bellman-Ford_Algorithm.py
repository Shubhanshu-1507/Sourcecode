def bellman_ford(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0

    for _ in range(len(graph) - 1):
        for vertex in graph:
            for neighbor, weight in graph[vertex].items():
                if distances[vertex] + weight < distances[neighbor]:
                    distances[neighbor] = distances[vertex] + weight

    # Check for negative weight cycles
    for vertex in graph:
        for neighbor, weight in graph[vertex].items():
            if distances[vertex] + weight < distances[neighbor]:
                raise ValueError("Graph contains a negative weight cycle")

    return distances

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'C': -3, 'D': 2},
    'C': {'D': 3},
    'D': {}
}

print(bellman_ford(graph, 'B'))
