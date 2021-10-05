/*
Approach: To do binary search on the answer
That is the minimum speed to reach on the time.
The search space will be from [0,1^10].
*/

class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int n = dist.length;
        long low = 0, high = (long)1e10;
        long ans = -1;
        
        // Performing BinarySearch
        while(low<=high) {
            long mid = (low+high)/2;
            
            // Calculating total time taken if speed is mid.
            double sum = 0;
            for(int i=0;i<n-1;++i) {
                sum += Math.ceil((double)dist[i]/mid);
            }
            sum+=(double)dist[n-1]/mid;
            
            if(sum<=hour) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return (int)ans;
    }
}
