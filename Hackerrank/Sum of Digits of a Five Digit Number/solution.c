#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	  //declaring variables
    int n,l,sum,i;
    //input n
    scanf("%d", &n);
    //for loop to calculate the sum of digits
    for(i=0;i<=5;i++)
    {
      l=n%10;
      sum=sum+l;
      n=n/10;
    }
    //output sum
    printf("%d",sum);
    return 0;
}
