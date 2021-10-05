#include <stdio.h>

int main() {
    // take n as input
    int n,temp;
    scanf("%d", &n);
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        // Scanning the element
        scanf("%d", &temp);
        // Adding each element to sum
        sum += temp;
    }
    printf("%lld", sum);
    return 0;
}
