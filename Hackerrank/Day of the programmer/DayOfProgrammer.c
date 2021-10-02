//Solution by Akshat Pandey
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,leap=0; 
    scanf("%d",&year);
    if (year%4==0) 
          leap=1;
    if (year>1918){
    if (year % 100==0) 
          leap=0;
    if (year % 400==0) 
          leap=1;
    }
    if (year!=1918){
        if(leap==0)
               printf("13.09.%d\n",year);
        else 
               printf("12.09.%d\n",year);
    }
    else 
          printf("26.09.%d\n",year);
    return 0;
}