class Solution {
    fun minPathSum(grid: Array<IntArray>): Int {
        for (i in 1..grid[0].size-1){
            grid[0][i] += grid[0][i-1]
        }

        for (i in 1..grid.size-1){
            grid[i][0] += grid[i-1][0]
        }

        for (i in 1..grid.size-1) {
            for (j in 1..grid[i].size-1) {
                val a = grid[i][j]+grid[i][j-1]
                val b = grid[i][j]+grid[i-1][j]

                grid[i][j] = minOf(a, b)
            }
        }

        return grid[grid.size-1][grid[0].size-1]
    }
}