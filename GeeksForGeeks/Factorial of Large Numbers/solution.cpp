#include<bits/stdc++.h>

#define pb push_back        //a shortcut to prevent writing push_back repeatedly 

class Solution {
public:
    vector<int> factorial(int N){
    
        vector<int> fact;
        
        //push back 1 to the vector 
        fact.pb(1);

        if(N==0) {
            return fact;
        }
        
        //Multiply from 1 to N (inclusive)
        for(int i=1; i<=N; i++) {
            // Initialize carry as 0
            int carry = 0;

            // Do following for i = 0 to res_size - 1 
            //      a) Find value of res[i] * x + carry. Let this value be prod. 
            //      b) Update res[i] by storing last digit of prod in it. 
            //      c) Update carry by storing remaining digits in carry.
            for(int j=0; j<fact.size(); j++) {
                int prod = i*fact[j] + carry;
                fact[j] = prod%10;
                carry = prod/10;
                
            }
            // 3) Put all digits of carry in res[] and increase res_size by number of digits in carry.

            while (carry) {   
                fact.pb(carry%10);
                carry = carry/10;
            }
        }

        //the factorial stored will be in reversed order (we multiply right to left but we store it in left to right, i.e, from 0th index)
        //return the reverse of the vector
        reverse(fact.begin(), fact.end());   
        return fact;
    }
};