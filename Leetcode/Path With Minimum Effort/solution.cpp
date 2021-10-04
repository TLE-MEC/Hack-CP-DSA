//Greedy will not work
//If all edges would have been on equal weight we could have considered BFS
/*
Probable Solution:
> Greedy solution will fail definitely.
> We should go via shortest path algorithm:
    > 3 Alsgos are present:
        > Dijikstra-> Shortest path from one to all other, doen't work in case of negative edges.
        >Bellmann Ford-> Shortest path from one node to all other also works in case of negative edges
        > Floyd Warshall -> Gives shortest path between each pair of vertices.

Finally applying Dijikstra's Algorithm

*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        multiset<pair<int,pair<int,int>>> mset;
        vector<vector<bool>> visited(heights.size(),vector<bool>(heights[0].size(),false));
        
        mset.insert({0,{0,0}});
        int x[4]={0,1,0,-1};
        int y[4]={1,0,-1,0};
        while(!mset.empty()){
            pair<int,pair<int,int>> p=*mset.begin();
            mset.erase(mset.begin());
          
            if(p.second.first==heights.size()-1&&p.second.second==heights[0].size()-1){
                return p.first;
            }
            if(visited[p.second.first][p.second.second])
                continue;
                
            visited[p.second.first][p.second.second]=true;
            
            for(int i=0;i<4;i++){
                int newX=p.second.first+x[i];
                int newY=p.second.second+y[i];
                if(newX>=0&&newX<heights.size()&&newY>=0&&newY<heights[0].size()){
                    if(!visited[newX][newY]){
                        int eff1 = max(p.first,abs(heights[newX][newY]-heights[p.second.first][p.second.second]));
                        mset.insert({eff1,{newX,newY}});
                    }
                }
            }
            
        }
        return -1;
        
    }
};