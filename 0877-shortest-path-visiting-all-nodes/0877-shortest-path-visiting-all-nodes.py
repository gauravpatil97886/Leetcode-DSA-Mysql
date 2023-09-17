from collections import deque

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        target_mask = (1 << n) - 1  # A bitmask with all nodes visited
        
        visited = set()
        
        queue = deque((i, 1 << i, 0) for i in range(n))
        
        while queue:
            node, state, cost = queue.popleft()
            
            if state == target_mask:
                return cost
            
            if (node, state) in visited:
                continue
                
            visited.add((node, state))
            
            for neighbor in graph[node]:
                new_state = state | (1 << neighbor)
                queue.append((neighbor, new_state, cost + 1))
        
        return -1  # If no valid path is found, return -1
