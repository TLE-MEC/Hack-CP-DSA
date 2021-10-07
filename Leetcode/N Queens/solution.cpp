class Solution {
public:
    
    // This Function checks if it is safe to place a queen in a particular index considering positions of already placed queens


    bool isSafe(int row,int col,vector<string> board,int n){
        int dupRow=row;
        int dupCol=col;
        
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        col=dupCol;
        row=dupRow;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            
        }
        col=dupCol;
        row=dupRow;
        
        while(row<n && col>=0 ){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
            
        }
        return true;
    }

    // This is a helper function used for recursion . If All the columns fill , this adds the board to the main answer vector
    // Otherwise it backtracks
    
    void solver(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solver(col+1,board,ans,n);
                board[row][col]='.';
                
            }
        }
    }
    
    
    
    // Here We Send an a vector of strings with dots which represent empty spaces in the board and then call the helper function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s;
        }
        solver(0,board,ans,n);
        return ans;
    }
};