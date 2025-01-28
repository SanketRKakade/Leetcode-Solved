#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // Use an adjacency list to represent the graph
        vector<vector<int>> adj(V);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        // Compute indegrees of each vertex
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Queue to store vertices with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Decrease indegree of adjacent vertices
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all vertices are visited, return true
        return count == V;
    }
};
