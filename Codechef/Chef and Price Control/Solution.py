# Taking Testcases as Input
t = int(input())
for i in range(t):
    # Taking n and k as input
    n,k = map(int,input().split())
    # taking array that is used to find the revenue as input
    p = list(map(int,input().strip().split()))[:n]
    rev = 0
    # for each prices in the array,reduce it by k and increment in the answer
    for i in range(n):
        if p[i]>k:
            rev += p[i]-k
    print (rev) 