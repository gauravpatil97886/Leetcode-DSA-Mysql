from collections import deque
from typing import List
import numpy as np

class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        graph = [[] for _ in range(n)]
        inDegree = [0] * n
        q = deque()
        dist = np.array(time)

        for r in relations:
            u = r[0] - 1
            v = r[1] - 1
            graph[u].append(v)
            inDegree[v] += 1

        for i in range(n):
            if inDegree[i] == 0:
                q.append(i)

        while q:
            u = q.popleft()
            for v in graph[u]:
                dist[v] = max(dist[v], dist[u] + time[v])
                inDegree[v] -= 1
                if inDegree[v] == 0:
                    q.append(v)

        return max(dist)
