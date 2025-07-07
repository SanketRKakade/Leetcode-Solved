// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (!root) return nullptr;

//         if (key < root->val) {
//             root->left = deleteNode(root->left, key);
//         } else if (key > root->val) {
//             root->right = deleteNode(root->right, key);
//         } else {
//             // Node to be deleted found
//             if (!root->left && !root->right) {
//                 // Case 1: No child
//                 delete root;
//                 return nullptr;
//             } else if (!root->left) {
//                 // Case 2: One child (right)
//                 TreeNode* temp = root->right;
//                 delete root;
//                 return temp;
//             } else if (!root->right) {
//                 // Case 2: One child (left)
//                 TreeNode* temp = root->left;
//                 delete root;
//                 return temp;
//             } else {
//                 // Case 3: Two children
//                 TreeNode* minNode = getMin(root->right);  // Find in-order successor
//                 root->val = minNode->val;                 // Replace value
//                 root->right = deleteNode(root->right, minNode->val);  // Delete successor
//             }
//         }

//         return root;
//     }

// private:
//     TreeNode* getMin(TreeNode* node) {
//         while (node->left) {
//             node = node->left;
//         }
//         return node;
//     }
// };


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }

private:
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }
};
