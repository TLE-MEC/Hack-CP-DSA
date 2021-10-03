# taking point input for alice and bob
alice = list(map(int, input().split()))
bob = list(map(int, input().split()))
aliceScore = 0
bobScore = 0

# comparing the points
for i in range(3):
    if alice[i] > bob[i]:
        aliceScore += 1
    elif alice[i] < bob[i]:
        bobScore += 1
print(aliceScore, bobScore)


''' for example Test case
input - 17 28 30
        99 16 8
output - 2 1
'''
