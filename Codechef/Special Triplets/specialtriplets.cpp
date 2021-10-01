#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> n;
    int ans = 0;
    for (int j = 2; j <= n; j++)
    {
      int temp = sqrt(j);
      for (int k = 1; k <= temp; k++)
      {
        if (!(j % k))
        {
          ans++;
          ans += (n - k) / j;
          int t2 = j / k;
          if (t2 != k and t2 < j)
          {
            ans++;
            ans += (n - t2) / j;
          }
        }
      }
    }
    cout << ans << endl;
  }
}