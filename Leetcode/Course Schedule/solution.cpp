
/*
    Intuition:-
    
    - We have to construct a Directed Graph with node 'u' directed to 'v'
    such that, in each pair of (u,v), 'u' will denote the prerequisite courses to be done to reach 'v'

    - Here, we have to detect in our contructed Graph, if there is a deadlock present will prevent
    us from doing all the courses.
    We can check that by detecting a Cycle in our Graph,
        If cycle present -> return FALSE ie all courses can't be finished
        else             -> return TRUE ie courses can be finished

    Cycle Detection (using DFS) Logic:-
    - Using recursion, we'll find out if in the path we are currently pursuing has a visited node or not
    - We'll use two arrays vis[] and dfsVis[] which marks the visted nodes and current path nodes respectively
    - We'll update the values of vis[] from 0 to 1 everytime we visit the node
    - We'll update the values of dfsVis[] from 0 to 1 everytime we visit a node in our path
                                      and from 1 ro 0 everytime we backtrack from our path
    - If a node is not visited ie vis[node] = 0, we recursivly call DFS for it again
    - If a node is visited but not from our path ie vis[node] = 1 && dfsVis[node] = 0,  we return FALSE
      If a node is visited but it's from our path ie vis[node] = 1 && dfsVis[node] = 1, we detect a cycle and return TRUE 

*/

class Solution {
public:
    
    // using DFS to detect a cycle
    bool cyclePresent(int node, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[])
    {
        // We mark our current node as visited
        vis[node] = 1;
        
        // We mark our current node is our current path as visited
        dfsVis[node] = 1;

        for(int it : adj[node])
        {
            if(!vis[it])    // unvisited node
            {
                if(cyclePresent(it, vis, dfsVis, adj))
                    return true;
            }
            else if(dfsVis[it]) // visited node and also visited node in our path
                return true;
        }
        
        // We update our mark to unvisited as we are backtracking from our path
        dfsVis[node] = 0;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // We'll represent our Graph in the from of an Adjacency List named 'adj'
        vector<int> adj[numCourses];

        // We'll check for each course (v) and it's pre-requisite course (u)
        // Such that u -> v ie, to reach course v, we need to complete u
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            adj[u].emplace_back(v);
        }
        
        // we make two arrays vis[] and dfsVis[]
        // vis[] will track if a node is visited
        // dfsVis[] will track if a node is visted in our current path
        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        for(int i=0; i<numCourses; i++)
            if(cyclePresent(i, vis, dfsVis, adj))   // Cycle Detection using DFS
                return false;
        return true;
    }
    
};