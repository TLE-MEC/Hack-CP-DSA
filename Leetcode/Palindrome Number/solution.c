#include<stdio.h> //using standard input output header file

// This function takes an integer and returns its reverse number
// Ex: 12345 -> 54321 | 20055002 -> 20055002
int reverseNum(int num){                  // Lets take num = 105
    int rev = 0;                          //the rev or reverse is initially kept 0
    while(num>0){                         // num = 105                                                                   num = 10                  num = 1
        int rem = num%10;                 // rem = 105%10 = 5                                                            rem = 10%10 = 0           rem = 1%10 = 1
        rev = 10*rev + rem;               // rev = 10*0 + 5 = 0+5 = 5 , the last digit of num is now first digit of rev  rev = 10*5 + 0 = 50       rev = 10*50+1 = 501(expected reverse output)
        num/=10;                          // num = 105/10 = 10  (int / int gives int result)                             num = 10/10 = 1           num = 1/10 = 0 (while loop will terminate)
    }
    return rev;                           // rev = 501 is returned
}

// This function takes the original number and reverse and 
// checks if they are equal or not and
// outputs answer accordingly
void isPalindrome(int num, int rev){
    if(num == rev) printf("true");        // In case of single line after if, curly braces can be omitted
    else printf("false");
}

// Start of main function
// main function is the entry point of the program
int main(){
    int num, reverse;
    printf("Enter the number: ");
    scanf("%d",&num);
    reverse = reverseNum(num);
    isPalindrome(num, reverse);
    return 0;
}