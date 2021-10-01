#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int n;
	long long int count=0;
    
	cin >> n; // input the number
	while(n!=0){		
		if (n%10==4 || n%10 ==7){ //check if the number is 4 or 7
			count++; // increment the count of lucky numbers
		}
		n/=10; //remove the right most digit from the number
	}
    // check if the count is a lucky number 
	if (count==4 || count==7)
		cout << "YES";
	else
		cout << "NO";

}