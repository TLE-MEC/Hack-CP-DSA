/*
    The code is self explanatory
*/
class Solution
{
public:
    int removeElement(vector<int> &A, int B)
    {
        int cnt = 0;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] != B)
            {
                A[cnt] = A[j];
                cnt++;
            }
            else // we skip the element
                continue;
        }

        return cnt;
    }
};
