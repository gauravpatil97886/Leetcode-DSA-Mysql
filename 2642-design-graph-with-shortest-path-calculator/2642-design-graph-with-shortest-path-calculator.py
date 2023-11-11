import heapq
from typing import List

class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.a = [[] for _ in range(n)]
        for e in edges:
            self.a[e[0]].append((e[1], e[2]))

    def addEdge(self, e: List[int]):
        self.a[e[0]].append((e[1], e[2]))

    def shortestPath(self, n1: int, n2: int) -> int:
        return self.dijkstra(n1, n2)

    def dijkstra(self, s: int, e: int) -> int:
        n = len(self.a)
        d = [float('inf')] * n
        d[s] = 0
        pq = [(0, s)]

        while pq:
            c, n = heapq.heappop(pq)
            if c > d[n]:
                continue
            if n == e:
                return c
            for ed in self.a[n]:
                nb, el = ed
                new_c = el + d[n]
                if d[nb] > new_c:
                    d[nb] = new_c
                    heapq.heappush(pq, (new_c, nb))

        return -1 if d[e] == float('inf') else d[e]
