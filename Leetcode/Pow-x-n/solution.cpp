/*
Time complexity = O(log n)

*/
class Solution {
public:
    double calculate(double x,int n){
        
        double ans = 1.0; //initialising result
        while(n){
            if(n%2)     //if power is odd multiply with x
                ans = ans*x;
           n=n/2;
           x=x*x; // convert x to x^2
         
        }
        return ans;
    }
    double myPow(double x, int n) {
        double power = (n<0)?calculate((double)1.0/x,n):calculate(x,n); // If power is negative then finding (1/x)^n
        return power;
    }
};
