// Applying dfs to solve this problem

// dfs_helper funcion 
bool dfs_helper(int node,vector<int>* adj, int parent, vector<bool> &vis){
        // marking the vertex visited
        vis[node]=true;

        // for every node connected to the current node using an edge do following
        for(auto it: adj[node]){

            // if same as parent ignore
            if(it==parent){
                continue;
            }

            // as node is already visited we detect a cycle here
            // and return true
            if(vis[it]==true){
                return true;
            } 

            // as node is not visited again calling the dfs_helper function
            if(dfs_helper(it,adj,node,vis)==true){
                return true;
            }
        }

        // as for current node all connectedd nodes doesn't contains any cycle 
        // returning false
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {

        // Creating vector for marking the visited node
        vector<bool> vis(V,false);

        // As graph may be disconnected check every unvisited noted 
        for(int i=0;i<V;i++){
            if(vis[i]==false){

                // as dfs_helper return true it contains cycle
                // return true;
	           if(dfs_helper(i,adj,-1,vis)==true){
	                return true;
	            }
            }
        }

        // No cycle found in the graph returnig false
        return false;
    }