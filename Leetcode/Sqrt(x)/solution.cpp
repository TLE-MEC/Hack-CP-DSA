/** Approach: We use long long int to avoid overflow. For searching a number binary search takes logn time so, I have used Binary search. **/


class Solution {
public:
    int mySqrt(int x) {
        
    long long int lo = 1, hi = x, mid, ans;
    while(lo <= hi){
        mid  = lo + (hi - lo)/2;
        if(mid * mid == x){
            return mid;
        }else if(mid * mid > x){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }    
      return hi;  
    }
};