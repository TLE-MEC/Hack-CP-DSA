#include <stdio.h>

// The function is declared with a void return type, so there is no value to return. Modify the values in memory so that  contains their sum and  contains their absoluted difference.


void update(int *a,int *b) {
    
    // a'= a + b 
    if (*a>*b){
        *b = *a - *b;
        *a = *a - *b + *a;
    }
    // b' = |a - b|
    else {
        *b = *b - *a;
        *a = *a + *b + *a;
    }
    
    // Complete this function    
}

int main() {
    // initalising intengers
    int a, b;
    int *pa = &a, *pb = &b;
    
    //printing the output
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
