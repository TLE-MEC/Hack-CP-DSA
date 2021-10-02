/*
Since the 2d array is sorted row wise and column wise, the element at [0,0] is the smallest number and element at [m-1,n-1] is the largest, where m = number of rows, n = number of columns.
This problem can be viewed similar to binary search in a 1D array.
Starting from the index [0,n-1](last element of 1st row), we have to choices:
    - if the element at position[i,j] is equal to target, the element is found
    - if the element at position[i,j] is greater than target, we need to go left.
    - if the element at position[i,j] is less than target, we need to go down.

For example:
matrix:
1 3 5 7
10 11 16 20
23 30 34 60

target: 30

path followed: 7->20->60->34->30(found)

If the path reaches outside the boundary of the matrix, return false.

Time complexity:
    - Since the problem is similar to binary search, time complexity is O(log(k)), where k = m*n.

Space Complexity:
    - Since there is no extra space used, spacce complexity is O(1).


*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        int j = cols-1;
        while(i<rows && j>=0) // boundary condition
        {
            if(matrix[i][j]  == target) // element found
                return true;
            else if(matrix[i][j] > target)// go left as the current element is greater
                j--;
            else // go down as the current element is smaller
                i++;
            
        }
        return false; // element not found
        
    }
};