class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int sum=0;
        // Split the number into digits using stringstream
        stringstream ss;
        ss << n;
        string str = ss.str();
        for(int i=0;i<str.size();i++){
            sum=sum+((str[i]-'0')*(str[i]-'0'));
            }
        //check if sum is present in the set
        if(s.find(sum) != s.end()){
            return false;
        }
        //if sum is not present, add it to the set
        else{
            s.insert(sum);
        }
        //repeat the previous procedure for sum
        while(true){
        stringstream ss;
        ss << sum;
        string str = ss.str();
        sum=0;
        for(int i=0;i<str.size();i++){
            sum=sum+((str[i]-'0')*(str[i]-'0'));
            
        }
        //check if sum is a happy number
        if(sum==1){
            return true;
        }
        else{
            //Return false if the number is not a happy number
            if (s.find(sum) != s.end()){
                return false;
            }
            else{
                s.insert(sum);
            }
            
        }
        
    
        
        
    }
        return false;
    }
};
