#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A)
{
   int slow = A[0];
   int fast = A[A[0]];
   while (slow != fast)
   {
      slow = A[slow];
      fast = A[A[fast]];
   }
   fast = 0;
   while (slow != fast)
   {
      slow = A[slow];
      fast = A[fast];
   }
   if (slow == 0)
      return -1;
   return slow;
}