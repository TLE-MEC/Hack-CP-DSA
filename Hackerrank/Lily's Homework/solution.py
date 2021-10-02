def solution(arr, n):
    m = {}  # hashmap
    # mapping the array numbers to respective indices
    for i in range(n):
        m[arr[i]] = i

    #sorted array copy
    sorted_arr = sorted(arr)
    res = 0

    # Iterate through input list, and compare current value(say cv) against value from sorted list (say scv).
    # If it is different then increment number of swaps and
    # get index of the scv from map - map[scv]
    # in input list swap cv with scv

    for i in range(n):
        if arr[i] != sorted_arr[i]:
            res += 1

            ind_to_swap = m[sorted_arr[i]]
            m[arr[i]] = m[sorted_arr[i]]
            arr[i], arr[ind_to_swap] = sorted_arr[i], arr[i]

    return res


n = int(input())
a = list(map(int, input().split(' ')))

# reversed input list - the smaller return value is the final result
asc = solution(list(a), n)
desc = solution(list(reversed(a)), n)
print(min(asc, desc))
