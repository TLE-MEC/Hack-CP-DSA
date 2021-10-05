#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    
    #Sorting the input array.
    arr.sort()


    #Variables for storing the count of each bird types.
    count_type_one = 0
    count_type_two = 0
    count_type_three = 0
    count_type_four = 0
    count_type_five = 0

    #calculationg the length of the sorted array
    aLen = len(arr)


    arr_count = []


    if 5 <= aLen <= 2*math.pow(10,5):

        for i in range(0,aLen):

            #Storing count for type 1 bird.
            if arr[i] == 1:
                count_type_one = count_type_one+1

            #Storing count for type 2 bird.
            elif arr[i] == 2:
                count_type_two = count_type_two+1

            #Storing count for type 3 bird.
            elif arr[i] == 3:
                count_type_three = count_type_three+1

            #Storing count for type 4 bird.
            elif arr[i] == 4:
                count_type_four = count_type_four+1

            #Storing count for type 5 bird.
            elif arr[i] == 5:
                count_type_five = count_type_five+1

        #Appending the count of the number of times the birds appeared in the arr_count array.
        arr_count.append(count_type_one)
        arr_count.append(count_type_two)
        arr_count.append(count_type_three)
        arr_count.append(count_type_four)
        arr_count.append(count_type_five)


        #Finding the max count from arr_count array for number of appearances.
        maxMigrate = max(arr_count)        


        #Returing the bird type from the array count.
        birdType = 0 
        for i in range(0,len(arr_count)):

            if arr_count[i] == maxMigrate and i == 0:

                birdType = 1
                break
            if arr_count[i] == maxMigrate and i == 1:

                birdType = 2
                break
            if arr_count[i] == maxMigrate and i == 2:
                birdType = 3
                break
            if arr_count[i] == maxMigrate and i == 3:
                birdType = 4
                break
            if arr_count[i] == maxMigrate and i == 4:
                birdType = 5
                break

        return birdType


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
