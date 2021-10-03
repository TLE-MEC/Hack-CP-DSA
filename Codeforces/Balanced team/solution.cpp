#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i]; //to input the programming skill of the ith student
    }
    sort(ar,ar+n); //sorting the array of programming skills in ascending order
    int ans=0; //to store the maximum possible number of students in balanced team
	int j=0;
	for (int i=0;i<n;++i) {
		while (j<n&&ar[j]-ar[i]<=5) { //to find the continuous number of students whose difference in programming skill is less than or equal to 5
			j++;
			ans=max(ans,j-i); //storing the maximum possible value
		}
	}
    cout<<ans<<endl;
}
