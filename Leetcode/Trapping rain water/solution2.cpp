class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        for(int i=0;i<height.size();i++)
        {
            int maxL = 0;
            int maxR = 0;
            int lefti = i;
            int righti = i;
            while(lefti >= 0)
            {
                maxL = max(maxL,height[lefti]);  //to find the maximum height from left side
                lefti--;
            }
             while(righti < height.size())
            {
                maxR = max(maxR,height[righti]); //to find the maximum height from left side
                righti++;
            }
            int current = min(maxR,maxL) - height[i];  //finding the amount of water it can store currently
            if(current >= 0)
                total += current; //adding to total to get final result
        }
        return total;
    }
};
