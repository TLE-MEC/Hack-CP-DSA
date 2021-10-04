#include <bits/stdc++.h>
using namespace std;
#define inf 1e18
#define int long long
const int mod1=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
int gcd(int a,int b){int c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
int expo(int a,int b){int res=1;while(b>0){if(b&1) res*=a%mod1;a*=a%mod1;b>>=1;}return res;}

/*
to find min number of steps(or power of 2) we use the formula:
    given_number = 2^(power x) * (random odd number y)
    Taking log on both sides: (iterate over  ceil(log2(given_number)) of x to 1)
        log(given_number)  = log(2^(pow x)) + log(y)
        log(y) = log(given number) - (pow x)log(2)
        y = antilog(log(given number) - (pow x)log(2))
    if (2^x) * y  == num and y is odd : return power x
    else return infinite.
*/
int findpow(int num){
    int maxpow = ceil(log2(num));
    for(int i=maxpow; i>0; i--){
        int anti = round(pow(2.718281828,log(num)-(i*log(2))));
        if(expo(2,i)*anti == num && anti%2) return i;
    }
    return inf;
}

int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,gd=0,mini=inf;
        cin>>n;
        vector<int> v(n);
        for(int &i:v){
            cin>>i;
            gd = gcd(gd,i); // find gcd of array using gcd function.
            mini = min(findpow(i),mini); // find min steps 
        }
        if (gd%2) cout << 0 << "\n"; // if gcd is already odd print 0 steps
        else cout << mini << "\n"; // else print minimum steps
    }
}


/*
Problem :
    Given number of elements in an array and the array elements; for each test case, 
    print a single line containing one integer - the minimum number of 
    operations after which GCD of all the elements in the array becomes an odd integer.
*/
/*
<--Mathematical approach to the problem-->
LOGIC : 
    For the gcd to be odd, there should be atleast one odd integer in an array.
    So we find that element in given array whose division by 2 would lead to an odd number in 
    minimum number of steps. 
    Example: 
        12 => 12/2 = 6/2 = 3 ===> 2 steps (2^2 * 3)
        24 => 24/2 = 12/2 = 6/2 = 3 ===> 3 steps (2*3 * 3)
    Choosing 12 over 24 would be preferable. 
    hence we have to seperate all powers of 2 from the number and find the max power of 2. 
*/
