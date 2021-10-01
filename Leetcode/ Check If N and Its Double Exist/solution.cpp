#include <iostream>
#include <vector>  
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(2*arr[i]==arr[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
