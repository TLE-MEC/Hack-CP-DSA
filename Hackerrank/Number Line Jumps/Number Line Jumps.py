#!/bin/python3

import math
import os
import random
import re
import sys

# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER x1 = position of kangaroo-1
#  2. INTEGER v1 = speed of kangaroo-1
#  3. INTEGER x2 = position of kangaroo-2
#  4. INTEGER v2 = speed of kangaroo-2

def kangaroo(x1, v1, x2, v2):
    if v1 != v2:                                    # Base case for kangaroo 1 & 2 ( if v1 == v2 both can't meet at any position)
        value = (x2-x1)/(v1-v2)                     # calculating time for meeting, if time is +ve they meet at a position, if -ve they never meet
        if (value - int(value)) == 0 and v1 > v2:   # checks whether time is a integer or not and from base case v1 should > v2
            return 'YES'                            
        else:
            return 'NO'                             # returns 'YES' if meet, 'NO' if not meet
    else:
        return 'NO'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    x1 = int(first_multiple_input[0])

    v1 = int(first_multiple_input[1])

    x2 = int(first_multiple_input[2])

    v2 = int(first_multiple_input[3])

    result = kangaroo(x1, v1, x2, v2)

    fptr.write(result + '\n')

    fptr.close()
