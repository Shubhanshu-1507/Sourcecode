import heapq

def ucs(graph, start, goal):
    # Priority queue to store (cost, node) pairs
    queue = [(0, start)]  # (cost, node)
    visited = set()  # Set to keep track of visited nodes
    while queue:
        cost, node = heapq.heappop(queue)  # Pop node with the lowest cost
        
        if node == goal:
            print(f"Goal {goal} reached with cost {cost}")
            return cost
        
        if node not in visited:
            visited.add(node)  # Mark node as visited
            
            # Expand neighbors with their respective costs
            for neighbor, weight in graph[node]:
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor))
    
    return float('inf')  # If goal is not reachable

# Example usage
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('D', 2), ('E', 5)],
    'C': [('A', 4), ('F', 3)],
    'D': [('B', 2)],
    'E': [('B', 5), ('F', 1)],
    'F': [('C', 3), ('E', 1)]
}
ucs(graph, 'A', 'F')
