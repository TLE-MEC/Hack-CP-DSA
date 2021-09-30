#!/bin/python3
import os
"""Logic Used for solving the problem is in this function"""
"""
   The function takes four inputs.The first condition where both the velocities are same, it will not meet again.
   The second condition is where we equate x1 + v1*t = x2 + v2*t.  as the time should be greater then 0, the resulting condition is (x1-x2)/(v2-v1) > 0
"""
def kangaroo(x1, v1, x2, v2):
    if v1==v2:
        return "NO"
    if (x1-x2)/(v2-v1)>0:
        var=float(x1-x2)/float(v2-v1)
        if var - int(var) ==0:
            return "YES"
        else:
            return "NO"
    else:
        return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    x1V1X2V2 = input().split()

    x1 = int(x1V1X2V2[0])

    v1 = int(x1V1X2V2[1])

    x2 = int(x1V1X2V2[2])

    v2 = int(x1V1X2V2[3])

    result = kangaroo(x1, v1, x2, v2)

    fptr.write(result + '\n')

    fptr.close()
