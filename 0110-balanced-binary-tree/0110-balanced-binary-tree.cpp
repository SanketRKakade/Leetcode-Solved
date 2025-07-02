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

    int dfsHeight(TreeNode* root){
        if(root == NULL) return true;

        int lh = dfsHeight(root->left);
        int rh = dfsHeight(root->right);

        return max(lh,rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int lh = dfsHeight(root->left);
        int rh = dfsHeight(root->right);

        if(abs(lh-rh) > 1) return false;

        bool leftCheck = isBalanced(root->left);
        bool rightCheck = isBalanced(root->right);

        if(!leftCheck || !rightCheck) return false;
        return true;
    }
};