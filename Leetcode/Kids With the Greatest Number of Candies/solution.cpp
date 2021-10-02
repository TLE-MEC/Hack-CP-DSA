class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // find the maximum number of candy the kid has
        int max = *max_element(candies.begin(),candies.end());
        vector<bool> arr;
        for (int i=0;i<candies.size();i++){
            // if the ith kid has lesser candies than the kid the with the max candy then push false
            if(candies[i]+extraCandies<max){
                arr.push_back(false);
            }
            // else push true
            else{
                arr.push_back(true);
            }
        }
        return arr;
    }
};