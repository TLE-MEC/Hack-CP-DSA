//time complexity:O(n)
//space complexity:O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    //pair stack for storing tempratures and their index
    stack<pair<int, int>> Stack;
    vector<int> ans;
    //this loop is running to find next greater temprature to right of 
    //particular element.
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        //if stack is empty means there is no element greater than current element
        if (Stack.size() == 0)
        {
            ans.push_back(-1);
        }
        //if element at top is greater we just store its index in vector
        else if (Stack.top().first > temperatures[i])
        {
            ans.push_back(Stack.top().second);
        }
        //else we pop elements from stack until we get greater element
        //or stack becomes empty
        else
        {
            while (Stack.size() != 0 && Stack.top().first <= temperatures[i])
            {
                Stack.pop();
            }
            if (Stack.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(Stack.top().second);
            }
        }
        Stack.push({temperatures[i], i});
    }
    //ans has index of next greatest element to right in reverse
    //i.e NGR for last is stored at ans[0]
    //so we reverse it 
    reverse(ans.begin(), ans.end());
    vector<int> answer;
    //this loop will subtract index of NGR from index of element
    //which will give no. of days we have to wait to get a warmer day
    for (int i = 0; i < temperatures.size(); i++)
    {
        if (ans[i] == -1)
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(ans[i] - i );
        }
    }
    return answer;
}
int main()
{
    vector<int> temprature;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int temp;
        cin>>temp;
        temprature.push_back(temp);
    }
    vector<int> answer=dailyTemperatures(temprature);
    for(int i=0;i<size;i++)
    {
        cout<<answer[i]<<" ";
    }
}