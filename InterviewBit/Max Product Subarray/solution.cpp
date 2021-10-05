/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

Solution approach :-

1) Traverse over every contiguous subarrays.
2) If A[i] < 0 then swap the imax and imin.
3) Then find imax comparing with maximum of A[i] and imax mulitply by A[i].
4) Then also find imin by comparing with minimum of A[i] and imin multiply by A[i],
5) Return the maximum product from these results.

*/

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
      int r = A[0];

            for (int i = 1, imax = r, imin = r; i < n; i++) {
                if (A[i] < 0)
                    swap(imax, imin);

                imax = max(A[i], imax * A[i]);
                imin = min(A[i], imin * A[i]);
                r = max(r, imax);
            }
            return r;
}
