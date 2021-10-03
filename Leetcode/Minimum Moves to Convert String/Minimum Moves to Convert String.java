class Solution {
    public int minimumMoves(String s) {
        char ch[]=s.toCharArray();
        int n=ch.length;
        int count=0;
        int i=0;
        while(i<n)
        {
            if(ch[i]=='X')
            {
                count++;
                i+=2;
            }
            i++;
        }
        return count;
    }
}
