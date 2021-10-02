#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define mod 1000000007
#define maxN 100005
#define inf 1e16
#define sp " "
#define f first
#define s second


// If m<n−1

// , the graph can't be connected, so the answer should be No.

// If m>n(n−1)/2

// , the graph must contaion multiedges, so the answer should be No.

// If m=n(n−1)/2
// , the graph must be a complete graph. The diameter of the graph is 1. If k>2

// the answer is YES, otherwise the answer is NO.

// If n=1
// , the graph has only one node, and its diameter is 0. If k>1

// the answer is YES, otherwise the answer is NO.

// If m=n−1
// , the graph must be a tree, the diameter of the tree is at least 2 when it 
// comes to each node has an edge with node 1. If m>n−1∧m<n(n−1)2, we can add 
// edges on the current tree and the diameter wouldn't be more than 2. Since 
// the graph is not complete graph, the diameter is more than 1, the diameter 
// is just 2. If k>3 the answer is YES, otherwise the answer is NO.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll diameter;
		ll p = (n*(n-1))/2;
		if(m<(n-1) || (m>p)){

			cout<<"NO"<<endl;
			continue;
		}
		if(n==1){
			diameter = 0;
		}else if(m==p){
			diameter = 1;
		}else{
			diameter = 2;
		}
		if(diameter<(k-1)){
			cout<< "YES" << endl;
		}else{
			cout<< "NO" << endl;
		}

		
	}



	return 0;
}