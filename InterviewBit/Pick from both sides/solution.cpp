int Solution::solve(vector<int> &a, int b) {
    long i,j,k,l,c=0,sum=0,left,right,temp;
    for(i=0;i<b;i++)
    {
        sum=sum+a[i]; // calculating the sum till first b elements
    }
    
    temp=sum;
    l=a.size();
    left=b-1;
    right=l-1;
    while(left>=0)
    {
        temp=temp-a[left]+a[right];  //excluding the elements from the first b elements and adding elements from the last one by one
        if(temp>sum)                 
        sum=temp;                    // storing the value of temp in sum if temp is greater than the current value of sum
        left--;
        right--;
    }
    return sum;
}
