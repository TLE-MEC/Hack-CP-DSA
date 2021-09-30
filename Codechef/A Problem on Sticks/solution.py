t = int(input())    #Taking input of number of testcases
for i in range(t):
    n = int(input())    #Taking Input of number of stick holders
    li = list(map(int, input().split()))    #Taking Input the Initial height of the stick in each stickholder
    li.sort()
    #If the number of sticks holder is 1 then we assign c = 1
    if n==1:
        c = n   
    #If the number of stick holder is not equal to 0 then we assign the length of list after removing duplicate elements into c    
    else:
        c = len(set(li)) 
    #If the first element of list after sorting is 0 then we subtract the 1 from the c because if the initial height of any stick is 0 then birbal doesn't need move to cut the stick   
    if li[0] == 0:
        c-=1        
    print(c)
        