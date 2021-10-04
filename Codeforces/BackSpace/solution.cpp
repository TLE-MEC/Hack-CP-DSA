// Solution Approach:
/*
The main idea of solution is,
When we select a backspace for input at that time, we lose 
two characters: one that was previously input and the character 
that the backspace removes (last char before it (if string is empty 
then no char. will remove))

So, starting with the last (right to left) char. of s and t, 
we point two pointers to the last char and compare S(i1) and T(j-1) 
in the following step if they match, else we compare S(i-2) with T(j) 
and process it until either PS >=0 OR PT >= 0 (PS and PT are pointers (index)).

If the length of the match characters equals the length of T, the answer is "YES".

Please see the code below for a better understanding.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    string s, t;
    cin >> s >> t;

    int len_s = s.length(), len_t = t.length();
    int pt = len_t - 1, ps = len_s - 1;
    int match_char = 0;

    if (len_s < len_t)
    {
        cout << "NO\n";
        return;
    }

    for (; (ps >= 0) && (pt >= 0);)
    {
        if (s[ps] == t[pt])
        {
            ps--, pt--;
            match_char++;
        }
        else
            ps -= 2;
    }

    if ((match_char == len_t) && match_char != 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}