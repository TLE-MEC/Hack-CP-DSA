// This program can be self understandable

#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    while (1)
    {
        float d1, v1, d2, v2, p;
        cin >> d1 >> v1 >> d2 >> v2 >> p;
        if (d1 == 1 && d2 == 1)
        {
            float x = v1 + v2;
            float res = p / x;
            cout << ceil(res);
            break;
        }
        if (d2 < d1)
        {
            float s;
            s = v1 + v2;
            int t = 0, i = 1;
            while (i)
            {
                if (t >= p)
                {
                    cout << i - 1;
                    break;
                }
                if (i >= d2)
                {
                    t += v2;
                    if (i >= d1)
                    {
                        t += v1;
                    }
                }
                i += 1;
            }
            break;
        }
        if (d1 < d2)
        {
            float s;
            s = v1 + v2;
            int t = 0, i = 1;
            while (i)
            {
                if (t >= p)
                {
                    cout << i - 1;
                    break;
                }
                if (i >= d1)
                {
                    t += v1;
                    if (i >= d2)
                    {
                        t += v2;
                    }
                }
                i += 1;
            }
            break;
        }
        if (d1 == d2)
        {
            float s = 0, t;
            s = v1 + v2;
            t = p / s;
            if (d1 > 1)
                s = (d1 - 1);
            cout << ceil(t) + s;
            break;
        }
    }
    return 0;
}
