n = int(input())
arr = []
l_sum = 0
r_sum = 0

# For getting the user input
for i in range(n):
    arr.append(list(map(int, input().split())))

# For the sum
for i in range(n):
    for j in range(n):
        # To find the sum of left diagonal
        if i == j:
            l_sum = l_sum + arr[i][j]

        # To find the sum of right diagonal
        if i + j == (n - 1):
            r_sum = r_sum + arr[i][j]

result = abs(l_sum - r_sum)

print(result)
