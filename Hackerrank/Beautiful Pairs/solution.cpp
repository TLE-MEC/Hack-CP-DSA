#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int beautifulPairs(vector<int> A, vector<int> B) {     
    /*The catch is here is that we dont need to care 
      of the beautiful pairs index we just need to know the 
      number of beautiful pairs*/
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());     //sort both arrays
    int i=0,j=0;
    int pairs=0 , length = A.size(); 
    while(i<length) {
        if(A[i]<B[j]) {          //increment i if it is pointing to smaller elements than j 
            i++;
        }
        else if(A[i]>B[j]) {     //increment j if it is pointing to smaller elements than i
            j++;
        }
        else {                   //if both i and j are pointing to equal elements increment pairs 
            i++;j++;
            pairs++; 
        }
    }
    return pairs==length?pairs-1:pairs+1; //(pairs-1) beacuse no matter if the whole array is beautiful we have to change one element
}                                            

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split(rtrim(B_temp_temp));

    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = beautifulPairs(A, B);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
