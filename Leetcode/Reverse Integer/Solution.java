class Solution {
    public int reverse(int x) {
        //variable to store the final reversed integer
        long rev = 0;
        //we will keep taking mod of the input until we reach zero
        while (x != 0) {
            //finding remainder
            int d = x % 10;
            //multiplying by 10 and adding the remainder back to rev
            rev = rev * 10 + d;
            //stripping off the unit digit
            x = x / 10;
        }
        //checking if our answer is within range
        if (rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE)
            return 0;
        else
            return (int) rev;
    }
}