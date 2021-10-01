class Solution {
    public int countNegatives(int[][] grid) {
        int n=grid.length, m=grid[0].length;
        int row=n-1, column=0;
        int count=0;
        while(row>=0 && column<m){
            if(grid[row][column] < 0){
                count++;
                count += (m-1) - column;
                row--;
            }
            else if(grid[row][column] >=0){
                column++;
            }
        }
        return count;
    }
}