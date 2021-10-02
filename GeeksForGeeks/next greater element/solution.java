
class Solution
{
    //Function to find the next greater element for each element of the array.
    public static long[] nextLargerElement(long[] arr, int n)
    { 
        // Your code here
       long nge[]=new long[n];
       Stack<Long> st=new Stack<Long>();
       st.push(arr[n-1]);
       for(int i=n-1;i>=0;i--)
       {
        while(!st.empty() && st.peek()<=arr[i])
        {
            st.pop();
        }
        nge[i]=st.empty()?-1:st.peek();
        st.push(arr[i]);
       }
       return nge;
    } 
}
