//This solution uses trial and error to find the square root of a number.
//It basically multiplies each number in the number system( except negatives)
//with themselves until the required square is obtained.


class Solution
{
public:
    int mySqrt(int x)
    {
        long r = 1;
        while (r * r <= x)
            r++;
        return r - 1;
    }
};