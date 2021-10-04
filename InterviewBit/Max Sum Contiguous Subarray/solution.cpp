/*
Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.

For example:

Input 1:- A = [1, 2, 3, 4, -10]

Output 1:- 10

Explanation 1:- The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:- A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:- 6

Explanation 2:- The subarray [4,-1,2,1] has the maximum possible sum of 6.

Solution approach :-

1) Apply the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this)
2) keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this)
3) Each time we get a positive-sum compare it with max_so_far and update max_so_far if it is greater than max_so_far  

*/

int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < A.size(); i++)
    {
        max_ending_here = max_ending_here + A[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int Solution::maxSubArray(const vector<int> &a) {

//here we are using kadanes algo. 
//The simple idea of Kadane’s algorithm is to look for all positive 
//contiguous segments of the array (max_ending_here is used for this). 
//And keep track of maximum sum contiguous segment among all positive 
//segments (max_so_far is used for this). Each time we get a positive-sum 
//compare it with max_so_far and update max_so_far if it is greater than max_so_far 



int size=a.size();
int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;

}

