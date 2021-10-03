/*Solution for Dungeon Game: 
this problem is similar to Minimum cost path probelm. We can not use Greedy approach to solve it. We can solve it either by recursion, Binary search or by dynamic programming approach.
let us go with the DP approach because it is optimal and through this problem, if you have any doubts about a DP Solution in general, it will be cleared.*/

// We will make a DP table and will start filling it from the bottom (Bottom up approach). In each cell of the DP table we will fill the minimum cost required to save the princess.

/*Creating the DP table : 
NOTE : The main trick of the solution is filling the cells which come out to be positive in the DP table with 0. We are replacing positive values with zero because we are actually filling the "Energy spent", so if we will mention a postive value as it is, our solution will not work because if the value is positive , then NO enery is spent or No minimum enery is required to come to that cell.
For example, if we have to choose between -5 and 20, -5 means that 5 energies will be spent to reach on that cell, where as 20 means that no energy will be spent ,instead, it will give us more 20 units of energy. Hence replacing any positive cumulative value with 0 will make our algirthm coose correct path.
Let us denote the given table values as health at given matrix. Now the table can be filled as follows:
1. We will start from the bottom right corner and fill the value of the given matrix at that cell itself. (since it is the destination)
2. For the cells in bottom row, we can only move to the right cell, so we will fill the cell with "health of current cell in given matrix + value in the right cell of DP table". If the value comes out to be positive , we will replace it with zero as mentioned in the note above
3. For the cells in rightmost column , we can only move to the bottom cell, so we will fill the cell with "health of current cell in given matrix + value in the cell below it in DP table" If the value comes out to be positive , we will replace it with zero as mentioned in the note above
4. For other cells , we have an option to choose between going to Right or Down. So we will choose the maximum value from the right and bottom cell in DP table and then will add the value in current cell. (We will choose max because it is a more negative value will cost us more energy  )
5. Finally when we will fill the top left (initial) cell, we will add 1 to it because the knight can not start with value 0. So the ans becoms DP[0][0]+1 */

// Time complexity : O(MN) i.e. the given matrix's dimensions.

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int r = dungeon.size();                    // row size
        int c = dungeon[0].size();                 // column size
        vector<vector<int>> dp(r, vector<int>(c)); // initializing the DP table with same size as given matrix
        // looping for filling the DP array starting from bottom right cell. the pattern is right to left ,then down to top
        for (int i = r - 1; i >= 0; --i)
        {
            for (int j = c - 1; j >= 0; --j)
            {
                if (i == r - 1 && j == c - 1)                                           //Bottom-Right cell (Princess Cell) (point 1.)
                    dp[i][j] = min(0, dungeon[i][j]);                                   // taking min so as to replace the positive value with 0
                else if (i == r - 1)                                                    //last row, (point 2)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j + 1]);                    // taking min so as to replace the positive value with 0
                else if (j == c - 1)                                                    //last col, point (3)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i + 1][j]);                    // taking min so as to replace the positive value with 0
                else                                                                    // any other cell (point 4)
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j + 1], dp[i + 1][j])); // taking min so as to replace the positive value with 0
            }
        }
        return abs(dp[0][0]) + 1; // Adding one because the knight can not start with value 0 as mentioned in point 5
    }
};