// Binary Search + LinkedList Solution
// Time complexity: O(logN + k)
// Space complexity: O(1) except the output list.
// Constraints: 1) 1 <= k <= arr.length; 2) arr is sorted in ascending order.
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        LinkedList<Integer> res = new LinkedList<>();
        final int N = arr.length;
        int idx = Arrays.binarySearch(arr, x);
        if (idx < 0) idx = -idx - 1;
        int l = idx - 1, r = idx;
        while (res.size() < k) {
            if (l < 0) {
                res.addLast(arr[r++]);
            } else if (r >= N) {
                res.addFirst(arr[l--]);
            } else {
                int diffL = x - arr[l];
                int diffR = arr[r] - x;
                if (diffL <= diffR) {
                    res.addFirst(arr[l--]);
                } else {  // diffL > diffR
                    res.addLast(arr[r++]);
                }
            }
        }
        return res;
    }
}