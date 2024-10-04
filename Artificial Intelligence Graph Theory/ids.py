def dls(graph, node, target, depth):
    # Depth-limited search helper function
    if depth == 0 and node == target:
        return True
    if depth > 0:
        for neighbor in graph[node]:
            if dls(graph, neighbor, target, depth - 1):
                return True
    return False

def ids(graph, start, target, max_depth):
    # Iterative deepening search
    for depth in range(max_depth):
        if dls(graph, start, target, depth):
            print(f"Target {target} found at depth {depth}")
            return True
    print("Target not found within max depth")
    return False

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}
ids(graph, 'A', 'F', 3)
