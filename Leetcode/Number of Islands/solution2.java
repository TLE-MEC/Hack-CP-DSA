class Solution {
    // we have find number of island means number of non connected components.
   

    public int numIslands(char[][] arr) {
        int cnt = 0;  // this will be our final ans

        // dir array will help to travel in all 4 directions
        int[][] dir = new int[][]{{0,1},{1,0},{-1,0},{0,-1}};
        
        //  we will iterate on the grid and find the index having value 1.
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                if(arr[i][j]=='1'){
                    cnt++;  // as we got on index having value 1, this mean it is a island so increament count by one.
                    dfs(arr,i,j,dir); // mark all 1, connected to this 1 to 0 as they will be part of this island only. will use DFS to mark them 0.
                }
            }
        }
        
        return cnt;
    }


    public void dfs(char[][] arr, int i, int j, int[][] dir){
        arr[i][j] = '0'; // put value 0f the current index as 0;
        
        // iterate in every direction and check if it is a valid index and have value as 1, then marks as 0 and call the same function for that index.
        for(int[] d : dir){
            int x = i+d[0];
            int y = j+d[1];
            if(x>=0 && y>=0 && x<arr.length && y<arr[0].length && arr[x][y] == '1')
            dfs(arr,x,y,dir);
        }
    }
    
}