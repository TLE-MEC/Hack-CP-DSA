# Each twin wants to keep costly gifts for himself
# so we sort the array of costs for gifts
# EVEN numb of gifts = twin keeps 1 in last turn
# ODD numb of gidts = twin keeps 2 in last turn 



t =int(input()) # t - test cases

while t!=0:
       t-=1
       n,k = list(map(int , input().split())) #n - numb of gifts , k - turns
       arr = list(map(int , input().split()))
       ans = 0
       arr.sort(reverse = True) #sorts cost in descending order
       
       for i in range(0 , 2*k-1 , 2): #twin uses 2k turns
              ans += arr[i]
       
       res=0
       for j in range(1 , 2*k , 2): #twin uses 2k-1 turns
              res += arr[j]
       
       res += arr[2*k] #because he can pick up 2 in last turn
       
       print(max(res , ans)) #prints answer
