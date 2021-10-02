// In this,first we will find out subarrays with atleast k different integers,then to get subarrays with exactly k different integers we will
//use logic i.e. subarrays with atleast k different integers - subarrays with stleast k-1 different integers  

class Solution {
public:
  int atleast(vector<int>&nums , int k)
  {
    unordered_map<int,int>m; // map to store frequencies of diffent integers in a subarray
    int diff = 0; // count of different integers in currently processing subarray
    int total = 0;
    int l = 0; // left index
    int r = 0; // right index
    int n = nums.size();
    for(;r<n;r++)
      {
	if(m[nums[r]] == 0) // if a integer is not already present in map then increment value of diff.
	  {
	    diff++;
	  }
	m[nums[r]]++; // Storing frequency of integer 
	if(diff<=k) 
	  {
	    total+=(r-l+1); // r-l+1 => no. of all possible subarrays with right and left index
	  }
	else
	  {
	    while(l<=r && diff > k) // if no. of different  integers becomes greater than k , then i will simply move left towards right 
	      {
		m[nums[l]]--;  //Decrementing frequency of integer present at left index;
		if(m[nums[l]] == 0)diff--; // if decrementing makes frequency of that integer = 0 , then diff = diff -1 ; 
		l++;
	      }
	    total+=(r-l+1);
	  }
      }
    return total; //Returning Total number of subarrays having atleast k different integers.
  }
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atleast(nums,k) - atleast(nums,k-1);
        
  }
};

// Time Complexity = O(n);
// Spce Complexity = O(n): As , we are using the map
