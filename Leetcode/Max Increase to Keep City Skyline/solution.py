# For grid[i][j], it can't be higher than the maximun of its row and column.
# So the maximum increasing height for a building at (i, j) is min(row[i], col[j]) - grid[i][j]

class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res += abs(grid[i][j] - min(max(grid[i]),
                           max([g[j] for g in grid])))
        return res
