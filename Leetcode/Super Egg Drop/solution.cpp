Proble link 
https://leetcode.com/problems/super-egg-drop/

class Solution {
public:
  
  int dp[101][10001];
int solve(int e, int f)
{
	if (f == 0 || f == 1 || e == 1)
		return f;
	if (dp[e][f] != -1)
		return dp[e][f];

	int ans = INT_MAX, temp, l = 1, h = f;
	while (l <= h)
	{
		int mid = (l + h) / 2;
		int left = solve(e - 1, mid - 1);
		int right = solve(e, f - mid) ;
		temp = 1 + max(left, right);
		if (left < right) {

			l = mid + 1;
		}
		else
		{
			h = mid - 1;
		}
		ans = min(ans, temp);
	}
	return dp[e][f] = ans;
}
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof dp);
	    return solve(k, n);
        
    }
    
};