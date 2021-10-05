// Maximize Distance to Closest Person

// Explanation : find number of empty seats between two person .for every empty seats do empty++
//               and result = max((empty+1)/2,result). when you encounter person while traversing do empty =0.

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int empty =0;
        int result=0;
        int idx1=-1,idx2=-1;
        
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                empty=0;
                if(idx1==-1)idx1=i;
                idx2=i;
            }
            else{
                empty++;
                result=max((empty+1)/2,result);
            }
        }
        result=max({result,idx1,n-1-idx2});
        return result;
    }
};
