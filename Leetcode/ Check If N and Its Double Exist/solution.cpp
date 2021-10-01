#include <iostream>
#include <vector>  
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr)  //Creating the function
    {
        for(int i=0;i<arr.size();i++) //Starting a loop of size equal to the size of array
        {
            for(int j=0;j<arr.size();j++) //Checking the corresponding elements and further.
            {
                if(i==j) //Checking if equal to continue
                {
                    continue;
                }
                if(2*arr[i]==arr[j]) //Checking for the existance of double
                {
                    return true; //Returning TRUE
                }
            }
        }
        return false; //Returning FALSE
    }
};
