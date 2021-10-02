typedef long long ll;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        // Time limit exceeded in our first attempt - because this is O(n * k) solution
        // Kadane algorithm optimisation - O(n) approach
        
        ll s = 0;
        for(int i=0; i<arr.size(); i++)
            s = s + arr[i];
        
        ll n = arr.size();
        ll j=0, sum = 0, best = 0;
        
        // We will solve it using Kadane's algorithm - k times
        while(j < min(k,2))
        {
            for(ll i=0; i<n; i++)
            {   
                ll a = arr[i];
                sum = max(a, sum + a);
                best = max(sum, best);
            }
            j++;
        }
        
        // It means include, 0, for max of(2), or sum of one and max of last two
        ll temp = 0;
        if(best > temp)
            temp = best;
        if(temp < (s * max(0, k-2) + best))
            temp = s * max(0, k-2) + best;
        
        temp = temp % 1000000007;
        int ans = temp;
        return ans;
    }
};