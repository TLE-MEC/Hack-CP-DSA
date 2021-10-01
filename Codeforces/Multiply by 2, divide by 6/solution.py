def findDiv(n, count):
    if n < 0:
        print(-1)
        return; 
    
    if n == 1:
        print(count)
        return;
    
    if n%6 == 0:
        findDiv(n/6, count+1)
    
    elif n%3 == 0:
        findDiv(n*2/6, count+2)
    else:
        findDiv(-1, count)

number = int(input())

for i in range(number):
    count = 0
    n = int(input())
    
    if n == 1:
        print(0)
        continue
    
    findDiv(n, count)
    
