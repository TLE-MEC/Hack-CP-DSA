class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        List<Integer> res = new ArrayList<Integer>();
        
         if (matrix.length == 0) {
            return res;
        }
        
        // Setting boundaries
        int left = 0;
        int right = matrix[0].length-1;
        int top = 0;
        int bottom = matrix.length-1;
        
        while(left<=right && top<=bottom){
            //Get every i in the topmost row
            for(int i=left; i<=right; i++){
                res.add(matrix[top][i]);   
            }
            top++;
            
            //Get every i in the rightmost column
            for(int i=top; i<=bottom; i++){
                res.add(matrix[i][right]);
            }
            right--;
            
            //Get every i in the bottom row
            for(int i= right; top<=bottom && i>=left; i--){
                res.add(matrix[bottom][i]);
            }
            bottom--;
            
            //Get every i in the right column
            for(int i= bottom; left<=right && i>=top; i--){
                res.add(matrix[i][left]);
            }
            left++; 
        }
        return res;  
    }
}
