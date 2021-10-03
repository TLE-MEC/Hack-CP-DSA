import java.io.*;
import java.util.List;
public class Solution {
    public static void main(String[] args) {
        
    }
    public static void bonAppetit(List<Integer> bill, int k, int b) {
        int actualBill = 0;
        for (int i = 0; i < bill.size(); i++) {
            if (!(i == k)) {
                actualBill += bill.get(i);
            }
        }
        actualBill = actualBill / 2;
        if (b == actualBill) {
            System.out.println("Bon Appetit");
        } else {
            System.out.print(b - actualBill);
        }
    }
}
