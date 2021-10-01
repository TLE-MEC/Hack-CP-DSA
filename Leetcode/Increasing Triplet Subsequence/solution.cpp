class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // O(n) time and O(1) space
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);   
        cout.tie(NULL);
        
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int &i : nums){
            if (i < min1) 
                min1 = i;
            else if (i > min1 && i < min2) 
                min2 = i;
            else if (i > min2) 
                return true;
        }
        return false;
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