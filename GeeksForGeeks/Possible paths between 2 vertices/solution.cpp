
/*  Intuition:-

    - As, we are simply finding a path to a specified node, we can mofidy DFS
    such that instead of visiting only the unvisited node in a DFS Recursive Branch,
    it'll visit all nodes in that branch (ie. visited and univisited)

    - In each branch, there are two options
            1. Destination Node present ->  if present simply ++ count as we found a path
                                            and we don't have to furthur check that branch
            2. Destination Node absent  ->  backtrack to check in some other branch

    - We can count the total number of paths and return it
*/

class Solution {
  public:
  
    void recurse(int node, int &dest, int &count, vector<int> &vis, vector<int> adj[])
    {
        // we reached our destination node in out branch
        if(node == dest)
        {
            count++;
            return;
        }
        
        // marking current branch
        vis[node] = 1;
        
        for(int it : adj[node])
        {
            if(!vis[it])    // node not visited in our branch
                recurse(it, dest, count, vis, adj);
        }
        
        // unmarking current branch
        vis[node] = 0;
    }
  
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        
        vector<int> vis(V,0);
        
        int count = 0;  // to store number of paths
        recurse(source, destination, count, vis, adj);
        return count;
        
    }
};