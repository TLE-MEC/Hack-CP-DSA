class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res += abs(grid[i][j] - min(max(grid[i]),
                           max([g[j] for g in grid])))
        return res
