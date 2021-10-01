// Two string are anagrams if and only if for every letter occurring in any of them the number of its occurrences is equal in both the strings.
// the only allowed letters are lowercase English letters, from a to z , the alphabet size is constant and its size is 26 . 
//  This allows us to assign a constant size signature to each of the substring of s.
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string input) {
    int length = input.size();
    map<string, int> m;
    m.clear();
    // iterate over all substrings of s.
    for(int i=0; i<length; i++){
        for(int j=1; j<length+1-i; j++){
            string t = input.substr(i,j);      
            sort(t.begin(), t.end());
            m[t]++;
            
        }
    }
    int ans = 0;
    
    for(map<string, int>:: iterator itr = m.begin(); itr !=m.end(); itr++).  // intialize the substring value
        ans += (long)(itr->second)*(itr->second-1)/2;
    return ans;
}
// The time complexity is O|s^3| since we iterate over all O|s^2| substrings of  and for each substring we compute its signature in O|s| time.

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
