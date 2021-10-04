class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),sum=0;            // variables n (assigned size of the vector mat) and sum
        for (int i=0;i<n;i++){
           sum += mat[i][i] + mat[i][n-i-1];
            }
        if(n%2!=0){                       //if n is odd 
                sum -= mat[(n-1)/2][(n-1)/2];
        }
        return sum;                       // returning sum
    }
};
