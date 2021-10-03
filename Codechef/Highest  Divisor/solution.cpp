#include <iostream>
using namespace std;

int main() {
	int n,md; 
	cin>>n;	//taking input of the number to be checked
	for(int i=10;i>=1;i--)	//checking for maximum divisor within 10 as per question
	{
	    if(n%i==0){	//when we get the maximum divisor we store it in md then break to come out of the loop
	        md=i;
			break;
	    }
	}
	cout<<md;	//we print md(ans)
	return 0;
}
