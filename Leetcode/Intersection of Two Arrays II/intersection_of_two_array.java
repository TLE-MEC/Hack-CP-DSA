// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
class Solution {

  public int[] intersect(int[] nums1, int[] nums2) {
    int m = nums1.length, n = nums2.length;
    Arrays.sort(nums1); //sorting the arrays
    Arrays.sort(nums2);
    List<Integer> res = new ArrayList<Integer>(); //arraylist to store the result

    int p = 0, q = 0;
    while (true) {
      if (p == m || q == n) break; //reached end of the array

      if (nums1[p] < nums2[q]) p++; // if the elements in the 1st array is smaller than element in 2nd array p++
      else if (nums1[p] > nums2[q]) q++; // if the elements in the 2nd array is smaller than element in 1st array q++
      else {
        res.add(nums1[p]);
        p++;
        q++;
      }
      //else add into the list
    }

    //return the array as the intersection of two arrays
    int[] resa = new int[res.size()];
    for (int i = 0; i < resa.length; i++) resa[i] = res.get(i);

    return resa;
  }
}
