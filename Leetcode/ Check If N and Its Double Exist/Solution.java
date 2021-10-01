import java.util.Arrays;
import java.util.Set ;
import java.util.HashSet;
public class Solution {
    public static boolean checkIfExist(int[] arr) {
        Set<Integer> seen = new HashSet<>();   
        for (int i : arr) {
            if (seen.contains(2 * i) || (i % 2 == 0 && seen.contains(i / 2)))
                return true;
            seen.add(i);
        }
        return false;
    }
  public static void main(String[] args) {
        int [] arr = {7,1,14,11}; 
        boolean ans=checkIfExist(arr); 
        System.out.println(ans);
//    In the problem ” Check If N and Its Double Exist” we are given an array of n elements. Array length is greater than or equal to two.
//    Our task is to check if there exists a pair in the array such that the first value is double the second value.
//    More formally we need to check if there exists i,j for which i <n,j<n and arr[i]=2*arr[j].


//  We can solve this problem in a better time complexity using an unordered map or unordered set
//  1.Traverse the array.
//  2.For every element in the array check if it’s double or its half already exists it the map.
//  3.If the condition is true simply return true else add that element into the map.
// 4.If array traversal is done and we didn’t find double of any element, then return false.
  }
}