/** Approach: First calculate frequency of characters in a string and convert it into a different string frequencies of character appended with # or any character 
to understand that similar group of strings will have same string of frequency and # and create a map to push the strings which have same group string. **/


class Solution {
public:
    string Get_groupid(string str){
        vector<int> freq(26, 0);
        for(int i = 0; i < str.size(); i++){
            freq[str[i]-'a']++;
        }
        string res;
        for(int i = 0; i < 26; i++){
            res = res + to_string(freq[i]) + '#';
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // define map
        vector<vector<string>> res;
        unordered_map<string, int> history;
        for(int i = 0; i < strs.size(); i++){
            string ana = Get_groupid(strs[i]);
            if(history.find(ana) == history.end()){
                res.push_back({});
                history[ana] = int(res.size() - 1);
            }
            res[history[ana]].push_back(strs[i]);
        }
        return res;
    }
};