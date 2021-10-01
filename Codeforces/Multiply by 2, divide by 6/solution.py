def findDiv(n, count):
    #If parameter n is negative, print -1 - indicating impossibility and return from the function
    if n < 0:
        print(-1)
        return; 
    
    #If n == 1, return from the function execution, printing the count value
    if n == 1:
        print(count)
        return;
    
    #If n is divisible by 6, divide the number by 6, and increment the counter
    if n%6 == 0:
        findDiv(n/6, count+1)
    
    #If n is divid=sible by 3, divide the number by 6 and multiply by 2, and increment the counter 
    elif n%3 == 0:
        findDiv(n*2/6, count+2)
        
    #If neither of the above conditions satisfies, recursively call the function, with negative input parameter
    else:
        findDiv(-1, count)
        
#Input the number of testcases
number = int(input())

for i in range(number):
    
    #initialize count with 0
    count = 0
    
    #Get the input
    n = int(input())
    
    #If number is 1, print 0 and ignore the rest of the loop
    if n == 1:
        print(0)
        continue
    
    #Call the function to find the count/impossibility
    findDiv(n, count)
    
