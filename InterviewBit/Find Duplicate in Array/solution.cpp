/*

Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

Solution approach
Split the numbers from 1 to n in sqrt(n) ranges so that range i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).

Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.

At least one of the ranges will contain more than sqrt(n) elements.

Do another pass and process just those elements in the oversubscribed range.

Using a hash table to keep frequencies, you'll find a repeated element.

This is O(sqrt(n)) memory and 2 sequential passes through the stream.

*/

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