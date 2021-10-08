/*
    Intuition:-
    - We'll be using BFS to check adjacent nodes from our current node
    - Using two colors ie. 1 and 0 we'll color the graph such that all 
    adjacent nodes are opposite colored.
    - When checking for adjacents we have two options
        1. Adjacent already colored ( 0 or 1 )
            If a Adjacent is already colored, we have to check if it color
            is opposite to our current nodes color
                if opposite -> carry on
                if same -> return false, as the graph can't be bipartite
        2. Adjacent not colored( -1 )
            color the adjacent in the opposite color of current node
            and carry on the BFS
*/

class Solution {
public:

    bool checkBipartite(int source, vector<int> adj[], vector<int> &color)
    {
        // queue is used for BFS
        queue<int> q;

        // marking source node with color 0
        q.emplace(source);
        color[source] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int it : adj[node])
            {
                if(color[it] == -1) // adj not visited, color opposite and continue BFS
                {
                    q.emplace(it);
                    color[it] = 1 - color[node];
                }
                else if(color[it] == color[node])   // adj visited and same color as current node, return false
                    return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    
        // start node is 0
	    int startNode = 0;

        // vis will mark is node is visited as well as color of the node
	    vector<int> vis(V, -1);     // -1 = not visited | 0 = visited, 0 colored | 1 = visited, 1 colored 
	    
        for(int i=0; i<V; i++)  // for multiple components
	        if(vis[i] == -1)
	            if(!checkBipartite(i, adj, vis))
	                return false;
	    
        return true;
	}

};