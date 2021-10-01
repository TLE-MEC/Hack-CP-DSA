#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def grade_round(num):
    while num % 5 != 0:
        num += 1
    return num 

def gradingStudents(grades):
    final_grades = []
    for i in grades:
        if i < 38:
            final_grades.append(i)
        else:
            if grade_round(i) - i < 3:
                final_grades.append(grade_round(i))
            else:
                final_grades.append(i)

    return final_grades

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
