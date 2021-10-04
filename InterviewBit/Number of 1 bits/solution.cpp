int Solution::numSetBits(unsigned int A) {
    int rem,count = 0;
    while(A)
    {
        A= A&(A-1); //this finds the next 1 position
        count++;
    }
    return count;
}