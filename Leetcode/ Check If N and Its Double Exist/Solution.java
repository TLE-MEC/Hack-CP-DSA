import java.util.Arrays;
import java.util.Set ;
import java.util.HashSet;
public class Solution {
    public static boolean checkIfExist(int[] arr) {
  //  In the problem ” Check If N and Its Double Exist” we are given an array of n elements. Array length is greater than or equal to two.
  //  Our task is to check if there exists a pair in the array such that the first value is double the second value
  //  More formally we need to check if there exists i,j for which i <n,j<n and arr[i]=2*arr[j].
        Set<Integer> seen = new HashSet<>();   // We can solve this problem in a better time complexity using an unordered map or unordered set
        for (int i : arr) {        // 1.Traverse the array.
            if (seen.contains(2 * i) || (i % 2 == 0 && seen.contains(i / 2))) // 2.For every element in the array check if it’s double or its half already exists it the map.
                return true;
            seen.add(i);
        }
        return false;
    }  // 3.If the condition is true simply return true else add that element into the map.
  


  public static void main(String[] args) {
        int [] arr = {7,1,14,11}; 
        boolean ans=checkIfExist(arr); 
        System.out.println(ans);





  }
}
