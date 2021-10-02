/*
code by iamkakashi
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nextPower(ll n)
{

    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return (log10(n)/log10(2));
}
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
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
ll binarySearch2(ll arr[], ll l, ll r, ll x)
{
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
    cin>>t;
    while(t--){
        ll n,k,ans=0;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        if(a[0]==a[n-1]){
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
        else{
            ll moves=0;
            while(moves<n){
                if(k>=a[n-1]){
                    ans+=(n-moves);
                    break;
                }
                ll index=binarySearch(a,0,n-1,k);
                if(index!=-1){
                    a[index]=0;
                    k=2*k;
                    moves++;
                }
                else{
                    ll ind=binarySearch2(a,0,n-1,k);
                    ll q=a[ind+1]/k;
                    if(ind!=-1){
                        ll q1=(k*q);
                        if(q1!=a[ind+1]){
                            q=q+1;
                        }
                        q=nextPower(q);
                        if(a[ind]!=0){
                            ll p=a[ind+1]/a[ind];
                            ll p1=(a[ind]*p);
                            if(p1!=a[ind+1]){
                                p=p+1;
                            }
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
                sort(a,a+n);
                ans++;
            }
        }
        cout<<ans<<endl;
    }

}

