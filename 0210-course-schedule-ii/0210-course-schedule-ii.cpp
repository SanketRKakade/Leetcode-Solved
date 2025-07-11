class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(N,0);
        for(int i=0 ; i<N ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0 ; i<N ; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        
        if(topo.size()==N) return topo;
        return {};
    }
};