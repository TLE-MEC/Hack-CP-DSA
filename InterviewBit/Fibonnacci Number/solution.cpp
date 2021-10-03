class Solution {
    static vector<vector<int>> matrix_multiplication(vector<vector<int>> F,vector<vector<int>> M)
    {
        int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
        int b= F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
        int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
        F[0][0] = a;
        F[0][1] = b;
        F[1][0] = c;
        F[1][1] = d;
        return F;
        //multiplies the matrix
    }
    static vector<vector<int>> pow(vector<vector<int>>m,int n)
    {
        //finds the power of the fibonacci number
        vector<vector<int>> h = {{1,1},{1,1}};
        int x = 0;
        while(n)
        {
            int i = n&1;
            x++;
            n = n>>1;
            if(i==1)
            {
                h = matrix_multiplication(m,h);
            }
            m = matrix_multiplication(m,m);
        }
        return h;
    }
    public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==2 || n==1) 
        {
            return 1;
        }
        vector<vector<int>> m={{1,1},{1,0}};
        //every fibonacci number is a sum of exponents of this matrix
        //and we can find that exponents by using bits
        m = pow(m,n-2);
        int d;
        d = m[0][0];
        return d;     
    }
};