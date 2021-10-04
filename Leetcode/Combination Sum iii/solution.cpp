/** Approach: Two Subsets one include an element and other exclude the element and repeat the same process for 1 to 9 numbers.**/


class Solution {
public:
    vector<vector<int>> res;
    void f(int k, int n, vector<int>& arr,int start, int end, vector<int> contribution){
       
        // base condition
        if (start > end){
            if (n == 0 && k == 0) {
                res.push_back(contribution);
                return;
            }
            else{
                return;
            }
        }
        else if(n == 0 && k == 0){
           res.push_back(contribution);
           return;
       }
       else if(n == 0 || k == 0 || n < 0){
           return;
       }
        
        // recursive step
        // c2 not included start
        f(k, n, arr, start+1, end, contribution);
            
        // c1 can be calculated
         contribution.push_back(arr[start]);
         f(k-1, n-arr[start], arr, start+1, end, contribution);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        arr = {1,2,3,4,5,6,7,8,9};
        f(k, n, arr, 0, 8, {});
        return res;
    }
};