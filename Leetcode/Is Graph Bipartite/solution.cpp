// A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. 

// Approach: Color all the nodes of the graph using 2 colors such that no two adjacent node are of same color then, the graph is bipartite graph.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph,int src,vector<int>&vis){
            queue<int>que;
            que.push(src);   // Push the source in the queue
            
            int Color = 0;
            
            // Apply Breadth First Search (BFS) 
            while(que.size()!=0){ 
                int size = que.size();
                while(size-- >0){
                    int rvtx = que.front();
                    que.pop();
                    // Check whether the popped node has been assigned any color before or not?
                    if(vis[rvtx]!=-1){
                        // If yes, check whether it has the same color as its adjacent node or not.
                        if(vis[rvtx] != Color){
                            // Return false if the adjacent node is colored with the same node color and not with the current value of Color.
                            return false;
                        }
                        continue;
                    }
                    vis[rvtx]=Color;  // Color the node with current value of Color to maintain the alternate coloring strategy.
                    // Find all non-colored adjacent nodes
                    for(int v : graph[rvtx]){
                        if(vis[v]==-1){
                            que.push(v);
                        }
                    }
                }
                Color = (Color + 1)%2; // Color the nodes with 2 colors alternately.
            }
            return true;
        }

        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            // Create a vector to store the colors which will be assigned to all the nodes.
            vector<int>vis(n,-1); // Initially, All the nodes are uncolored which is shown by assigning -1 as the default value.
            bool res = true;
            // Check for all the nodes
            for(int i=0;i<n;i++){
                if(vis[i]==-1){
                    res = res && isBipartite(graph,i,vis);
                }
            }
            return res;
        }
    };