// 1. If all the piranhas have the same size then the answer is -1.
// Otherwise, there are at least two different sizes of piranhas and the answer always exists.
// 2. the answer is such a piranha with the maximum size that one of the adjacent piranhas has the size less than a maximum.

#include <bits/stdc++.h>
using namespace std;
// solver function is called for each test case
int solver()
{
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  // Max is the largest value in the array i.e., piranha of largest size
  long long Max = *max_element(a, a + n);
  // If all piranha's are of same size then answer does not exist
  if (count(a, a + n, Max) == n)
    cout << -1 << endl;
  else
  {
    for (int i = 0; i < n; ++i)
    {
      // In all other cases, we will find that piranha that has largest size as well as
      // has a adjacent piranha whose size is less than it
      if (a[i] == Max && ((i > 0 && a[i - 1] < Max) || (i < n - 1 && a[i + 1] < Max)))
      {
        // On finding the required piranha, we print the index of the same
        cout << i + 1 << endl;
        break;
      }
    }
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solver();
  return 0;
}
