// Time complexity : O(n) where n is the length of the binary string
// Space: O(1)
class Solution {
public:

    int numSub(string s) {
      long long  unsigned int n = s.size(),ans=0,count=0; // initializing necessary variables
      for(int i=0;i<n;i++){
      if(s[i]=='1'){                                       // increments count by 1 if the ith indice of the given sting has a value of '1'
        count++;                                          
      }                                                    //otherwise 
        else {
          if(count!=0)ans+=(((count*(count+1))/2)%(1000000000 + 7));    // adds the value of count to ans and assignes count with value of zero
          count=0;                                                      //  NOTE: Modulo of 10000000007 as the value of ans can be too high   
        }
    }
      ans+=((count*(count+1))/2)%(1000000000 + 7 );
      return ans;
    }
};
