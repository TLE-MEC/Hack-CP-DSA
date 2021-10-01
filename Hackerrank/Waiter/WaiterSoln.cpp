#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> split_string(string);

// function to get the prime number from 2 to 10^4
vector<int> getPrime (){
    vector<int> prime;
    int lower = 2;
    int upper = 10000;
    for (int i=lower; i<upper; i++){
        bool isPrime = 0;
        for(int j=lower; j<=sqrt(i); j++){
            if (i%j == 0)
                isPrime = 1;
        }
        if (isPrime == 0)
            prime.push_back(i);
    }
    return prime;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> result, strA, strB;   
    int num;
    vector<int> prime = getPrime(); // assign all the prime number to array
    
    for (int i=0; i<q; i++){
        int size = number.size();
        
        for (int j=0; j<size; j++){
            num = number.back();
            
            // if the number is divisible by the prime number, store it to stack strB
            // if not, store it to stack strB
            if( num % prime[i] == 0 ){
                strB.push_back(num);
                number.pop_back();
            }
            else{
                strA.push_back(num);    
                number.pop_back();
            }
        }
        number = strA;  // do the iteration with number in the strA
        strA.clear();
        
        // move the strB stack value to the result stack
        while (!strB.empty()){
            result.push_back(strB.back());
            strB.pop_back();
        }
    }
    
    // if the strA stack not empty until all iteration, move it to result stack
    while (!number.empty()){
        result.push_back(number.back());
        number.pop_back();
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
