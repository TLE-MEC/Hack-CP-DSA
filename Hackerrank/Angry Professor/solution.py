import math
import os
import random
import re
import sys

# Complete the angryProfessor function below.
def angryProfessor(k, a):
    c=0                              #initializing the count with 0
    for i in a:
        if i<=0:
            c+=1                     #checking for the students those are on time
    if k<=c:                         #checking if the number of minimum students recquired to be on time is less than equal to the students actually are on time
        return "NO"
    return "YES"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())                #input the number of test casses

    for t_itr in range(t):
        nk = input().split()        

        n = int(nk[0])

        k = int(nk[1])

        a = list(map(int, input().rstrip().split()))        #splitting the line input of students in a list

        result = angryProfessor(k, a)

        fptr.write(result + '\n')

    fptr.close()