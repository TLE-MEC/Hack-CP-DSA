/*
The grid can be viewed as a graph. Every adjacent element to an element at position [i,j] can be viewed as adjacent nodes.
Since the word can be in any direction (i.e up, down, left, right), a depth first solution can be used. 
In every depth first search, the current element can be compared to the offset in the given string.

For example:

matrix:
A B C E
S F C S
A D E E

target: ABCCED

output: true

The depth first search should only continue till the current element is same as the offset in the given string. 
*/



class Solution {
public:
    
    bool explore(vector<vector<char>>& board, string word, int i, int j, int k){
        if(k == word.size()) // the last character match has been found
            return true;
        int rows = board.size();
        int cols = board[0].size();
        if(i<0 || j<0 || i == rows || j == cols) // condition to check that the position is still inside the grid
            return false;
        if(board[i][j] == word[k])// k is the offset which changes on each step in a depth first search
        {
            char temp = board[i][j]; // creating a copy of the current element
            board[i][j] = '*'; // marking this element as visited so that the flow does not return to this in the depth first search
            
            bool res =  explore(board, word, i+1,j,k+1) | // explore down
                        explore(board, word, i-1,j,k+1) | // explore up
                        explore(board, word, i,j+1,k+1) | // explore right
                        explore(board, word, i,j-1,k+1); // explore left
            board[i][j] = temp;// after one complete search this element needs to be unmarked
            return res;
            
            
        }
        return false; // k reaches the end of the string => word not found

        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int s = word.size();
        int rows = board.size();
        int cols = board[0].size();
        if(s > rows*cols) // impossible case to be true
            return false;
        
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0; j<cols; j++)
                // traversing on element at [i,j]
                if(board[i][j] == word[0]) // if the first character is matched, do a dfs
                {
                    if(explore(board, word ,i ,j ,0)) 
                        return true;
                }
        }
        return false;
    }
};