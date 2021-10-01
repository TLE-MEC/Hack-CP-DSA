#!/bin/python3

import math
import os
import random
import re
import sys

def grade_round(num):
    while num % 5 != 0:  # checks until the number has reached it's neareast boundaries
        num += 1
    return num # returns neareast round value

def gradingStudents(grades):
    final_grades = []
    for i in grades:
        if i < 38:               # checking base case for pass and fail
            final_grades.append(i)
        else:
            if grade_round(i) - i < 3:   # checking whether the increment is less than 3
                final_grades.append(grade_round(i)) # if it is less than 3 , then append the round value to final grades
            else:
                final_grades.append(i) # if it is greater than 3 , then appends the actual value to final grades

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
