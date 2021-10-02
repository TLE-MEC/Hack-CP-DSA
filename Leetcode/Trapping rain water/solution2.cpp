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
                maxL = max(maxL,height[lefti]);
                lefti--;
            }
             while(righti < height.size())
            {
                maxR = max(maxR,height[righti]);
                righti++;
            }
            int current = min(maxR,maxL) - height[i];
            if(current >= 0)
                total += current;
        }
        return total;
    }
};
