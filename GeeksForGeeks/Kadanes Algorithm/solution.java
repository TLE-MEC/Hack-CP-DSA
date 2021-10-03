class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    
    int maxSubarraySum(int arr[], int n){
        
        //initializing the max value with minimum int value
        int max= Integer.MIN_VALUE;
        int positiveSum= 0;
        
        //checking and updating the max and positiveSum values
        for(int i=0; i<n; i++) {
            positiveSum+= arr[i];
            max= max<positiveSum ? positiveSum : max;
            positiveSum= positiveSum<0 ? 0 : positiveSum;
        }
        
        return max;
    }
}
