#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool isSafe(int x,int y,int m,int n)
{
    return (x>=0 && x<m && y>=0 && y<n);
}
// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int m = A.size();                 //Number of rows
    int n= A[0].size();                //Number of columns
    int surfaceArea=0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {              //iterate over all elements of A 
            int box=A[i][j];                //it gives number of cubes
            surfaceArea+= ((6*box)-((box-1)*2));    //(6*box) since a cube has 6 surfaces and 
                                                    //((box-1)*2)) remove the surfaces that are in between
            if(isSafe(i-1,j,m,n))                   
                surfaceArea-= (A[i-1][j]>box?box:A[i-1][j]);   //check all 4 adjacent vertical columns 
            if(isSafe(i,j-1,m,n))                              //remove whichever is joint
                surfaceArea-= (A[i][j-1]>box?box:A[i][j-1]);
            if(isSafe(i+1,j,m,n))
                surfaceArea-= (A[i+1][j]>box?box:A[i+1][j]);
            if(isSafe(i,j+1,m,n))
                surfaceArea-= (A[i][j+1]>box?box:A[i][j+1]);  
        }
    }
    return surfaceArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

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
