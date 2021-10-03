#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;while(t--){
	    int n,k;cin>>n>>k;
	int a[n]={0};
//taken the array to store and print the numbers
	int count=n;//count taken to ignore the index=value problem
	if(abs(n-k)==1) cout<<"-1";/*if there are numbers satisfying the ondition in if statement then it is impossible 
    to achieve the goal as only one number will be left with one position for eg take n=2 and k=1 in{1,2} 
    there are 2 numbers satisfying the condition which is greater than k and in {2,1} it is 0 and it is less than k */
	    else{
	    for(int i=1;i<=k;i++){
	    a[i]=i;cout<<a[i]<<" ";}
	    for(int j=k+1;j<=n;j++){
	        a[j]=count;
	        if(j==count){
	            a[j]--;
	        }
	        if(a[j]==a[j-1])
	        a[j]++;
	        count--;
	        cout<<a[j]<<" ";
	    }
	    }
	    cout<<'\n';
	
	}
    /*in else we printed the numbers from 1 to k and then starting it from n took the count as n
    on each iteration assigning the count to a[index] and cheking if it is equal to index then change it with the next one 
    if it is equal to previous one then we inrease it by one and this satifies the condition given in question.*/
	return 0;
}
