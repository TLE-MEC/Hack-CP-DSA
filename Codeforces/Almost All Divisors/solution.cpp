#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)  // for fast input-output operations

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<long long, long long>
#define plll pair<long long, pair<long long, long long>>
#define nline "\n"
#define sz(x) ((int)(x).size())
#define all(a) a.begin(), a.end()

/*
Approach :- 

We are given all the divisors of a number except 1 and n ( number itself ) and we need to find if there exist a
number so that if we add 1 and n then all of the divisors of n are present.

We can sort all the divisors and then take product of first and last number, let say it NUM.
Then we find all the divisors of NUM and if all obtained divisors of NUM and the divisors
given to us are same (except 1 and n) then we can say ans exist and the ans is num; 

Let's understand with an example - 

let's assume the number is 16.
then divisors of 16 are = [1,2,4,8,16] (in sorted order)
we can see that product of firs and last number is the number itself 
i.e 1*16 = 16
    2*8 = 16
    4*4 = 16 ( as number of divisors are odd)

so we can now sort the divisors and take product of first and last and then find its divisors and if the divisors 
is equal to the given divisors then ans exist outherwise ans is -1. 

*/


void solve() {
	int t;
	cin >> t; // for t test cases
	while (t--) {
        ll n; cin>>n; // n is the number of divisors
        vector<ll> vec(n); // vector to store all the divisors
        for (int i = 0; i < n; i++) cin>>vec[i];
        sort(all(vec)); // sorting all the divisors
        ll ans1 = vec[0]*vec[n-1]; // calculating num
        vector<ll> res; // to store all the divisors of num except 1 and num i.t i>=2
        for (ll i = 2; i*i <= ans1; i++)
        {
            if(ans1%i == 0){
                if(i == ans1/i){
                    res.pb(i);
                }
                else{
                    res.pb(i);
                    res.pb(ans1/i);
                }
            }
        }
        sort(all(res));// sorting the res vector
        // checking if both the vectors are same or not
        // we can simply sort the array and check equaltiy by == operator
        if(res == vec) cout<<ans1<<nline; // if both are equal ans is num
        else cout<< -1 <<nline; // otherwise -1
	}
}


int32_t main()
{
    fastio();
    solve();
    return 0;
}