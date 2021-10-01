"""According to the question we need to maintain count of likes and dislikes such that from a set of numbers(Second line of input) if a particluar number exist in set A(Third line of input) then the happiness count will be 1, if it exist in (Forth line of input)B the happiness count will be -1 and if neither of the sets then the happiness count will remain unchanged. 

Here the First line of input dictates the number of entries in the COMPARING set(from which we will compare) and A and B (they both wil have same length).To keep the count of happiness we have created a variable count intialised to 0.
"""

x, y = map(int, input().split())                         # x is length of storage and y is length of A, B
storage = list()
count = 0

storage = list(map(int, input().strip().split()))        # map function converts all string input values into int

A = set(map(int, input().strip().split()))
B = set(map(int, input().strip().split()))

for i in storage:
    if i in A:                                            # if A then increment in count value
        count = count+1                            
    if i in B:                                            # if B then decrement in count value
        count = count-1

print(count)
