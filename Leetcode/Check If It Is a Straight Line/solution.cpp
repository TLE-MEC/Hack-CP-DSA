class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();                                       //Stores the size of the vector
        if (n == 1)
            return false;                                                 //False as a line requires at leat two points
        if (n == 2)
            return true;                                                  //Two points always lie in a stright line
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int dx = coordinates[1][0] - x0, dy = coordinates[1][1] - y0;         
        for (int i = 1; i < n; i++)                                       //Finding the slope between the first and the remaining points
        {
            int x = coordinates[i][0], y = coordinates[i][1];
            if (dx * (y - y0) != dy * (x - x0))                           //Testing whether general equation of a line is true
                return false;
        }
        return true;
    }
};
