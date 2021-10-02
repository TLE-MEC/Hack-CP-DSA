### [658\. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)

Difficulty: **Medium**  

Related Topics: [Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)


Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

*   `|a - x| < |b - x|`, or
*   `|a - x| == |b - x|` and `a < b`

**Example 1:**

```
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

**Example 2:**

```
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
```

**Constraints:**

*   `1 <= k <= arr.length`
*   `1 <= arr.length <= 10<sup>4</sup>`
*   `arr` is sorted in **ascending** order.
*   `-10<sup>4</sup> <= arr[i], x <= 10<sup>4</sup>`


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
    }
};
```