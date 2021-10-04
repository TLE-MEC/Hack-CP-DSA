/** Approach: Our Solution set can viewed as including start and not including start and working on both cases for all the elements so that we will return for the target sum **/


class Solution {
public:
    vector<vector<int>> f(vector<int>& candidates, int start, int end, int target){
        //base cases
        if(start > end){
            if(target == 0)
                return {{}};
            else
                return {};
        }
        if(target == 0)
            return {{}};
        if(target < 0)
            return {};
        
        // calculating c2
       vector<vector<int>> c2 = f(candidates, start+1, end, target);
        
        // calculating c1
        vector<vector<int>> temp = f(candidates, start, end, target-candidates[start]);
        vector<vector<int>> c1;
        for(int i = 0; i < temp.size(); i++){
            temp[i].push_back(candidates[start]);
            c1.push_back(temp[i]);
        }
        
        // calculating s
        vector<vector<int>> s = c1;
        for(int i = 0; i < c2.size(); i++){
            s.push_back(c2[i]);
        }
        return s;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        ans = f(candidates, 0, n-1, target);
        return ans;
    }
};