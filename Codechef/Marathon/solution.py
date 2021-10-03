for i in range(int(input())):
    D,d,A,B,C=map(int, input().split())
    #given input
    total_km= d*D #num of days*total distance per day
    prize=[] #stores prize for each category

    #condition 1
    if(total_km<10):
        prize.append(0)
    #condition 2
    if(total_km>=10 and total_km<21):
        prize.append(A)
    #condition 3
    if(total_km>=21 and total_km<42):
        prize.append(A)
        prize.append(B)
    #condition 4
    if(total_km>=42):
        prize.append(A)
        prize.append(B)
        prize.append(C)
    
    #output is maximum
    print(max(prize))

        
        
        
