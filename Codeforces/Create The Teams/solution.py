# Iterate over t time for test cases
for _ in range(int(input())):
    
    # Input n and x
    n, x = [int(x) for x in input().split()]
    
    # Input the array into list
    a = [int(x) for x in input().split()]
    
    # Sort the list
    a.sort()
    
    # Conter to manage number of teams formed
    val = 0
    
    # Current stack of team members
    v = []
    
    while len(a) > 0:
        
        # Adding one member to stack and if the current stack able to form a team then increment val
        v.append(a.pop())
        if v[-1] * len(v) >= x:
            v = []
            val += 1
            
    print(val)