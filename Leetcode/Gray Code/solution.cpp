class Solution {
public:
    vector<int> grayCode(int n) {
        // since, every integer is in the inclusive range [0,2^n-1]
        // therefore, we can use 2^n as upper-limit
        // lets store this upper limit in variable ul
        int ul=pow(2,n);
        // crreate an "ans" vector that will store the desired outputs
        vector<int> ans;
        for(int i=0;i<ul;i++){
            // we can generate gray code sequence just by taking "xor" of "i" and "(i>>1) i.e. binary representation of "i" right shifted by 1 bit"
            ans.push_back(i^(i>>1));
        }
        // finally, return the output vector
        return ans;
    }
};