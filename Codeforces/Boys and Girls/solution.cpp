#include <bits/stdc++.h>
using namespace std;
 
int main(){
    
    freopen("input.txt", "r", stdin); //read input from input.txt
    freopen("output.txt", "w", stdout); // write output in output.txt
    
    // initialize variables of count for boys and girls
	long long int count_g, count_b;
	cin >> count_b >> count_g; // take input as prescribed
 
	while (count_g || count_b){ // while either count is greater than 0 run the loop
		if (count_b>count_g){
			// if boys count is more start with boys and then add girls
            cout << "B";
			if (count_g){
				cout << "G";
				count_g--; //substract 1 from count of girls
			}
			count_b--; //substract 1 from count of boys
		} else {
            // if girls count is more, start with girls and then add boys
			cout << "G";
			if (count_b){
				cout << "B";
				count_b--; //substract 1 from count of boys
			}
			count_g--; //substract 1 from count of girls
		}
	}
}
 
	
 