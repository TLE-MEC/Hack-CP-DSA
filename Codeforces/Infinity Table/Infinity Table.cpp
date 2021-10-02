#include<iostream>
#include<fstream>
#include<vector>
#include<climits>
#include<cmath>
#include<map>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vector<ll>> vvll;
typedef map<ll,bool> mllb;
typedef unordered_set<char> ucst;
typedef unordered_map<ll,bool> umllb;
#define PI 3.1415926535897932384626
#define pb push_back
#define mp make_pair
const ll mod=10e9+7;
 
class Triplet
{
    public:
        ll gcd;
        ll x;
        ll y;
    Triplet(ll gcd,ll x,ll y)
    {
        this->gcd=gcd;
        this->x=x;
        this->y=y;
    }
};
 
class Sieve
{
    private:
        void genPrime()
        {
            for(ll i=0;i<n+1;i++)
                Prime.push_back(true);
            Prime.at(0)=false;
            Prime.at(1)=false;
            for(ll i=2;i*i<=n;i++)
                if(Prime[i])
                    for(ll j=i*i;j<=n;j+=i)
                        Prime[j]=false;
        }
 
    public:
        ll n;
        vector<bool> Prime;
 
        void printPrime()
        {
            for(ll i=0;i<=n;i++)
                if(Prime[i])
                    cout<<i<<" ";
            cout<<endl;
        }
 
        ll countPrime(ll l,ll h)
        {
            ll count=0;
            for(ll i=l;i<=h;i++)
                if(Prime[i])
                    count++;
            return count;
        }
    
        bool isPrime(ll x)
        {
            if(x>=0 && x<=n)
            {
                if(Prime.at(x))
                    return true;
            }
            return false;
        }
 
        Sieve(ll n)
        {
            this->n=n;
            genPrime();
        }
};
 
ll gcd(ll a,ll b) {return a==0?b:gcd(b % a, a);}
 
Triplet gcdExt(ll a,ll b)
{
    if(b==0)
        return Triplet(a,1,0);
    Triplet smallRes=gcdExt(b,a%b);
    return Triplet(smallRes.gcd,smallRes.y,smallRes.x-(a/b)*smallRes.y);
}
 
ll multiModInvrs(ll a,ll m)
{
    //if there exist any b (1<=b<=m-1) for which (a.b)modm=1 then b is multiplicative modulo inverse of a and m
    //Multiplicative modulo inverse exists only if gcd(a,m)=1;
    //If returns -1 mean multiplicative modulo inverse doesn't exist.
    Triplet ans=gcdExt(a,m);
    if(ans.gcd==1)
    {
        ll B=ans.x;
        if(B<0)
            B+=m;
        return B;
    }
    else
        return -1;
}
 
vector<ll> arr;
 
bool isPftSqur(double x,double y)
{
    return x==y;
}
 
void solve()
{
    int n;
    cin>>n;
    double ceilSq=ceil((double)sqrt(n));
    double floorSq=floor((double)sqrt(n));
    ll sqNum=ceilSq*ceilSq;
    if(isPftSqur(ceilSq,floorSq))
        cout<<ceilSq<<" "<<1<<endl;
    else
    {
        if(n<sqNum && n>=sqNum-ceilSq+1)
            cout<<ceilSq<<" "<<sqNum-n+1<<endl;
        else
        {
            ll x=sqNum-n;
            ll y=x-ceilSq+1;
            ll z=ceilSq-y;
            cout<<z<<" "<<ceilSq<<endl;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    //t=1;
    while(t--) {
        /*if(solve())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;*/
        solve();
        //cout<<solve()<<endl;
    }
 
    return 0;
}