
//Steps
//1: find all primes in the range sqrt(R)
//2: create a dummy array of size R-L+1
//3: mark all non-primes in the dummy array as 0 with referenve to the primes array that we created in step 1
//4: for that we need to find the first multiple and begin from fm or i*i which ever is bigger

class Solution{
public:
    vector<int> sieve(int n)
    {
        vector<int> isprime(n+1,1);
        for(int i=2;i<=n;i++)
        {
            if(isprime[i]==1)
            {
                for(int j = i*i;j<=n;j+=i)
                {
                    isprime[j] = 0;
                }
            }
        }
        vector<int> prime;
        for(int i=2;i<=n;i++)
        {
            if(isprime[i]==1)
            {
                prime.push_back(i);
            }
        }
        return prime;
    }
    long long primeProduct(long long L, long long R){
        vector<int> primes;
        primes = sieve(sqrt(R));
        long long s = R - L +1;
        vector<int> segs(s,1);
        for(auto i:primes)
        {
            int fm = (L/i)*i;
            if(fm<L) fm+=i;
            for(long long j = max(fm, i*i);j<=R;j+=i)
            {
                segs[j-L] = 0;
            }
            
        }
        //the question was to find the product of primes
        long long pro = 1;
        for(long long i=L;i<=R;i++)
        {
            if(segs[i-L]==1)
                pro = (pro*i)%1000000007;
        }
        return pro%1000000007;
    }
};
