public class solution {
    public int movesToChessboard(int[][] board) {
        int l = board.length, moveCol = 0, moveRow = 0, rowOneCnt = 0, colOneCnt = 0;
        //Check if the board can be transformed or not
        /*
        If the board can be transformed to a chessboard, for any two rows in the board, the cells between them must be either all the same, 
         or all inverted, if some items are inverted and some items are the same, they can't form a chessboard by swapping.
        */ 
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                 // Since XOR operator is associative and commutative, we don't have to verify columns again
                if (((board[0][0] ^ board[i][0]) ^ (board[i][j] ^ board[0][j])) == 1) {
                    return -1;
                }
            }
        }
        /*
         We will just check the first row and col now because
         We have checked that board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) == 0 for all i and j.
         So if we well arrange the first row and the first col, all board will be well set up.
        */
        for (int i = 0; i < l; i++) {
            rowOneCnt += board[0][i];
            colOneCnt += board[i][0];
            if (board[i][0] == i % 2) {
                moveRow++;
            }
            if (board[0][i] == i % 2) {
                moveCol++;
            }
        }
        //if l is even, rowOneCnt and colOneCnt should be l / 2
        //if l is odd, rowOneCnt = l / 2, colOneCnt = l / 2 + 1 or rowOneCnt = l / 2 + 1, colOneCnt = l / 2
        if (rowOneCnt < l / 2 || rowOneCnt > (l + 1) / 2) {
            return -1;
        }
        if (colOneCnt < l / 2 || colOneCnt > (l + 1) / 2) {
            return -1;
        }
         /*
            we can change either moveCol or l - moveCol, similarly, either moveRow or l - moveRow
            if l is even, choose the smaller one
            if l is odd, we must choose the even one between ToMove or l - ToMove
            */
        if (l % 2 == 1) {
            
            if (moveCol % 2 == 1) {
                moveCol = l - moveCol;
            }
            if (moveRow % 2 == 1) {
                moveRow = l - moveRow;
            }
        } else {
           
            moveCol = Math.min(moveCol, l - moveCol);
            moveRow = Math.min(moveRow, l - moveRow);
        }
        //(moveCol + moveRow) / 2 will be the number of swaps in total for each swap will move either two columns or two rows
        return (moveCol + moveRow) / 2;
    }    
}
