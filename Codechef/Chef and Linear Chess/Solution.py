# take the testcase as input
t = int(input())
for i in range(t):
    # take all the required inputs
    n,k = map(int,input().split())
    p = list(map(int,input().strip().split()))[:n]
    arr = []
    # create a variable with high valuie to store minimum value
    mino = 9999999999
    #Iterate the array using for loop
    for i in range(n):
        #update the minimum id the condition given in the problem i.e 
        # remained when k is divided by the array element must be 0 and
        # when divided must be less than the minimum is satisfied
        if k%p[i] == 0 and k//p[i] < mino:
            mino = p[i]
    #print the answer
    if mino == 9999999999:
        print(-1)
    else:
        print(mino)
        
    