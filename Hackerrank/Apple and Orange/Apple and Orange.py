#!/bin/python3

import math
import os
import random
import re
import sys

# The function accepts following parameters:
#  1. INTEGER s = start point
#  2. INTEGER t = End point
#  3. INTEGER a = location of apple tree
#  4. INTEGER b = location of orange tree
#  5. INTEGER_ARRAY apples
#  6. INTEGER_ARRAY oranges

def bwt(s,t,a,arr):
    array = []
    btw = 0
    for i in arr:
        array.append(a+i) # appending the relative locations to array with respective global origin
    for i in array:
        if i >= s and i <= t :
            btw += 1  # checks wheather the item is there or not
    return btw
    
def countApplesAndOranges(s, t, a, b, apples, oranges):
    print(bwt(s,t,a,apples))   # return No.of apples in between trees
    print(bwt(s,t,b,oranges))  # return No.of oranges in between trees

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    s = int(first_multiple_input[0])

    t = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    a = int(second_multiple_input[0])

    b = int(second_multiple_input[1])

    third_multiple_input = input().rstrip().split()

    m = int(third_multiple_input[0])

    n = int(third_multiple_input[1])

    apples = list(map(int, input().rstrip().split()))

    oranges = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apples, oranges)
