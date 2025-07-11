class Solution {

private:
    bool bfs(int start, int color[], vector<vector<int>>& graph){
        queue<int>q;
        q.push(start);
        color[start]=0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:graph[node]){
                //if the adj node is not coloured
                // give the colour opposite to that of node
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // if the adjacent node has same color as that of node
                // some other node coloured it before 
                // and the graph is not a bipartite graph
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i=0 ; i<n ; i++) color[i] = -1;
        for(int i=0 ; i<n ; i++){
            if(color[i]==-1){
                if(bfs(i,color,graph)==false) return false;;
            }
        }
        return true;
    }
};