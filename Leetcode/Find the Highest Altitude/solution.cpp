class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       vector<int> alt(gain.size()+1,0);      // vector alt defined
        
        for(int i=1;i<gain.size()+1;i++) {    // loop 
          alt[i]=gain[i-1]+alt[i-1];
      }
        
        return *max_element(alt.begin(),alt.end()); // returning the maximum of vector alt
    }
};
