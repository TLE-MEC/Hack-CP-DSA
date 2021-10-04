/*the idea is to use sliding window approach*/

#include<bits/stdc++.h>
using namespace std;


int calc(vector<int>&nums, int k){
    int i=0,j=0,count=0,sum=0;
    while(j<nums.size() && i<=j){
        sum+=nums[j];
        if(sum<=k){
            count+=j-i+1; // j-i+1 will give the count of subarrays ending with element at j and the sum of that subarray is atmost k
            j++;
        }
        else
        {
            while(sum>k && i<=j){
                sum-=nums[i];
                i++;
            }
            if(i<=j)
                count+=j-i+1;
            j++;
        }
    }

    return count;
}
    
int numSubarraysWithSum(vector<int>& nums, int goal) {
    
    //asked to calculate the subarrays whose sum is exactly goal
    // w.k.t exactly(k) = atmost(k)-atmost(k-1);
    // so find the subarrays whose sum is atmost 'goal' and 'goal-1'
    // then return their difference
    
    return calc(nums,goal) - calc(nums,goal-1);
}

int main()
{
    int n,goal;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	v.push_back(x);
	}
	cin>>goal;
    
    cout<<numSubarraysWithSum(v,goal)<<endl;

}