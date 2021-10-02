/*
Last Stone Weight solution in C++
Author: Shourya Gupta
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while(stones.size()!=1){//run the loop until only one element remains
            int rem=0;
            sort(stones.begin(), stones.end()); //Sorting the stones array
            rem=stones[stones.size()-1]-stones[stones.size()-2];//After smashing the new weight obtained
            stones.pop_back();//removed the heaviest weight
            stones.pop_back();//removed the 2nd largest weight
            stones.push_back(rem);//input the new remaining weight
        }
        return stones[0];
    }
};
