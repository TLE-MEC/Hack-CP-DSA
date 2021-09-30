# Logic:
# The required result is simply the solution of the equations
# x1 + y*v1 = x2 + y*v2 (where y is the number of jumps)
# which is same as checking if (x1-x2)%(v2-v1)==0


def kangaroo(x1, v1, x2, v2):
    return "YES" if (v1 > v2) and not (x2 - x1) % (v2 - v1) else "NO"


if __name__ == '__main__':

    # input
    x1V1X2V2 = input().split()

    x1 = int(x1V1X2V2[0])

    v1 = int(x1V1X2V2[1])

    x2 = int(x1V1X2V2[2])

    v2 = int(x1V1X2V2[3])

    result = kangaroo(x1, v1, x2, v2)

    print(result)
