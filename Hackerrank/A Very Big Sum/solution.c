#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    // take n as input
    int n;
    scanf("%d", &n);
    // creating array of n elements
    long long int ar[n], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ar[i]);
        // adding each element to sum
        sum += ar[i];
    }
    printf("%lld", sum);
    return 0;
}
