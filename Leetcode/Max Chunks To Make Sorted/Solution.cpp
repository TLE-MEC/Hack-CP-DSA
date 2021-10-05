/* Problem Statement: You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.

Approach: 
-> Traverse array from left to right, keep on adding array elements and index.
-> At every iteration just check if array_sum is equal to index sum then increment the chunk count.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
     
        // Storing size of array
        int n = arr.size();

        // Declaring necessary variables
        int array_sum = 0, index_sum = 0;
        int count_chunk = 0;
        
        for(int i = 0; i < n; i++)
        {
            array_sum = array_sum + arr[i]; // Adding array elements
            index_sum = index_sum + i; // Adding indexes
            
            if(index_sum == array_sum)  // If they match, increment the chunk count
                count_chunk++;
        }
        
        // Returning the result
        return count_chunk;
    }
};