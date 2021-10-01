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
    
    for(int i=0; i<length; i++){
        for(int j=1; j<length+1-i; j++){
            string t = input.substr(i,j);
            sort(t.begin(), t.end());
            m[t]++;
            
        }
    }
    int ans = 0;
    
    for(map<string, int>:: iterator itr = m.begin(); itr !=m.end(); itr++)
        ans += (long)(itr->second)*(itr->second-1)/2;
    return ans;
}

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
