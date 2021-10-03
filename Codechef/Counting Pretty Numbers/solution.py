'''Approach:  Count numbers which have last digit as 2,3 or 9 which can be found by num % 10 unit digit'''



# cook your code here
t = int(input())
while(t):
    l,r = map(int,raw_input().split())
    l_d = 0
    c = 0 
    for i in range(l,r+1):
        l_d = i % 10 
        if(l_d == 2 or l_d == 3 or l_d == 9):
            c += 1 
    print(c)
    t -= 1
        
