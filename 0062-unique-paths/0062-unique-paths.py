class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        ans = 1
        j = 1
        for i in range(m, m+n-2 + 1):
            ans *= i
            ans //= j
            j += 1
            
        return ans