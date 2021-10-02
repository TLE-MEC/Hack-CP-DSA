#include<bits/stdc++.h>
using namespace std;
#define N (int)1e6

//Square of Prime Number will be T-Prime.
//As n = 1e12, its square root will be 1e6.
//Hence finding all prime numbers via sieve of eratosthenes.

bool * allPrime(){
    static bool isPrime[N+1];
    for(int i=0;i<=N;++i) isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<=N;++i){
        if(isPrime[i] == true){
            for(int j=i*i;j<=N;j+=i) isPrime[j] = false;
        }
    }
    return isPrime; //an array which tells whether a number (less than 1e6) is prime or not.
}
 
int main(){
    bool *p;
    p = allPrime();
 
    int n; cin>>n;
    while(n--){
        long long int input; cin>>input;
        if( (int)sqrt(input) == (double)sqrt(input) ) //checking whether input number is perfect square or not.
        {
            // Finding the square root of the input number.
            // If that number is prime then print YES otherwise print NO.
            int check = sqrt(input); 
            if( *(p+check) == 1) cout << "YES" << endl; 
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
 
    return 0;
}
