"""We need to create a designer door mat. So we need to find pattern in order to make another door mats. We will divide it into 3 parts i.e. 2 loops and 1 welcome statement.
"""

number,width=map(int, input().split())  # map function to assign variables
whole=1
str=".|."
for i in range(int(number/2)):          # this loop is for the first half
        print(str.center(width,"-"))    # we want our string to be in center and surrounded by "-"
        whole+=2                        # whole will keep count of strings to be added
        str=".|."                       # the number of string ".|." increases by 2 in each step
        str*=whole
print("WELCOME".center(width,"-"))
whole=whole-2                         
str=".|."
str*=whole
for j in range(int(number/2)):         #this is loop for below welcome line
        print(str.center(width,"-"))
        whole-=2
        str=".|."
        str*=whole
