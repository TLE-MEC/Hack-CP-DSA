class Solution {
public:
    string multiply(string num1, string num2) {  
        // handle edge-case where the product is 0
        if (num1 == "0" or num2 == "0") 
            return "0";
        
        // num1.size() + num2.size() == max no. of digits
        vector<int> num(num1.size() + num2.size(), 0);
        
        // build the number by multiplying one digit at the time
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); 
                //string to number  
                num[i + j] += num[i + j + 1] / 10; 
                // getting the carry
                num[i + j + 1] %= 10; 
                //storing the remainder
            }
        }
        
        // skip leading 0's
        int i = 0;
        while (i < num.size() and num[i] == 0) 
            ++i;
        
        // transform the vector to a string
        string res = "";
        while (i < num.size()) 
            res.push_back(num[i++] + '0'); // converting to string
        
        return res;
    }
};


// TLE
// string multiply(string num1, string num2) {  
//     return to_string(stoi(num1) * stoi(num2));  
// }