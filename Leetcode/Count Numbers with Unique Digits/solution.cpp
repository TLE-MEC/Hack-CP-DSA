/** Approach: We can calculate by recursively calculation for n and n-1 **/


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      if(n == 0)
          return 1;
        int counter = 9, x = 9;
        for(int i = 1; i < n; i++){
            counter *= x;
            x--;
        }
        return counter+countNumbersWithUniqueDigits(n-1);
    }
};