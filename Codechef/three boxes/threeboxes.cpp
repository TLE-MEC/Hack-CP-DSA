//logic:keep adding blocks to bag (starting from first)
//until sum of block sizes exceeds or equals bag size,
//when it equals bag size increment no. of bags needed
#include <iostream>
using namespace std;
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int A[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> A[i];
        }
        int i = 1;
        int sum = A[0];
        int count = 0;
        while (i < 3)
        {
            sum += A[i];
            //if sum exceeds bag size increment count and make sum equal to added bag
            if (sum > A[3])
            {
                count++;
                sum = A[i];
            }
            //if sum equals bag size increment count and make sum 0
            else if (sum == A[3])
            {
                count++;
                sum = 0;
            }
            i++;
        }
        //if there is some bag left we just increment no. of bags
        if (sum != 0)
        {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
