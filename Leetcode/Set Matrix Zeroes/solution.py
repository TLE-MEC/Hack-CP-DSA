class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        ## number of rows
        m = len(matrix)
        ## number of columns
        n = len(matrix[0])
        ## total number of elements
        num_ele = m * n
        
        ## list to store locations of zeros
        list_of_zeros = []

        ## finding the positions of zeros in the matrix
        for i in range(num_ele):
            x = int(i // n)
            y = int(i % n)
            if matrix[x][y] == 0:
                list_of_zeros.append((x, y))
                
        ## for every zero position, set elements in that row and column to 0
        for i, j in list_of_zeros:
            ## set elements in that column to 0
            for x in range(n):
                matrix[i][x] = 0
                
            ## set elements in that column to 0
            for y in range(m):
                matrix[y][j] = 0
