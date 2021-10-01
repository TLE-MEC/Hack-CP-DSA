#include <bits/stdc++.h>

using namespace std;
// ======================================================
string timeConversion(string s) {
    // seperates AM/PM from the time 
    string t = s.substr(8);
    string v,b;
    int h;
    if(t=="AM"){
        v=s.substr(0,8); // taking the time
        b=s.substr(0,2); // taking only the hour section of the given time
        // if the given hour is 12, then it is midnight.
        if(b=="12"){
            b="00"+s.substr(2,6); // since it is midnight, concat 00 to the minutes and second section.
            return b;
        }
        return v;
    }
    else if(t=="PM"){
        // convert the hour part of the time to int
        h = stoi(s.substr(0,2));
        // checking if it is equal not equal to 12. as if it is equal to 12:00:00 PM, then it is considered to be noon
        // and there is no need to add 12 to make it into 24 hour format.
        if(h!=12){
            h+=12; // adding 12 to the hour if h is not equal to 12
            v=to_string(h)+s.substr(2,6); 
        }
        else{
            v="12"+s.substr(2,6); //if it is equal to 12. there is no need to change it.
        }
    }
    return v;
}
// =======================================================
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
