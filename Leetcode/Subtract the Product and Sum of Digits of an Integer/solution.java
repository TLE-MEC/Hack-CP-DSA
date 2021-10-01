// package Hack-CP-DSA.Leetcode.Subtract the Product and Sum of Digits of an Integer;

public class Solution {
  public int subtractProductAndSum(int n) {
      int product = 1;
      int sum = 0;
      while(n > 0) {
          int temp = n % 10;
          n /= 10;
          product *= temp;
          sum += temp;
      }
      return product - sum;
  }
}
