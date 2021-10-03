"""
Things to know for the solution:
 - The Frog will alway create a triangle. Why?
    - He is limited to T moves before the villager reports.
    - His maximum will always be the sum of X and Y which creates a triangle of slope -1.
 - The triangular number sequence can be used to calculate the points. Why?
    - Count the points and write them (1, 3, 6, 10, 15, ...)
    - You soon notice a pattern: 1+2 = 3, 3+3=6, 6+4=10, ...
    - This sequence is the triangular number sequence n(n+1)/2 where n = the points on a line
 - You could have enough moves to go past the lenght of the square
    - If the frog has 7 moves and the square has a length of six the frog will move beyond the square. 
      Those extra points need to be removed.
 - Excess points are just smaller triangular numbers.
    - After stepping out of the square he will still be limited to his triangle. 
      This facilitates the removal of leftover points.
"""

stdin = input().split()                         # Reading input from STDIN
x = int(stdin[0])
y = int(stdin[1])
s = int(stdin[2])
t = int(stdin[3])

# moves left after going from (0,0) to (X,Y).
moves = t-x-y
# Total number of points he can make after arriving at (X,Y)
points = int(((moves+1)*(moves+2))/2)
# There are 3 options for the frog
# 1. he can't move outside the square making a triangle inside the square
if(moves <= s):
    sol = points
# 2. he can get out and cover the entire square
elif(moves >= 2*s):
    sol = (s+1)**2
# 3. he can get out of it but the triangle does not cover the square
else:
    sol = points - ((moves-s)*(moves-s+1))

print('%s' % sol)                               # Writing output to STDOUT