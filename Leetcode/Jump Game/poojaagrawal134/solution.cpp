//jump game
//The idea is to use a variable maxrange which will tell you the maximum jump possible , and run a loop if i>maxrange then it will return 0 otherwise it will return 1 .

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n=nums.size();
       if(n==1) return  1;
       
       int maxrange = nums[0];
      for(int i=1;i<n;i++){
          if(maxrange>=n-1) return 1;
          if(maxrange>=i&&i!=0) maxrange = max(maxrange,i+nums[i]);
          else return 0;
      }
        return -1;    //we are never going to return this value
    }
};