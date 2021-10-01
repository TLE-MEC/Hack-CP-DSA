/* 
    Algorithm:-
        1) Keep two index, left = 0 and right = height.size() - 1 and a value max_area that stores the maximum area.
        2) Run a loop until left is less than the right.
        3) First calculate left height and right height.
        4) Then, calculate minimum height of left height and right height.
        5) Update the max_area with maximum of max_area and min_height multiply by (right - left).
        6) if the value at array[left] is greater the array[right] then update right as right – 1 else update left as left + 1
        7) Print the maximum area.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        // Initialize l = 0, r = height.size() - 1
        // and area = 0
        int l = 0;
        int r = height.size() - 1;
        int max_area = 0;
        
        // Run a loop until Left is less than the right.
        while(l < r)
        {
            int lh = height[l];
            int rh = height[r];
            int min_h = min(lh,rh);

            // Calculating the max area
            max_area = max(max_area, min_h * (r - l));
            
            if(lh < rh)
                l++;
            else
                r--;
        }

        // Return the max area
        return max_area;
    }
};
