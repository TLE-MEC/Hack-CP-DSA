// Solution for ACM ICPC Team problem
#include<bits/stdc++.h>
using namespace std;
/*
The idea here is to find the number of subject expertise for
every possible combination and store it in an array. Then find the
maximum expertise and count the number of its occurences in the
storage array. Then display both of them.
*/

// Function to find subject expertise for two students
int subjects(string a, string b, int size){
  int s = 0;
  for(int i=0; i<size; i++){
    if(a[i] == '1' || b[i] == '1')
      s++;
  }
  return s;
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<string> s; // Array storing subject expertise of each student
  while(n--){
    string a;
    cin>>a;
    s.push_back(a);
  }
  vector<int> v; // Storage array
  for(int i=0; i<s.size(); i++){
    for(int j=0; j<s.size(); j++){
      if(j != i){
        v.push_back(subjects(s[i], s[j], m)); // Storing subject expertise of each pair
      }
    }
  }
  int x = *max_element(v.begin(), v.end()); // Finding maximum element
  int teams = 0; // Number of teams with maximum expertise
  for(int i=0; i<v.size(); i++){
    if(v[i] == x)
      teams++;
  }
  cout<<x<<'\n'<<teams/2<<'\n';
  return 0;
}
