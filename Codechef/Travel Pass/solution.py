for _ in range(int(input())):
    N,A,B = map(int, input().split()) 
    # N => length of string
    # A => Inter-district time
    # B => Inter-state time
    s=input()
    time=0
    
    #for every element in s
    for i in s:
        #if i is 1 then inter-state time added
        if(i=="1"):
            time+=B
        #if i is 0 then inter-district time added 
        if(i=="0"):
            time+=A
    #output
    print(time)      
