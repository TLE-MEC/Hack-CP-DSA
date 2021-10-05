// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Solution Logic
// Apply binary search by considering the 2d matrix as a single 1d array
// 1. set l=0 and h = total no. of elements
// 2. Now using the row major implementation, index = (columns*i)+j, where i -> row number and j -> column number
// 3. => i=index/columns and j=index%columns
// 4. Rest is simple binary search in the array


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int l=0,h=(m*n)-1;
        int mid = (h+l)/2;
        
        while(l<=h){
            mid = (h+l)/2;
            if(target<matrix[mid/n][mid%n]){
                h=mid-1;
            }
            else if(target>matrix[mid/n][mid%n]){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        
        return false;
    }