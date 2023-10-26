class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        indegree = [0] * n  # Initialize in-degree of all nodes to 0
        
        # Build the in-degree array in a single pass
        for i in range(n):
            if leftChild[i] != -1:
                indegree[leftChild[i]] += 1
            if rightChild[i] != -1:
                indegree[rightChild[i]] += 1
        
        # Find the root (node with in-degree 0)
        root = None
        for i in range(n):
            if indegree[i] == 0:
                if root is None:
                    root = i
                else:
                    return False  # More than one root
        
        # If there's no root
        if root is None:
            return False
        
        visited = [False] * n
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            if visited[node]:
                return False  # Already visited this node, not a valid tree
            visited[node] = True
            if leftChild[node] != -1:
                queue.append(leftChild[node])
            if rightChild[node] != -1:
                queue.append(rightChild[node])
                
        return sum(visited) == n  # If all nodes are visited, it's a valid tree
