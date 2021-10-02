/**********************************************************************
 * Ejercicio: The Change                                           *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/2685 *
 * Lenguaje: C++                                                      *
 * Autor: Jhoser Pacheco                                              *
 *********************************************************************/

// Print a greeting for the time of day it is

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin>>n){
		if(n>=90 && n<180) cout<<"Boa Tarde!!\n";
		else if(n>=0 && n<90 || n == 360) cout<<"Bom Dia!!\n";
		else if(n>=270 && n<360) cout<<"De Madrugada!!\n";	
		else cout<<"Boa Noite!!\n";

	}
	return 0;
}