class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int r1 = mat.size();    //number of rows in the given matrix
        int c1 = mat[0].size(); //number of columns in the given matrix
        if (r * c != r1 * c1)
            return mat; //returning the given matrix if every element does not fit in the new matrix
        vector<vector<int>> res(r, vector<int>(c));
        int i, j, n1 = 0, n2 = 0;
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                res[n1][n2] = mat[i][j];
                n2++;        //inserting elements row-wise
                if (n2 == c) //checking if the first row is insertion complete
                {
                    n2 = 0;
                    n1++; //moving to the next row
                }
            }
        }
        return res;
    }
};