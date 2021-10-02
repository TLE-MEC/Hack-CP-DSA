/*
code by iamkakashi
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// find nextpower of two for n
ll nextPower(ll n){
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return (log10(n)/log10(2));
}
// binary searching code
ll binarySearch(ll arr[], ll l, ll r, ll x){
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
// searching for index (ind) having value less than x and (ind+1) value greater than x using binary search 
ll binarySearch2(ll arr[], ll l, ll r, ll x){
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        if (arr[mid]<x && arr[mid+1]>x)
            return mid;

        if (arr[mid] > x)
            return binarySearch2(arr, l, mid - 1, x);

        return binarySearch2(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
    ll t;
    // input testcases
    cin>>t;
    while(t--){
        // input n & k where n is number of countries and k is amout of cure ready.
        ll n,k,ans=0;
        cin>>n>>k;
        ll a[n];
        // Array to store population of each country
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        // sort population of countries in increasing order
        sort(a,a+n);
        // if all countries have same population
        if(a[0]==a[n-1]){
            // if amount of cure available on day 1 are greater than or equal to needed.
            if(k>=a[0]){
                ans=n;
            }
            else{
                while(k<a[0]){
                    ans++;
                    k=k*2;
                }
                ans=ans+n;
            }
        }
        // if all countries doesn't have same population
        else{
            ll moves=0;
            while(moves<n){
                if(k>=a[n-1]){
                    ans+=(n-moves);
                    break;
                }
                // search for index having population equal to cures available
                ll index=binarySearch(a,0,n-1,k);
                // if there is no such population equal to cures available
                if(index!=-1){
                    a[index]=0;
                    k=2*k;
                    moves++;
                }
                // if there is population equal to cures available
                else{
                    // find index having value less than k and next index having value greater than k
                    ll ind=binarySearch2(a,0,n-1,k);
                    ll q=a[ind+1]/k;
                    // if there is no index which have value less than k and next index having value greater than k
                    if(ind!=-1){
                        ll q1=(k*q);
                        if(q1!=a[ind+1]){
                            q=q+1;
                        }
                        // find nextpower of two for q
                        q=nextPower(q);
                        if(a[ind]!=0){
                            ll p=a[ind+1]/a[ind];
                            ll p1=(a[ind]*p);
                            if(p1!=a[ind+1]){
                                p=p+1;
                            }
                            // find nextpower of two for p
                            p=nextPower(p);
                            if(p<=q){
                                k=2*a[ind];
                                a[ind]=0;
                                moves++;
                            }
                            else{
                                ll pre=a[n-1];
                                a[n-1]=a[n-1]-k;
                                ll temp=2*a[n-1];
                                if(temp<pre){
                                    a[n-1]=temp;
                                }
                                else{
                                    a[n-1]=pre;
                                }
                                k=2*k;
                            }
                        }
                        else{
                            ll pre=a[n-1];
                            a[n-1]=a[n-1]-k;
                            ll temp=2*a[n-1];
                            if(temp<pre){
                                a[n-1]=temp;
                            }
                            else{
                                a[n-1]=pre;
                            }
                            k=2*k;
                        }
                    }
                    // if there is index which have value less than k and next index having value greater than k
                    else{
                        ll pre=a[n-1];
                        a[n-1]=a[n-1]-k;
                        ll temp=2*a[n-1];
                        if(temp<pre){
                            a[n-1]=temp;
                        }
                        else{
                            a[n-1]=pre;
                        }
                        k=2*k;
                    }
                }
                // sort the population array
                sort(a,a+n);
                ans++;
            }
        }
        // output the answer
        cout<<ans<<endl;
    }

}

