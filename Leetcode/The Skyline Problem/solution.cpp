/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in 
that city when viewed from a distance. Given the locations and heights of all the buildings, 
return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where 
buildings[i] = [lefti, righti, heighti]:
    lefti is the x coordinate of the left edge of the ith building.
    righti is the x coordinate of the right edge of the ith building.
    heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate 
in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal 
segment in the skyline except the last point in the list, which always has a y-coordinate 0 
and is used to mark the skyline's termination where the rightmost building ends. 
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        // first: x, second: height
        vector<pair<int, int>> walls;
        vector<vector<int>> ans;

        for (auto b : buildings)
        {
            // let left wall has negative height to ensure left wall goes to
            // multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());

        multiset<int> leftWallHeights = {0};
        int maxHeight = 0;
        for (auto w : walls)
        {
            if (w.second < 0) // Left
                leftWallHeights.insert(-w.second);
            else // Right
                leftWallHeights.erase(leftWallHeights.find(w.second));

            if (*leftWallHeights.rbegin() != maxHeight) // If Max height changes
            {
                maxHeight = *leftWallHeights.rbegin();
                ans.push_back({w.first, maxHeight});
            }
        }

        return ans;
    }
};
