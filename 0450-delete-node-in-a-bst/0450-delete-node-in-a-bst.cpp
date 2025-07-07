class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node to be deleted found
            if (!root->left && !root->right) {
                // Case 1: No child
                delete root;
                return nullptr;
            } else if (!root->left) {
                // Case 2: One child (right)
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                // Case 2: One child (left)
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 3: Two children
                TreeNode* minNode = getMin(root->right);  // Find in-order successor
                root->val = minNode->val;                 // Replace value
                root->right = deleteNode(root->right, minNode->val);  // Delete successor
            }
        }

        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
