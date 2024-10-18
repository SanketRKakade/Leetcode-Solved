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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);
        int ans = max(left_height,right_height)+1;
        return ans;

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        //currNode - solve
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool currNodeAns = (diff<=1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(currNodeAns && rightAns && leftAns ){
            return true;
        }
        else{
            return false;
        }
    }
};