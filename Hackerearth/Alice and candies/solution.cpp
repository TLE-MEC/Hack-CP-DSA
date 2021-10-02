#include <bits/stdc++.h>
using namespace std;

/*
Since all numbers are odd we assume the candies to be 2k+1,2k+3,etc. If n is odd then we will be needing odd number of candies (since sum of odd number of odd numbers is odd) and if n is even we will need even number of candies. We know that sum of 1+3+5+...+p is equal to k^2 (1+3+5=9) where k is the number of terms. So our first task is to find an upper bound for n such that it is less than the square of a given number. Now adding the consecutive candies we get a number of the form 2p+q^2 ((2k+1)+(2k+3)+(2k+5)=6k+9). Hence if this number equals n for some k belonging to Z(integer) then it will be one of our solution.
*/
int main()
{
    int n;
    cin >> n;
    long long pos;
    for (long long i = 1; ; i++)
    {
        if (i * i > n)
        {
            pos = i;
            break;
        }
    }
    int count = 0;
    for (long long i = 2-(n%2); i < pos; i += 2)
    {
            if ((n - i * i) % (2 * i) == 0)
                count++;
    }
    cout << count;
    //Time complexity : O(sqrt(n)) i.e Proportion to Root of N
}
