class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        // if there is only one node present, its label will be zero
        // so, put that in vector and return that vector
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        // to create adjacency list, we will use vector of unordered_sets to reduce serch time
        vector<unordered_set<int> >adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        
        // now, we will create the queue to deal with the leaf nodes
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1)q.push(i);
        }
        
        while(n>2){
            // now, size of queue denotes the current number of leaf nodes 
            int s=q.size();
            // we will remove these leaf nodes, thus reduce n by s i.e. n=n-s
            n=n-s;
            while(s--){
                int leaf=q.front();
                q.pop();
                // remove leaf from all its adjacents 
                for(auto x:adj[leaf]){
                    adj[x].erase(leaf);
                    // & if size of adjacents of leaf becoms 1, that means after removal of this leaf,
                    // that node also became leaf,
                    //so, push it to queue, so it will be removed in next iteration
                    if(adj[x].size()==1)q.push(x);
                }
            }
        }
        // finally, push remaining elements to ans vector
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};