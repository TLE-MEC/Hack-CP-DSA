#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    vector<int> result(n,100000);        //n <= 10^5 (constraint) and thus the dist has to be less.
    sort(c.begin(),c.end());         //sort the indices
    int prev =-1;
    for(int i=0;i<c.size()-1;i++)   //go to all stations
    {
        int currStation=c[i];      
        for(int j=currStation;j>prev;j--)
        {
           if((currStation-j)<result[j])     //if the station in front is less far from the previous station
                result[j] = currStation-j;
            else
                break;                      //rest all stations will also be far from the station ahead
        }
        for(int j=currStation+1;j<c[i+1];j++)
        {
            if((j-currStation)<result[j])    //if the previous station is less far from than the station ahead
                result[j] = j-currStation;
            else
                break;
        }
        prev = currStation;
    }
    int currStation=c[c.size()-1];            //this whole is for last satation
    for(int j=currStation;j>prev;j--)        
    {
       if((currStation-j)<result[j])
            result[j] = currStation-j;
        else
            break;
    }
     for(int j=currStation+1;j<n;j++)
    {
        if((j-currStation)<result[j])
            result[j] = j-currStation;
        else
            break;
    }
    // for(int i=0;i<result.size();i++)
    //     cout<<result[i]<<" ";
    int maxDistance = *max_element(result.begin(),result.end());  //take the maximum distance
    return maxDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

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
