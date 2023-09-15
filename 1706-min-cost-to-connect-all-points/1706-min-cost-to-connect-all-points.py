class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def calculate_manhattan_distance(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

        def find(parents, node):
            if parents[node] == node:
                return node
            parents[node] = find(parents, parents[node])
            return parents[node]

        def union(parents, node1, node2):
            root1 = find(parents, node1)
            root2 = find(parents, node2)
            if root1 != root2:
                parents[root1] = root2

        n = len(points)
        edges = []

        for i in range(n):
            for j in range(i + 1, n):
                dist = calculate_manhattan_distance(points[i], points[j])
                edges.append((dist, i, j))
        edges.sort()

        parents = list(range(n))
        min_cost = 0
        num_edges = 0

        for edge in edges:
            dist, u, v = edge
            if find(parents, u) != find(parents, v):
                union(parents, u, v)
                min_cost += dist
                num_edges += 1
                if num_edges == n - 1:
                    break

        return min_cost
