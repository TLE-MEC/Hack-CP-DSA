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
    // max to count maximum number of candles
    int max;
    // n is to count number of no. of candles
    int count = 0,n;
    scanf("%d",&n);
    // array is used to stores height of each candle
    int ar[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    max=ar[0];
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > max)
            {
                // find candle with maximum height
                max = ar[i];
            }
    }
    for (int i = 0; i < n; i++)
        if (ar[i] == max)
        // count how many candles have maximum height
        count++;
    printf("%d",count);
    return 0;
}

