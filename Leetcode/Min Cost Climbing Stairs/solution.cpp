class Solution {
public:
    vector<int> lookup;
    int sum(vector<int>& cost, int i, int n){
        
        if(i>=n) return 0; //reaches top
        if(lookup[i] != -1) return lookup[i];
           
        int optionA = cost[i] + sum(cost,i+1,n); //if going one step
        int optionB = cost[i] + sum(cost,i+2,n); //if going two steps
        return lookup[i] = min(optionA, optionB);
        
        //RECURSIVE SOLUTION PART
        // int optionA = cost[i] + sum(cost,i+1,n);
        // int optionB = cost[i] + sum(cost,i+2,n);
        // return min(optionA, optionB); // calculating the smallest part through each subtree and comparing it above, till it reaches top
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        lookup = vector<int>(n,-1);
        return min(sum(cost,0,n), sum(cost,1,n)); //start from step 0 or step 1
    }
};