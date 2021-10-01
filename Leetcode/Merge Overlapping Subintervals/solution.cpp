// In this problem, we have are given an array of intervals where intervals[i] = [starti, endi], 
// and we have to merge all overlapping intervals, and return an array of the non-overlapping intervals 
// that cover all the intervals in the input. 

//Solution Logic:
//The approach to solve the problem is a greedy algorithm
// 1. Sort the intervals w.r.t their starting time
// 2. Take a temp variable initially equal to the first interval (This will store the final merged intervals)
// 3. By iterating through the intervals, check if the ending time of temp > starting time of the current interval
// 4. If yes, it means the interval can be merged with temp - so update the ending time of temp with maximum of their ending times
// 5. If no, push temp to the output and update it - set temp equal to the curr interval 
// 6. Repeat it until the end
// 7. Finally return the output


#include<bits/stdc++.h>
using namespace std;

// Utility function
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){return intervals;}
        sort(intervals.begin(),intervals.end());
        
        vector<int> temp = intervals[0];
        vector<vector<int>> output;
        
        for(auto it:intervals){
            if(temp[1]>=it[0]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                output.push_back(temp);
                temp=it;
            }
        }
        
        output.push_back(temp);
        
        return output;
    }

// Driver Code
int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(v);

    for(auto i:ans){
        cout<<i[0]<<","<<i[1]<<"\n";
    }
}