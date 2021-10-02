/*
time: O(n)
space: O(1)
just think about the mathematical induction
if we know all the string of len k, so the string of len k + 1 will be
1 add a before all string of len k
2 add e before the string of len k, which is starts with or after e
3 add i before the string of len k, which starts with or after i
4 add o before the string of len k, which starts with or after o
5 add u before the string of len k, which starts with or after u
*/

class Solution
{
public
    int countVowelStrings(int n)
    {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        while (n > 1)
        {
            // add new char before prev string
            a = (a + e + i + o + u); // a, e, i, o, u -> aa, ae, ai, ao, au
            e = (e + i + o + u);     // e, i, o, u -> ee, ei, eo, eu
            i = (i + o + u);         // i, o, u -> ii, io, iu
            o = (o + u);             // o, u -> oo, ou
            u = (u);
            ; // u -> uu
            n--;
        }

        return a + e + i + o + u;
    }
}