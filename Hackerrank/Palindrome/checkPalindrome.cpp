#include<iostream>
#include<string>
using namespace std;

bool checkPalin(string arr, int l, int s=0){
    //base condition 
    //if starting index is greater then ending index then stop and return True
    if (l<s){
        return true;
    }
    //if start and end are not equal then not palindrome
    if (arr[s] != arr[l]){
        return false;
    }
    
    //call recursion for next element from start and end
    return checkPalin(arr, l-1, s+1);
}

int main(){
    //take input
    string arr;
    cin>>arr;
    //calculate length
    int n = arr.length();
    
    //if palindrome then print YES
    //else print NO
    
    if (checkPalin(arr, n-1)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }   
}