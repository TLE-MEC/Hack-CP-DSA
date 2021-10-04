// Regular Expression Matching
/*
    i -> length of string left to check
    j -> length of pattern left to check
    dp[i][j] will store if string from 0 to i-1 index and pattern from 0 to j-1 index matches or not
    dp[i][j] = {
                case1: i == 0 && j == 0    both string and pattern are completely equal
                     = true
                
                case2: j == 0  pattern completely traversed but string left
                    = false
                
                case3: i == 0  string completely traversed
                    if p[j-1] == '*' && j%2 == 0
                         = dp[i][j-2]
                    else
                        = false
                
                case4: if s[i-1] == p[j-1] || p[j-1] == '.'
                    = dp[i-1][j-1]
                
                case5: if p[j-1] == '*'
                    case a : 0 occurrence of previous character of *
                        dp[i][j-2]
                    case b : occurrence of previous character of *
                        dp[i-1][j]
                     = dp[i][j-2] || (dp[i-1][j] if s[i-1] == p[j-2] || p[j-2] == '.')              
                else
                    = false            
    }
*/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // case1
        dp[0][0] = true;
        // case2 already filled as default value of all cells is false

        // case3
        for (int j = 1; j <= n; j++)
        {
            if (j % 2 == 0 && p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // case4
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (j > 1 && p[j - 1] == '*')
                {                            // case5
                    dp[i][j] = dp[i][j - 2]; // case 5a
                    if (p[j - 2] == '.' || s[i - 1] == p[j - 2])
                    { // case 5b
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        // Final answer
        return dp[m][n];
    }
};