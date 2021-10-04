//This can be solved using DFS.

int dfs(int x,int y, vector<vector<int>>&grid, vector<vector<bool>>&visited)
{// If a point is out of bounds or if is already visited then we return 0;
        if(x<0 || y<0 || x>=grid.size()|| y>=grid[0].size() || visited[x][y] == true || grid[x][y] == 0){
              return 0;
           }
        else
          {
          // Else we make the point visited and then search if its neighbours are 0 or 1 if they are 1 then the size of island is increased, else it is made 0;
              v[x][y] = true;
            // we do DFS here
               int    top = dfs(x-1,y,grid,visited);
               int    left = dfs(x,y-1,grid,visited);
               int    right = dfs(x,y+1,grid,visited);
               int   down = dfs(x+1,y,grid,visited);
               return (1+(left+right+down+top));
        }
      }
      
 int maxAreaOfIsland(vector<vector<int>>& grid) {       
        int ans = 0;        
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));        
        int n = grid.size();
        int m = grid[0].size()
        for(int i=0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    ans = max(ans,dfs(i,j,grid,visited));
                }
            }
        return ans;
 }
    // The time complexity of this algorithm is O(n^2)
    // Space complexity is (O(n^2)) 