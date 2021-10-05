#include<bits/stdc++.h>

using namespace std;  
 
#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
 
int n,a,b;
 
void run() {
	scanf("%d%d%d",&n,&a,&b);
	int l=1,h=a+b+1;
	while(l+1<h) {
		int m=l+(h-l)/2;
		int cnt=a/m+b/m;
		if(cnt>=n&&m<=a&&m<=b) l=m; else h=m;
	}
	printf("%d\n",l);
}
 
int main() {
	run();
	return 0;
}