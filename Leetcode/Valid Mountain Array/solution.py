def validMountainArray(arr):
    i = 0

    # to check whether values of array are in increasing order
    while i < len(arr) and i+1 < len(arr) and arr[i] < arr[i+1]:
        i += 1

    # i == 0 means there's no increasing sequence
    # i+1 >= len(arr) means the whole array is in increasing order
    if i == 0 or i + 1 >= len(arr):
        return False

    # to check whether values of array are in decreasing order
    while(i < len(arr) and i+1 < len(arr)):
        if arr[i] <= arr[i+1]:
            return False
        i += 1

    return True


print(validMountainArray([0, 3, 2, 1]))
