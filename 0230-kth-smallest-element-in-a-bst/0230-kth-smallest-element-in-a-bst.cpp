/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int solve(TreeNode* root, int k, int& count){

        if (!root) return -1;

        // Search in the left subtree
        int left = solve(root->left, k, count);
        if (left != -1) return left;

        // Visit current node
        count++;
        if (count == k) return root->val;

        // Search in the right subtree
        return solve(root->right, k, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        return solve(root,k,count);
    }
};