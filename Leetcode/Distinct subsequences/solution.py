class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        N, M = len(t), len(s)
        dp = [[0] * (M + 1) for _ in range(N + 1)]

        for i in range(N + 1):
            dp[i][
                0] = 0  # Number of subsequences of zero length S can be formed which equal t[0:i]
        for j in range(M + 1):
            dp[0][
                j] = 1  # Number of subsequences of S[0:j] can be formed which equal t[0:1]

        for i in range(1, N + 1):
            for j in range(1, M + 1):
                # if char matches then we want the count of 2 positions behind in the string
                if t[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]

        return dp[-1][
            -1]  # [-1][-1] indicates bottom right position in Dp matrix
