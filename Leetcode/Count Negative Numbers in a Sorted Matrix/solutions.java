// Points to remember:-
// 1. Remeber that the array is sorted both row and column wise. Therefore if arr[x]  is -ve then it means that all no.s below and after arr[x] are also -ve.
// 2. There can be repeated values also therefore we can't say that if current element is 0 then all no. after and below that will be -ve as 0 can be repeated

class Solution {
    public int countNegatives(int[][] grid) {
        int n=grid.length, m=grid[0].length;     // n and m represent no. of rows and columns respectively
        int row=n-1, column=0;             // we will start our search from the element present at this index i.e last element in first row
        int count=0;         // to count the no. of -ve no.s
		
        while(row>=0 && column<m){       // loop will break if either row and column go out of bounds
            if(grid[row][column] < 0){     // this will execute if element at this index is -ve
                count++;            // bcz element itself is -ve therefore increment count
                count += (m-1) - column;      // bcz array is sortd therefore no.s after this index are also -ve no.s. Therefore, this formula will calculate the all -ve no.s excluding the element at current index bcz it has already been included in count++;
                row--;            // as the current element is -ve therefore all elements after that is also -ve and we already counted that, so now we will search for the same in the row above the current row
            }
            else if(grid[row][column] >=0){     // will execute if no. is +ve
                column++;      // we don't care about +ve no.s therefore simply increment our column
            }
        }
        return count;      // returning our final answer
    }
}
