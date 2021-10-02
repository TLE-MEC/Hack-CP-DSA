//DayOfProgrammer Solution by Akshat Pandey
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,leap=0;               //initializing year and leap variable
    scanf("%d",&year);
    if (year%4==0)                 //checking if year is leap or not
          leap=1;
    if (year>1918){                
    if (year % 100==0)             //an year divided by 100 is not leap year
          leap=0;
    if (year % 400==0)             //an year divided by 400 is leap year
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