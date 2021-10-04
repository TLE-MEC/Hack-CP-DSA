# Function to calculate the mask of a number.
def split(n):
    b = []
    # Iterating the number by digits.
    while n > 0:
        # If the digit is lucky digit it is appended to the list.
        if n % 10 == 4 or n % 10 == 7:
            b.append(n % 10)
        n //= 10
    # Return the mask.
    return b


# Input the two input values.
x, y = [int(x) for x in input().split()]
# Calculate the mask of 'y'.
a = split(y)
# Iterate for value greater than 'x'.
for i in range(x + 1, 1000000):
    # If mask equals output the integer and break the loop.
    if split(i) == a:
        print(i)
        break