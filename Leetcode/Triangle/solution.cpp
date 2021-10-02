/*
Dynamic programming can be performed on an array of the same size.
It can be performed top-down or bottom-up:
1) In top-down, we have to compare all the bottom elements to find the minimum one.
2) In bottom-up, the topmost point of the triangle automatically holds the answer. THIS IS PREFERRED
As the sum upto a point includes the value at that point, we can reuse the same array instead of creating a new one.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        //bottom-up: topmost point will hold answer
        for( int i=triangle.size()-2 ; i>=0 ; i-- ) //starting from last but one row
        {
            for( int j=0 ; j<=i ; j++ ) //for all elements in the row
                triangle[i][j] += min( triangle[i+1][j] , triangle[i+1][j+1] ); //add the smaller of the two possible elements to the current value
        }
        
        return triangle[0][0]; //returning minimum path sum
    }
};