#include<bits/stdc++.h>
using namespace std;
#define int long long int   //To avoid overflows, no major difference in runtime
#define vi vector<int>      //Macros to make it shorter to write these
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)

bool compare(vector<int> v1, vector<int> v2){   //Helper function that compares the two contestants and returns who the winner is
    int answer = 0;
    for(int i=0; i<5; i++){
        answer += v1[i]<v2[i];
    }
    return (answer>2);
}
 
void solve(){
    int n; cin>>n;
    vector<vector<int>> v(n);   //A vector of vectors to take out input in
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){ //Taking in input
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    int current = 0;            //Variable to store the index of a current answer      
    //Simple greedy approach, the answer has to be winner over all contestants, so we can iterate over them one by one
    for(int i=1; i<n; i++){
        if(compare(v[i], v[current])){  //Checks who wins
            current = i;
        }
    }
    //We check if our answer is the winner over all the other ones, if not we print -1
    for(int i=0; i<n; i++){
        if(compare(v[i], v[current])){
            cout<<"-1\n";
            return;
        }
    }
    //We print the answer
    cout<<current+1<<endl;
    return;
}
 
 
signed main(){          //If we write int it'll run into a compilation error as we've defined int as long long so we write int as signed int
    int t;
    cin>>t;
    while (t--){    //We run the code for every test case
        solve();       
    }
    return 0;
}