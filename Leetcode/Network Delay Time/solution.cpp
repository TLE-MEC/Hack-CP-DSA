//Shortest path algo will work, if a vertex is not reachable then its time would be inf
//Dijikstra's -> O(ElogV), E -> number fo edges, V -> number of vertices in the graph
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> delay(n+1,INT_MAX);
        delay[k]=0;
        vector<bool> visited(n+1,false);
        multiset<pair<int,int>> mset;
        mset.insert({0,k});
        while(!mset.empty()){
            pair<int,int> p = *mset.begin();
            mset.erase(mset.begin());
            if(visited[p.second])
                continue;
            visited[p.second]=true;
            for(int i=0;i<graph[p.second].size();i++){
                if(delay[p.second]!=INT_MAX&&!visited[graph[p.second][i].first]&&delay[graph[p.second][i].first]>graph[p.second][i].second+delay[p.second]){
                    delay[graph[p.second][i].first]=graph[p.second][i].second+delay[p.second];
                    mset.insert({delay[graph[p.second][i].first],graph[p.second][i].first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<delay.size();i++)
            ans=max(delay[i],ans);
        return ans==INT_MAX?-1:ans;
    }
};