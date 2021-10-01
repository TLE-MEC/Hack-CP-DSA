//solution class
class Solution {
//public access modifier
public:
    //function
    int findMiddleIndex(vector<int>& nums) {
        //vector declaration to store left sum and right sum
        vector<int>lsum,rsum;
        //initializing left sum with 0
        lsum.push_back(0);
        //pushing values in vector by adding next index 
        for(int i=1;i<nums.size()+1;i++){
            lsum.push_back(lsum[i-1]+nums[i-1]);
        }
        //keeping last index as 0
        lsum.push_back(0);
        //working with rsum vector
        rsum.push_back(0);
        rsum.push_back(lsum[nums.size()]);
        for(int i=2;i<nums.size()+1;i++){
            rsum.push_back(rsum[i-1]-nums[i-2]);
        }
        rsum.push_back(0);
        // rsum.push_back(lsum[nums.size()]);
        for(int i=0;i<lsum.size();i++){
            cout<<lsum[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<rsum.size();i++){
            cout<<rsum[i]<<" ";
        }
        //checking the overlapping values and finding for a match
        for(int i=0;i<lsum.size()-2;i++){
            if(lsum[i]==rsum[i+2]){
                    return i;
            }
        }
        //if no match found, returning -1
        return -1;
    }
    
};
