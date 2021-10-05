proble statemnt
https://leetcode.com/problems/longest-palindromic-subsequence/

Video link
https://www.youtube.com/watch?v=YHSjvswCXC8

class Solution {
public:

int lps(string str){
    int n = str.size();
    int dp[n][n]; // Create a table to store results of subproblems

    // Strings of length 1 are palindrome of length 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Build the table. Note that the lower diagonal values of table are
// useless and not filled in the process.
    for (int cl = 2; cl <= n; cl++){
        for (int i = 0; i < n - cl + 1; i++){
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[0][n - 1];
}

int longestPalindromeSubseq(string s) {
    return lps(s);
}
};