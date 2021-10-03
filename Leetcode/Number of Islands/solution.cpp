class Solution {
public:
    
    
    void dfs(int i , int j, vector<vector<char>> &arr, vector<vector<int>> &vis){   //function for DFS
        
        vis[i][j]=1;    // mark island as visited
        
        int dx[]={0,0,1,-1};    // array for changing values of x
        int dy[]={-1,1,0,0};    // array for changing values of y
        
        for(int k=0;k<4;k++){
            if(i+dx[k]<arr.size() && i+dx[k]>=0 && j+dy[k]<arr[0].size() && j+dy[k]>=0 && arr[i+dx[k]][j+dy[k]]=='1' && vis[i+dx[k]][j+dy[k]]==0){  // if index (i+dx,j+dy) is in bounds of the grid, value at that index is 1 and index is not visited, mark it as visited and then perform DFS on it
                vis[i+dx[k]][j+dy[k]]=1;
                dfs(i+dx[k],j+dy[k],arr,vis);
            }
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size()==0){
            return 0;   //if grid is empty return 0
        }
        if(grid[0].size()==0){
            return 0;   //if grid is empty return 0
        }
        int count=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0)); //create an empty grid for denoting which indices have been visited
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,grid,vis);          // perform DFS on every cell that is 1 and not visited and increase the count of islands
                    count++;
                }
            }
        }
        return count;
        
    }
};  