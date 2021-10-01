//In this problem - we have to check if an array has an ideal permutation
// i.e., if the number of global inversions == number of local inversions


//The number of global inversions is the number of the different pairs (i, j) where:
// 0 <= i < j < n , nums[i] > nums[j]
// The number of local inversions is the number of indices i where:
// 0 <= i < n - 1 , nums[i] > nums[i + 1]
// Return true if the number of global inversions is equal to the number of local inversions.

//Solution Logic -
// To find the number of local inversions, we just iterate through the array once and
// check if an element > its adjacent element, increment the count 
// To find the global inversions, make use of the merge sort logic
// Merge sort compares every element with the other in nlogn time complexity 
// and hence is the most efficient approach

#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int temp[],int l,int mid,int h,int &count){
        int i=l,j=mid+1,k=l;
        while(i<=mid and j<=h){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
                
                count=count+(mid-i+1); //here, if arr[i]>arr[j] => all the elments > arr[i] are also > arr[j]
                // hence we add (mid-i+1) to the count of global inversions
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        while(j<=h){
            temp[k++]=arr[j++];
        }
        
        for(int i=l;i<=h;i++){
            arr[i]=temp[i];
        }
        
        return count;
    }

// Everything else is same as the logic of the merge sort algorithm   
int merge_sort(int arr[],int temp[],int l,int h){
        if(l>=h) return 0;
        
        int mid=(l+h)/2;
        int count=0;
        count+=merge_sort(arr,temp,l,mid);
        count+=merge_sort(arr,temp,mid+1,h);
        merge(arr,temp,l,mid,h,count);
        return count;
    }

int global_inv(vector<int> &A){
        int n=A.size();
        
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=A[i];
        }
        
        int temp[n];
        return merge_sort(arr,temp,0,n-1);
    }
    
int local_inv(vector<int> &A){
        int n=A.size();
        
        int count=0;
        for(int i=0;i<n-1;i++){
            if(A[i]>A[i+1]) count++;
        }
        return count;
    }

bool isIdealPermutation(vector<int>& A) {
        if(global_inv(A)==local_inv(A)) return true;
        return false;
    }

//Driver code
int main(){

    vector<int> v = {0,1,2};
    cout<<isIdealPermutation(v);

}
