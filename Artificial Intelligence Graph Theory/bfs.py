from collections import deque

def bfs(graph, start):
    visited = set()  # To keep track of visited nodes
    queue = deque([start])  # Queue for BFS, starting from the start node

    while queue:
        node = queue.popleft()  # Pop the leftmost element (FIFO)
        
        if node not in visited:
            print(node, end=' ')  # Process node
            visited.add(node)  # Mark node as visited
            
            # Add all unvisited neighbors to the queue
            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}
bfs(graph, 'A')
