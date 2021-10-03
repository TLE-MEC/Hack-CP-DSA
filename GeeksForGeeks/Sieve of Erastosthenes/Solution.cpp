vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> prime(N+1,1);
        //create a vector to store all numbers upto n (n+1 because vectors are zero indexed)
        vector<int>ans;
        for(int i=2;i<=N;i++)
        {
            if(prime[i]==1) //check if the current number is prime
            {
                for(int j = 2*i;j<=N;j+=i)
                {
                    prime[j]=0;//make all multiples of the current num to 0
                }
                ans.push_back(i); //insert that number
            }
        }
        return ans;
    }