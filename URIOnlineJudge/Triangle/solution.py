def solution():
    # taking asked inputs
    A, B, C = map(float, input().split())

    #check triangle inequality conditions
    if (A + B) > C and (A + C) > B and (B + C) > A:
        perimeter = (A + B + C)
        print(f"Perimetro = {perimeter:0.1f}")
    else:
        area = 0.5 * (A + B) * C
        print(f"Area = {area:0.1f}")


if __name__ == '__main__':
    solution()