/** Approach: Intialize a map which stores sum of subarray of each wall as a key and calculate maximum frequency of the subarray of wall. 
Total wall size - maximum repeated sum of subarray is vertical line which is crossing minimum walls. **/


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_val = 0, pos;
        unordered_map<int,int>history;        // map 
        for(int i = 0; i < wall.size(); i++){
            pos = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                pos += wall[i][j];         // subarray sum calculation
                history[pos]++;
                max_val = max(max_val, history[pos]);
            }
        }
        return wall.size()-max_val;
    }
};