// Sample Input 0
// 0 3 4 2

// Sample Output 0
// YES

// Explanation 0
// The 1st kangaroo starts at x=0 and has a speed of 3 units/sec and the 2nd kangaroo starts at x=4 with a speed of 2 units/sec. Both the kangaroos will meet at t=4sec at x=12 units. Hence output will be 1.

// Sample Input 1
// 0 2 5 3

// Sample Output 1
// NO

// Explanation 1
// The second kangaroo has a starting location that is ahead (further to the right) of the first kangaroo's starting location (i.e., ). Because the second kangaroo moves at a faster rate (meaning ) and is already ahead of the first kangaroo, the first kangaroo will never be able to catch up. Thus, we print NO.


#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2) 
{
    if((x1>x2 && v1>v2) || (x2>x1 && v2>v1))
        return "NO";
    else if(x1==x2)
        return "YES";
    else
    {
        int max,min,max_speed,min_speed;
        if(x1>x2)
        {
            max = x1;
            max_speed = v1;
            min = x2;
            min_speed = v2;
        }
        else 
        {
            max = x2;
            max_speed = v2;
            min = x1;
            min_speed = v1;
        }
        while(max>min)
        {
            max+=max_speed;
            min+=min_speed;
            if(max==min)
                return "YES";
        }
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string x1V1X2V2_temp;
    getline(cin, x1V1X2V2_temp);

    vector<string> x1V1X2V2 = split_string(x1V1X2V2_temp);

    int x1 = stoi(x1V1X2V2[0]);

    int v1 = stoi(x1V1X2V2[1]);

    int x2 = stoi(x1V1X2V2[2]);

    int v2 = stoi(x1V1X2V2[3]);

    string result = kangaroo(x1, v1, x2, v2);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}