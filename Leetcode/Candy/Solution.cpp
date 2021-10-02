#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        //left[i] denotes how many elements are continuously increasing till ith element from left side
        int left[ratings.size()];
        int counter = 1;
        left[0] = 1;
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] - ratings[i - 1] > 0)
                counter++;
            else
                counter = 1;
            left[i] = counter;
        }
        counter = 1;
        int answer = 0;
        //It is like left[i] but on the opposite side. Basically, it denotes how many elements are continuously increasing till ith element
        //from right side
        //Since, we have to give atleast 1 candy, we should make max(continuously increasing from left side, continously increasing from right side)
        //So, that none receive less than one candy
        for (int i = ratings.size() - 1; i >= 0; i--)
        {
            if (i + 1 < ratings.size() and ratings[i] - ratings[i + 1] > 0)
                counter++;
            else
                counter = 1;
            answer += max(left[i], counter);
        }
        return answer;
    }
};

int main()
{
    Solution s1;
    vector<int> ratings = {1, 2, 2};
    cout << s1.candy(ratings);
    return 0;
}