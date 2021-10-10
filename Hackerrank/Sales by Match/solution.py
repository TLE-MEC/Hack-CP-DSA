# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY ar

def sockMerchant(n, ar):
    # Write your code here
    # variable to store the pair
    a = 0
    # Dictionary to store the count
    dic = {i: ar.count(i) for i in ar}
    for v in dic.values():
        a = a + v // 2

    return a


n = int(input().strip())

ar = list(map(int, input().rstrip().split()))

result = sockMerchant(n, ar)
print(result)
