// package Hack-CP-DSA.Leetcode.Subtract the Product and Sum of Digits of an Integer;

public class Solution {
  public int subtractProductAndSum(int n) {
      int product = 1;
      int sum = 0;
      while(n > 0) {    // loop till input>0
          int temp = n % 10;    // module for getting remainder
          n /= 10;              // divide to get quotent
          product *= temp;      // to get product of remainder
          sum += temp;          // to get sum of quotent
      }
      return product - sum;      // to return subtraction of product & sum.
  }
}
