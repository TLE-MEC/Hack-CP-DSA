/*
The simplest way to perform this operation is to -
1) Take transpose of matrix.
2) Take mirror image of matrix.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        
        //Transpose
        for( int i=0 ; i<n ; i++ )
            for( int j=i+1 ; j<n ; j++ )
            {
                swap( matrix[i][j], matrix[j][i] );
            }
        
        //Mirror image
        for( int i=0 ; i<n ; i++ )
            for( int j=0 ; j<n/2 ; j++ )
            {
                swap( matrix[i][j], matrix[i][n-1-j] );
            }
    }
};