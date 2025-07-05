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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                // Go to the rightmost node of the left subtree
                while (prev->right) {
                    prev = prev->right;
                }
                // Attach curr's right subtree to the rightmost node of left subtree
                prev->right = curr->right;
                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node (always to the right in the flattened tree)
            curr = curr->right;
        }

    }
};