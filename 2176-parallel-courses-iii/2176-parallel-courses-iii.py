from collections import defaultdict
from functools import lru_cache
from typing import List

class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        G = defaultdict(list)
        for x, y in relations:
            G[y].append(x)

        @lru_cache(None)
        def dp(node):
            return time[node - 1] + max([dp(child) for child in G[node]] + [0])

        return max(dp(i) for i in range(1, n + 1))
