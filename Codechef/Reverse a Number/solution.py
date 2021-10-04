while(True):
    try:
        t=int(input())
        for x in range(t):
            reversedno=0
            n=int(input())
            
            while n>0:
                remainder=n%10
                reversedno=reversedno*10+remainder
                n=n//10
            print(reversedno)
    except:
        break

# Need to print the provided number in reversed order.
# --> Ask for input of 't'
# --> Initiate a 'for' loop to get constant input of 'n' and set 'reversedno' to 0
# --> Initiate a 'while' loop

# First Iteration:
# --> Remainder = Number%0 (If Number = 543) --> Remainder = 543%10 = 3
# --> Reverse = Reverse*10 + Remainder --> 0 * 10 + 3 = 3
# --> Number = 543//10 = 54

# Second Iteration:
# --> Remainder = Number%0 (Now, Number = 54) --> Remainder = 54%10 = 4
# --> Reverse = Reverse*10 + Remainder --> 3 * 10 + 4 = 30 + 4 = 34
# --> Number = 54//10 = 5


# Third Iteration:
# --> Remainder = Number%0 (Now, Number = 5) --> Remainder = 5%10 = 5
# --> Reverse = Reverse*10 + Remainder --> 34 * 10 + 5 = 340 + 5 = 345
# --> Number = 5//10 = 0

# Since 'n' = 0, fourth iteration is cancelled, come out of 'while' loop
# print(reversedno) --> print(345) --> 345
