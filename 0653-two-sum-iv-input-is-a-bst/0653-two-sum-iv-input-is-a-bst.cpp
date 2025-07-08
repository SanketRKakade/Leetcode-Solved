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

class BSTIterator{
    private:
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }

    public:

    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* tmpNode = st.top();
        st.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;

    }
};