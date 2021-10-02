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