//In this probelem, we are given Given an array arr of positive integers and the array queries 
//where queries[i] = [Li, Ri], for each query i, we have to compute the XOR of elements from Li to Ri 
//(that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
// Finally, Return an array containing the result for the given queries.

// Solution-
// The logic is using the property of xor according to which, a^a=0 and 0^a=0 => a^b^a=b
// 1. Calculate a prefix xor, at its ith position, it holds the xor for all the elements of the array from 0 to i
// 2. while iterating through the queries array, calculate the xor of the numbers at (li-1)th position
// and (ri)th position of the pre_xor array
// 3. This will give the ans of the xor of elements between li and ri since the repeated elements will yield 0 upon xor
// Time Complexity - O(n) in worst case 

#include<bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> pre_xor;
        
        pre_xor.push_back(arr[0]);
        
        for(int i=1;i<arr.size();i++){
            pre_xor.push_back(arr[i]^pre_xor[i-1]);
        }
        
        vector<int> ans;
        
        int val;
        
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0)
                val = (0^pre_xor[queries[i][1]]);
            else {
                val = (pre_xor[queries[i][0]-1]^pre_xor[queries[i][1]]);
            }
            
            ans.push_back(val);
        }
        
        return ans;
    }

int main(){
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};

    vector<int> ans = xorQueries(arr,queries);
    for(auto i:ans){
        cout<<i<<" ";
    }
}