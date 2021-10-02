/**********************************************************************
 * Ejercicio: Maester's Map                                           *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1855 *
 * Lenguaje: C++                                                      *
 * Autor: Jhoser Pacheco                                              *
 *********************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
int lar,anc,x=0,y=1,mx=0,my=0;
bool chest=false;
string mapa[102];
bool vis[102][102];
 
void init(){
	chest=false;
	x=0,y=1,mx=0,my=0;
	memset(vis,false,sizeof(vis));
}
 
void solve(){
		while(!chest){
		if(vis[my][mx] || mx>=lar ||my>=anc){
			cout<<"!\n";
			break;
		} 
		vis[my][mx] = true;
 
		if(mapa[my][mx]=='>'){
			y=0;
			x=1;
		}
		if(mapa[my][mx]=='<'){
			y=0;
			x=-1;
		}
		if(mapa[my][mx]=='^'){
			y=-1;
			x=0;
		}
		if(mapa[my][mx]=='v'){
			y=1;
			x=0;
		}
		if(mapa[my][mx]=='*'){
			cout<<"*\n";
			chest=true;
		}
	//	cout<<mapa[my][mx]<<" ";
	//	cout<<endl;
		my+=y;
		mx+=x;
	}
}
 
int main() {
	while(cin>>lar>>anc){
		init();
		for(int o =0;o<anc;o++){
			cin>>mapa[o];
		}
	solve();
	}
	return 0;
}