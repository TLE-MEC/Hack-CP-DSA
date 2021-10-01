#!/bin/python3

import os
import sys

#
# Complete the pageCount function below.
#
def pageCount(n, p):
    #
    # Write your code here.
    #
    pages = []
    count = 0
    #For turing from page 1.
    loop_run_one = 0
    #For turning from page n.
    loop_run_two = 0

    #For storing count from page 1 and page n and then finding the min value from this array.
    count_turns = []

    #Appending the page numbers.
    for i in range(0, n + 1):
        pages.append(i)



    #checking if total number of pages is odd.
    if len(pages) % 2 != 0: 
        #checking if page to turn is odd.
        if p % 2 != 0:
            p = p - 1

        #Checking and counting the page turns from page 1.
        for j in range(0, len(pages), 2):

            loop_run_one = loop_run_one + 1
            #if pages array equals the page number then turns should be turns - 1. Suppose if we go to page 2 from page 1. Then the loop count will be 2 but we had only one turn so -1.
            if j == p:
                loop_run_one = loop_run_one - 1
                count_turns.append(loop_run_one)
                break

        #Reversing the pages to start counting from page n.
        pages.reverse()
        
        for k in range(0, len(pages), 2):
            loop_run_two = loop_run_two + 1
            #if pages array equals the page number then turns should be turns - 1. Suppose if we go to page 2 from page 1. Then the loop count will be 2 but we had only one turn so -1.
            if pages[k] == p:
                loop_run_two = loop_run_two - 1
                count_turns.append(loop_run_two)
                break

    else:
        #Checking when page n is even.
        if p % 2 != 0:
            p = p - 1

        for j in range(0, len(pages), 2):

            loop_run_one = loop_run_one + 1

            if j == p:
                loop_run_one = loop_run_one - 1
                count_turns.append(loop_run_one)
                break

        pages.reverse()
        

        p = p + 1
        for k in range(0, len(pages), 2):
            loop_run_two = loop_run_two + 1
            if pages[k] == p:
                loop_run_two = loop_run_two - 1
                count_turns.append(loop_run_two)
                break
        

    if len(count_turns) > 1:
        #Checking for min turns required from the count_turns from back and front.
        turns = min(count_turns)

    else:

        turns = 0

    return turns
    

print(pageCount(6,2))

