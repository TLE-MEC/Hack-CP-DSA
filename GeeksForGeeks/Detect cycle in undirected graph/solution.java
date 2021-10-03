class Solution {
    // Function to detect cycle in an undirected graph.
    public boolean dfs(boolean []visited,int curr,int parent,ArrayList<ArrayList<Integer>> adj){
        if(visited[curr]) return true; //if node is visited then cycle
        
        visited[curr]=true;
        ArrayList<Integer> neighbours=adj.get(curr);
        for(int i=0;i<neighbours.size();i++){
            if(!visited[neighbours.get(i)]){
                if(dfs(visited,neighbours.get(i),curr,adj)) return true;
            }
            else if(parent!=neighbours.get(i)){
                return true; // if parent is not part of child's neighbours then cycle exists
            }
        }
        return false;
    }
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean []visited=new boolean[V]; //track visited nodes
        for(int i=0;i<V;i++){
            if(!visited[i]){
                boolean flag=dfs(visited,i,-1,adj); //DFS method to detect cycle
                if(flag) return true;
            }
        }
        return false;
    }
}