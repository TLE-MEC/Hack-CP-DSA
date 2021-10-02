# Input the length of array
n = int(input())

# Input the array as list
a = [int(x) for x in input().split()]

# List to maintain output
v = []

# As we can only divide by 3, so the number will be arranged in order of highest power of 3 to lowest power of 3. For
# the same power of 3 the condition shift to 2, so the value only can be multiplied so order will be lowest to highest.
for i in a:
    val = i
    count = 0

    # Each element of v will contain first a power of 3 in it and its value multiplied by -1.
    while val % 3 == 0:
        count += 1
        val //= 3
    v.append([count, -1 * i])

# When sorting lowest power of 3 will be in order lowest to highest and value for elements with same power in order 
# most negative to least negative. 

v.sort()
v.reverse()
for i in v:
    # Multiply by -1 to get the original number.
    print(-1 * i[1], end=" ")