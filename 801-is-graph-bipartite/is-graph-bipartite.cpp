class Solution {
public:

    bool dfs(int curr,vector<int>& color,vector<vector<int>>& graph){
        if(color[curr]==-1)color[curr]=1;
        for(auto ne:graph[curr]){
            if(color[ne]==-1){
                color[ne] = 1 - color[curr];
                if(!dfs(ne, color, graph)) return false;
            }else if(color[ne]==color[curr]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        int n = graph.size();
        for(int i=0;i<n;++i){
            if(color[i]==-1){
                if(!dfs(i, color, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};