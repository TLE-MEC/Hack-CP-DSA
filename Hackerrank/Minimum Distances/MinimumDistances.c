#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, t, s = 0, o = 0, e = 0;
    scanf("%d", &t);
    int a[t], b[t];
    for (i = 0; i < t; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < t; i++)
    {
        s = 0;
        o = 0;
        e = 0;
        for (j = i + 1; j < t; j++)
        {
            s++;
            if (a[i] == a[j])
            {
                e = 1;
                break;
            }
            else
            {
                o++;
            }
        }
        if (e == 1)
            b[i] = s;
        else
            b[i] = 0;
    }

    k = 10000;
    for (i = 0; i < t; i++)
    {
        if (b[i] < k && b[i] > 0)
        {
            k = b[i];
        }
    }
    if (k == 10000)
        printf("-1");
    else
        printf("%d", k);
    return 0;
}
