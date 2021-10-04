import math

# Input number of test cases.
t = int(input())

for _ in range(t):
    # Input integer value.
    n = int(input())

    # Iterate until the GCD Sum became greater than 1.
    while True:
        s = 0
        val = n
        # Loop to calculate the sum of digits. It removes last digit in one iteration.
        while val > 0:
            s += val % 10
            val = val // 10

        # Use gcd function. If condition is satisfied output the number and break the loop.
        if math.gcd(n, s) > 1:
            print(n)
            break
        n += 1