class Solution {
private:
    vector<int> inorderVals;
    int index;

    // Step 1: Store the inorder traversal
    void storeInorder(TreeNode* root) {
        if (!root) return;
        storeInorder(root->left);
        inorderVals.push_back(root->val);
        storeInorder(root->right);
    }

    // Step 3: Modify the tree with sorted values
    void recoverTreeUtil(TreeNode* root) {
        if (!root) return;
        recoverTreeUtil(root->left);
        if (root->val != inorderVals[index]) {
            root->val = inorderVals[index];
        }
        index++;
        recoverTreeUtil(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        if (!root) return;

        // Step 1: Store inorder traversal
        inorderVals.clear();
        storeInorder(root);

        // Step 2: Sort the values
        sort(inorderVals.begin(), inorderVals.end());

        // Step 3: Replace values using sorted inorder
        index = 0;
        recoverTreeUtil(root);
    }
};

