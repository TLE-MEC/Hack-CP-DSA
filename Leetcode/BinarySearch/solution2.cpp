class Solution
{
public:
    int search(vector<int> &a, int target)
    {
        int e = a.size() - 1;
        int s = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            // If the element is present at the middle itself

            if (a[mid] == target)
            {
                return mid;
            }
            // If element is greater than mid, then it can only be present
            // in right subarray
            if (a[mid] < target)
            {
                s = mid + 1;
            }

            // If element is smaller than mid, then
            // it can only be present in left subarray
            else if (a[mid] > target)
            {
                e = mid - 1;
            }
        }
        return -1; // We reach here when element is not
        // present in array
    }
};