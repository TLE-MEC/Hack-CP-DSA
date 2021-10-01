for _ in range(int(input())):
    N,A,B = map(int, input().split())
    s=input()
    time=0
    for i in s:
        if(i=="1"):
            time+=B
        if(i=="0"):
            time+=A
    print(time)      