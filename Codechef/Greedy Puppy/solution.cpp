/*
Greedy Puppy solution in c++
Author : Keshav Prajapati
*/

#include <iostream>
using namespace std;

int main()
{
    int t, n, k, cal;
    cin >> t;
    for (int i = 0; i < t; i++) //testCases
    {
        int coin = 0;
        cin >> n >> k; //n=no. of coins,k=no. of peoples
        for (int j = 1; j < k + 1; j++)
        {
            cal = n % j;//checking from 1 to k max no. of coins tuzik can get.
            if (cal > coin)
                coin = cal;//replacing prev. value if we get more coins.
        }
        cout << coin << endl;
    }
    return 0;
}