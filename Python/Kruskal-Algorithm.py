class DisjointSet:
    def __init__(self, vertices):
        self.parent = {v: v for v in vertices}
        self.rank = {v: 0 for v in vertices}

    def find(self, vertex):
        if self.parent[vertex] != vertex:
            self.parent[vertex] = self.find(self.parent[vertex])
        return self.parent[vertex]

    def union(self, vertex1, vertex2):
        root1 = self.find(vertex1)
        root2 = self.find(vertex2)

        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

def kruskal(graph):
    mst = []
    ds = DisjointSet(graph['vertices'])
    edges = sorted(graph['edges'], key=lambda x: x[2])

    for edge in edges:
        u, v, weight = edge
        if ds.find(u) != ds.find(v):
            mst.append(edge)
            ds.union(u, v)

    return mst

graph = {
    'vertices': ['A', 'B', 'C', 'D', 'E'],
    'edges': [
        ('A', 'B', 1), ('A', 'C', 3),
        ('B', 'C', 2), ('B', 'D', 4),
        ('C', 'D', 5), ('C', 'E', 6),
        ('D', 'E', 7)
    ]
}

print(kruskal(graph))
