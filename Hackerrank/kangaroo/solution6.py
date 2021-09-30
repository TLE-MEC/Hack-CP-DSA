""" There are two cases:
case 1: When both kangaroo meets at the same location then we have to say "YES".
case 2: If they are not going to meet in the given distance then "NO".
"""

import math
import os
import random
import re
import sys

""" "kangaroo" function takes 4 parameters i.e.
   1st kangaroo's start location x1 and moves at a rate of v1 meters per jump.
   2nd kangaroo's start location x2 and moves at a rate of v2 meters per jump.
"""
def kangaroo(x1, v1, x2, v2):
    count = 1                              # it is counting the number of jumps.
    while x1 != x2 and count < 10000:      # this while loop runs util both kangaroo meets.
        count += 1                         # incrementing the count variable when both are not meeting.
        x1 = x1 + v1                       # adding 1st kangaroo intial distance and jummps per meter.
        x2 = x2 + v2                       # adding 2st kangaroo intial distance and jummps per meter.
        if x1 == x2:                       # checking whether both kangaroo meeeting or not. If true then return "YES".
            return "YES"

        elif count == 10000:               # if not meeting in the given distance then returns "NO"
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

