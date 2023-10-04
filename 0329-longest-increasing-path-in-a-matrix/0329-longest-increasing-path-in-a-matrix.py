class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        
        def dfs(x, y):
            if memo[x][y] != -1:
                return memo[x][y]
            
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            max_path = 1
            
            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                
                if 0 <= new_x < m and 0 <= new_y < n and matrix[new_x][new_y] > matrix[x][y]:
                    max_path = max(max_path, 1 + dfs(new_x, new_y))
            
            memo[x][y] = max_path
            return max_path
        
        m, n = len(matrix), len(matrix[0])
        memo = [[-1] * n for _ in range(m)]
        max_len = 0
        
        for i in range(m):
            for j in range(n):
                max_len = max(max_len, dfs(i, j))
        
        return max_len
