class Solution:
    memo = {}
    MOD = 10**9 + 7
    
    def countOrders(self, n: int) -> int:
        if n == 1:
            return 1
        if n in self.memo:
            return self.memo[n]
        
        count = (self.countOrders(n - 1) * (2 * n - 1) * n) % self.MOD
        self.memo[n] = count
        return count
