'''Approach: Difference between strings both minimal and maximal. Minimum difference will be there if characters in both strings are not equal and not question mark ie denoted by x
 and Maximum difference will be there if strings match at positions and not equal to question mark '''



# cook your code here
l = []
n = int(raw_input())
for i in range(n):
    f = raw_input()
    s = raw_input()
    l.append([f,s])
for i in l:
    x , y = 0 , len(i[0])
    for j in range(y):
        if(i[0][j] == i[1][j]) and i[0][j] != '?':
            y -= 1 
        if (i[0][j] != i[1][j]) and (i[0][j] != '?' and i[1][j] != '?'):
            x += 1 
    print(str(x) + ' ' + str(y))
