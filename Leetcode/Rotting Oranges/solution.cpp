// Here, we are given a n*m matrix with either 0, 1 or 2 stored in the cells which denote the following:
//     0 => empty cell
//     1 => fresh orange
//     2 => rotten orange 

// Given that, every minute all the fresh oranges 4-direnctionally adjacent to a rotten orange become rotten, 
// we need to find out the time taken for all oranges to become rotten or return -1 if it is not possible.

// This problem can be solved optimally by using the multi source bfs on the matrix where the initially rotten oranges act as source 
// and the distance of fresh oranges from the source is the time taken for them to rot.

// We create a dist matrix to store the distance. Initially, each cell is initialised INT_MAX.
// We store the empty cells and the rotten oranges distance as 0.

// We use a queue of pair<int, int> to store coordinates of oranges as they rot in the bfs.

// If in the end any cell still has dist = INT_MAX after completion of bfs, it means that it does not rot.

// Hence, we take the maximum distance stored in the dist matrix. If it is INT_MAX, we return -1 else return the max distance.

// TIME COMPLEXITY: O(n*m)
// SPACE COMPLEXITY: O(n*m)     , where n = number of rows and m = number of columns

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>  grid){
    int n = grid.size();
    int m = grid[0].size();

    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
    int ans=0;
    queue<pair<int, int> > q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==0 || grid[i][j]==2){
                dist[i][j]=0;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
    }

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        for(int i=0; i<4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];

            if(xx<n && xx>-1 && yy<m && yy>-1 && grid[xx][yy]==1 && dist[xx][yy]==INT_MAX){
                dist[xx][yy]=dist[x][y]+1;
                q.push({xx, yy});
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // cout<<dist[i][j]<<" ";
            ans=max(dist[i][j], ans);
        }
        // cout<<"\n";
    }
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    vector<vector<int> > v ={{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(v);
    return 0;
}