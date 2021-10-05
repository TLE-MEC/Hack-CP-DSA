#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// The runningTime function.
int runningTime(vector<int> arr,int n) 
{
    int j=0,temp=0,count=0;
    //Algorithm for insertion sort
    for(int i=1;i<n;i++)
    {
        j=i-1;
        temp=arr[i];
        while(temp<arr[j])
        {
            arr[j+1]=arr[j];
            count++;
            j--;
        }
        arr[j+1]=temp;
    }
return count;//returning the variable that keeps track of the running time
}

//Main function
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;//getting the array size from the user
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);//taking user's input

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = runningTime(arr,n);//Call to the function

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
