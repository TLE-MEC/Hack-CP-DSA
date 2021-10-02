class Solution
{
public:
    unordered_set<int> memo[32][32];
    void dfs(string &s, int st, int fin)
    {
        if (memo[st][fin].empty())
        {
            if (fin - st == 1)
                memo[st][fin].insert(s[st] - '0');
            for (int i = st + 1; i < fin; i += 2)
            {
                dfs(s, st, i);
                dfs(s, i + 1, fin);
                for (int n1 : memo[st][i])
                {
                    for (int n2 : memo[i + 1][fin])
                    {
                        int n = s[i] == '*' ? n1 * n2 : n1 + n2;
                        if (n <= 1000)
                            memo[st][fin].insert(n);
                    }
                }
            }
        }
    }
    int scoreOfStudents(string s, vector<int> &answers)
    {
        int correct = 0;
        for (int i = 1, j = 0; i <= s.size(); i += 2)
            if (i == s.size() || s[i] == '+')
            {
                int mul = 1;
                for (; j < i; j += 2)
                    mul *= s[j] - '0';
                correct += mul;
            }
        dfs(s, 0, s.size());
        return accumulate(begin(answers), end(answers), 0, [&](int sum, int ans)
                          { return sum + (ans == correct ? 5 : memo[0][s.size()].count(ans) ? 2
                                                                                            : 0); });
    }
};