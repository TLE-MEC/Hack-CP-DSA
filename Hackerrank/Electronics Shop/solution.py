#!/bin/python3

import os
import sys

#
# Complete the getMoneySpent function below.
#
def getMoneySpent(keyboards, drives, b):
    
    #Find length of array of keyboards and usb drives.
    key_len = len(keyboards)
    dri_len = len(drives)

    total_amount = 0
    #amount_arr to store all the possible values out of keyboards and drives array and storing in the amount_arr to then calc the max value.
    amount_arr = []

    #Total amounts from both the arrays will be added and then the max amount will be calculated using max function.
    for i in range(0, key_len):
        for j in range(0,dri_len):
            total_amount = total_amount + drives[j] + keyboards[i]
            #Checking if toal_amount is less than budget(b).
            if total_amount <= b:
                #Appending all amounts keyboards + USB to total_amount.
                amount_arr.append(total_amount)
                total_amount = 0
            else:
                total_amount = 0
                
    if len(amount_arr) > 0:
        final_price = max(amount_arr)
        #Final Price will be the maximum value from the amount_arr that will be appended above.
        return final_price
    else:
        return -1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    bnm = input().split()

    b = int(bnm[0])

    n = int(bnm[1])

    m = int(bnm[2])

    keyboards = list(map(int, input().rstrip().split()))

    drives = list(map(int, input().rstrip().split()))

    #
    # The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    #

    moneySpent = getMoneySpent(keyboards, drives, b)

    fptr.write(str(moneySpent) + '\n')

    fptr.close()
