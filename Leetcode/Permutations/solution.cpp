/** Approach: First make vector of bool and push a element into a vector, call for the other elements and undo it. Repeat the same process for all 
elements until the size of the vector is number of elements given.This will create all the permutations.**/


class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int>& nums, vector<bool>& B, vector<int>contri){
        // base condition
        if(nums.size() == contri.size())
            res.push_back(contri);
    
        //recursive step
        for(int i = 0; i < nums.size(); i++){
            if(B[i] == 0)
                continue;
            contri.push_back(nums[i]);
                B[i] = false;
            f(nums, B, contri);
            // undo
            contri.pop_back();
            B[i] = true;
        }
    
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> B(nums.size(), 1);
        f(nums, B, {});
        return res;
    }
};