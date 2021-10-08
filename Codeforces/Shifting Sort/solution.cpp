#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++) //macro so that initialisation for for loop does not have to be written over and over

 
int main(){
    int t;
    cin>>t;                     //Running the loop for every test case
    while (t--){
        //So we essentially do bubble sort and every time the least element is put in front
        //Time complexity is O(n*n) and since n is small this is well within bounds
        int n;
        cin>>n;
        vector<int> v(n);       //Make a vector to take in all the inputs
        rep(i,0,n){
            cin>>v[i];
        }
        vector<pair<int, int>> ranges; //We associate every value with the index and store the indices as a pair so that we can push the initial and final position of every value
        int k=0;                        //Keeps track of number of values in ranges, can be removes and ranges.size() used everytime
        for(int i=0; i<n; i++){
            int minn=v[i], min_idx=-1;  //Do bubble sort
            for(int j=i+1; j<n; j++){   
                if(v[j]<minn){          //Find the minimum element that can take the place of the current element
                    minn = v[j];
                    min_idx = j;
                }
            }
            if(min_idx!=-1){            //If we do find a minimum element, we shift all the other elements and put the minimum element at position i such that the array(vector) is now sorted upto i
                k++;
                int temp = v[min_idx];
                for(int k=min_idx; k>i; k--){
                    v[k] = v[k-1];
                }
                v[i] = temp;
                ranges.push_back({i+1, min_idx+1}); //Push the final and initial position of the value, number of rotations is simply their difference
            }
        }
        if(k==0){                          //If no changes we output 0
            cout<<k<<endl;
            continue;
        }
        cout<<k<<endl;                      //Else we output the required stuff in proper formatting
        for(int i=0; i<k; i++){
            cout<<ranges[i].first<<" "<<ranges[i].second<<" "<<(ranges[i].second - ranges[i].first)<<endl;
        }      
    }
    return 0;
}