//https://www.hackerrank.com/challenges/frequency-of-digits-1/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 1000

int main() 
{
    char str[1000]; //array to store input
    int freq[10];   //array to store frequency of digits
    scanf("%s",str);
    
    int len = strlen(str); //here we take a variable to store length of input string
    
    for(int i=0;i<10;i++) //initialize all elements of frequency array to zero
        freq[i] = 0;
        
    for(int i=0;i<len;i++)
    {
        if(str[i] >='0' && str[i] <= '9') //we check if ith character of string is a digit
        {
            int t = str[i] - '0'; //temporary variable, converts character to int
            freq[t] += 1; //we increment frequency of ith digit by 1
        }
    }
    
    for(int k=0;k<10;k++) //here we simply display frequency of digits in desired output format
        printf("%d ",freq[k]);
    return 0;
}