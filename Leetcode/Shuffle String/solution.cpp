class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // indices contains the order in which each letter should be rearranged
        string newStr=s;
        for(int i=0;i<indices.size();i++){
            // adding the letter of the string s to the new index.
            // eg: if the string s = cat and indices is [2,0,1] then newStr[indices[i]] = newStr[2] (if i=0)
            newStr[indices[i]]=s[i];
        }
        return newStr;
    }
};