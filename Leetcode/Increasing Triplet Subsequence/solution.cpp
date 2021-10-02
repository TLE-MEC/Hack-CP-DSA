class Solution {
public:
    //Sample input nums = [1,2,3,4,5]
    bool increasingTriplet(vector<int>& nums) {
        // O(n) time and O(1) space
        
        // The below 3 lines are just used for to make the code faster
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);   
        cout.tie(NULL);
        
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int &i : nums){
            if (i < min1) 
                min1 = i;
            // check if nums[i]<min1, if yes then update min1 to nums[i]
            // 1 < INT_MAX, set min1 = 1
            
            else if (i > min1 && i < min2) 
                min2 = i;
            // check if nums[i]>min1 and nums[i]<min2, if yes then update min2 to nums[i]
            // as 2 > 1 and 2 < INT_MAX, set min2 = 2 
            
            else if (i > min2) 
                return true;
            // as 3 > 2 now we fulfill the condition of increasing triplet subsequence and return true
        }
        return false;
        // otherwise return false
    }
};

//GIVEN
// i < j < k and nums[i] < nums[j] < nums[k]

        //BRUTE FORCE
        //for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i] < nums[j] and nums[j] < nums[k])
        //                 flag = true;
        //         }
        //     }
        // }
