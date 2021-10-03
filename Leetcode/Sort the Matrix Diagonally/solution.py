# Each diagnol will have the same value of i - j, where i is the index of row and j is the index of column.
# So we get all the elements in a particular diagnol, sort them and then put them back in their correct places.

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        d = {}
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if (i-j) in d:
                    d[i-j].append(mat[i][j])
                else:
                    d[i-j] = [mat[i][j]]
        for k, v in d.items():
            v.sort()
        x = len(mat)
        y = len(mat[0])
        for i in range(x):
            for j in range(y):
                mat[i][j] = d[i-j].pop(0)
        return mat
