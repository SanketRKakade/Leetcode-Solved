// #include <unordered_map>
// #include <vector>
// #include <functional>
// using namespace std;

// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;  // If the node is null, return null
        
        unordered_map<Node*, Node*> copiedNodes;  // Map to store the original node and its clone
        
        // Lambda function for DFS
        function<Node*(Node*)> dfs = [&](Node* n) -> Node* {
            if (copiedNodes.find(n) != copiedNodes.end()) {
                // If the node is already copied, return the clone
                return copiedNodes[n];
            }
            
            // Create a new node and store it in the copiedNodes map
            Node* clone = new Node(n->val);
            copiedNodes[n] = clone;
            
            // Recursively clone the neighbors and add them to the clone's neighbors list
            for (Node* neighbor : n->neighbors) {
                clone->neighbors.push_back(dfs(neighbor));
            }
            
            return clone;
        };
        
        return dfs(node);  // Start the DFS from the given node
    }
};
