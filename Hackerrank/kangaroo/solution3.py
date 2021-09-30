'''
LOGIC:
    First, we compare the first kangaroo's location with the second one.
        if same then they will meet at the starting point.
    Second, if first kangaroo's location and rate bothe are heigher or visa-verse 
        then there is no chance of them meeting at same place.
    Else if their location are different and theit rates are same
        thene there is no chance of them meeting at same place.
'''

x1,v1,x2,v2 = map(int,input().split())
a = 0
while True:
    k = x1 + a*v1 
    m = x2 + a*v2
    if k==m:
        print("YES")
        break
    elif k>m and v1>v2:
        print("NO")
        break
    elif k<m and v2>v1:
        print("NO")
        break
    elif k>m or k<m and v1==v2:
        print("NO")
        break
    a=a+1