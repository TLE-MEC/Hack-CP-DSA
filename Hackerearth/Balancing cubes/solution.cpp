#include<bits/stdc++.h>
using namespace std;


//here we have to find the minimum number of operations required to get the impure cube among pure cubes
//Also we have to consider worst case scenario too.
//as impure cube is of less weight than pure cube you can divide n cudes into two group of n/2.
//the group which weights less will have impure one. We can repeat this with less weight group untill we have impure at last.

//but dividing n into 3 groups of n/3,we can find least weight group in 1 operation and also we are eliminating two groups i.e. 2n/3 cubes
//which is better than n/2 if we have divided into 2 groups.

//now there might be possibility that n wont be divisible by 3 that means
//group size will be n/3, n/3 and ((n/3)+1 or (n/3)+2).
//here (n/3, n/3 and (n/3)+2) can be resolved to (n/3)+1 , (n/3)+1 and n/3.
//So in the worst case we have to check max for (n/3)+1 only.

int numberOfOperations(int n){
    if(n<=1){
        return 0;
    }
    if(n==2||n==3){
        return 1;
    }
    if(n%3!=0){
        //if n is not divisible by three then checking for worst case
        return numberOfOperations((n/3)+1)+1;
    }
    else{
        return numberOfOperations(n/3)+1;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<numberOfOperations(n);

}
