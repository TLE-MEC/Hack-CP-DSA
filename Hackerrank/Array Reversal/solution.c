#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaring variables
    int num, *arr, i;
    //input num
    scanf("%d", &num);
    //dynamic allocation of arr
    arr = (int*) malloc(num * sizeof(int));
    //for loop to scan the array
    for(i = 0; i < num; i++) 
    {
        scanf("%d", &arr[i]);
    }
    // logic to reverse the array
    for(i = num-1; i >=0; i--)
        printf("%d ", arr[i]);
    return 0;
}