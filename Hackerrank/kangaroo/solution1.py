#


# working
# the trick to this problem is understanding where both kangaroos will coincide

# case1: if either one of the kangaroo has start position and jump distance greater than the other one
#         both kangaroos can never meet

# case2: both kangaroos can only meet if (x2-x1) % (v2-v1) is equal to 0

def findPos(x1, v1, x2, v2):
    if (x1 < x2 and v1 <= v2) or (abs(x2 - x1) % abs(v2 - v1) != 0):
        print("NO")
    else:
        print("YES")


# working
# this method uses brute force to find the jumped position of both kangaroos
# jumped position can be calculated using (x1 + v1) over n iterations
# here number of iteration limit is taken as 10000

# if at any point both kangaroos have the same position problem is solved
def findPosBruteForce(x1, v1, x2, v2):
    for n in range(10000):
        if (x1 + v1) == (x2 + v2):
            print("YES")
        x1 += v1
        x2 += v2
    print("NO")


if __name__ == "__main__":
    t = int(input())
    X1, V1, X2, V2 = input().strip().split()
    print(findPos(int(X1), int(V2), int(X2), int(V2)))
