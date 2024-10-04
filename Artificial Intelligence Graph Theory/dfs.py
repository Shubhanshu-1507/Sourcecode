def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()  # Set to store visited nodes
    
    print(start, end=' ')  # Process the node
    visited.add(start)  # Mark node as visited
    
    # Explore all unvisited neighbors recursively
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}
dfs(graph, 'A')
