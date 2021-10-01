//Naive approach: Find each element using individual for-loop
//for(int i = 0; i < num.length; i++)
//    for(int j = i+1; j < num.length; j++)
//        for(int k = i+2; k < num.length; k++)

//TO have unique triplets we insert them in a set

//TIme complexity: O(n^3logm) (log m b/c of insertion in set)

//Optimized approach:
//Two pointer approach:let i = 0, low pointer points to i+1 and high points to last element of the array is num.length-1
//Sort the given array
//let i = 0, low = i+1, high = num.length-1, sum = -a[i]
//find low and high such that, a[low]+a[high] = sum
//if num[low]+num[high] < sum increase the low pointer by 1 else decrease the high pointer by 1

class Solution {
    public List<List<Integer>> threeSum(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> res = new LinkedList<>();
    for (int i = 0; i < num.length-2; i++) {
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            int lo = i+1, hi = num.length-1, sum = 0 - num[i];
            while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    res.add(Arrays.asList(num[i], num[lo], num[hi]));
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
           }
        }
    }
    return res;
    }
}
