class Solution {
    public int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        
        // Even children are right childs
        // 0's right child is 1
        // 1's right child is 0
        if(k % 2 == 0) return (kthGrammar(n-1, k / 2) == 0) ? 1 : 0;
        
        
        // Odd children are left childs
        // 0's left child is 0
        // 1's left child is 1
        return (kthGrammar(n-1, (k + 1) / 2) == 0) ? 0 : 1;
    }
}
