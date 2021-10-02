# cook your dish here
# Total no. of testcases 
T = int(input())
for i in range(1,T+1):
    # taking the required inputs and array
    n,k = map(int,input().split())
    array = list(map(int,input().strip().split()))[:n]
    # calculate the sum of array
    num = sum(array)
    #initialize the variables required to arrive at solution
    c = 0
    ans = 0
    # iterate over the array
    for i in range(n):
        # update the array values on each iteration
        array[i] = array[i]+c
        # if value of array at i index is less than k than update the answer variable
        if array[i] < k:
            ans = i+1
            break
        else:
        # update the c variable according the condition given in the question
            c=array[i] - k 
    #print the answer
    if ans==0:
        ans = num//k + 1
    print(ans)            