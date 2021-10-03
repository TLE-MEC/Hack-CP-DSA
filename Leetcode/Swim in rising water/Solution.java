class Solution {

    // Using BFS algorithm

    public int swimInWater(int[][] grid) {

        // dx, dy to traverse in four directions
        int[] dx = new int[]{1,-1,0,0};
        int[] dy = new int[]{0,0,1,-1};

        int ans = 0;
        int n = grid.length;
        boolean[][] vis = new boolean[n][n];
        
        // Defining PriorityQueue with int[] array including -> rowIndex, colIndex, gridValue
        // Priority is defined on the basis of gridValue
        // smallest gridValue has highest priority

        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[2]-b[2]);
        pq.add(new int[]{0,0,grid[0][0]});
        
        while(!pq.isEmpty()) {
            int[] u = pq.poll();

            // Updating ans
            ans = Math.max(ans,u[2]);
            if(u[0]==n-1 && u[1]==n-1) {
                return ans;    
            }

            // Checking in the adjacent four directions
            for(int i=0;i<4;++i) {
                int x = u[0] + dx[i];
                int y = u[1] + dy[i];
                if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]) {
                    pq.add(new int[]{x,y,grid[x][y]});
                    vis[x][y] = true;
                }
            }
        }
        
        return 0;
    }
}
