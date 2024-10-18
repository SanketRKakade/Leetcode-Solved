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
    int searchInorder(vector<int>inorder,int size,int target){
        for(int i=0 ; i<size ; i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>&preorder,vector<int>& inorder,int &preOrder_index , int inOrder_start,int inOrder_end,int size){
        //base case
        if(preOrder_index>=size || inOrder_start>inOrder_end){
            return NULL;
        }
        //1 case mein solve karunga
        int element = preorder[preOrder_index];
        preOrder_index++;
        TreeNode* root=new TreeNode(element);
        //element search krna padega inorder me
        int position = searchInorder(inorder,size,element);
        //recurssion solve karlega
        root->left = solve(preorder,inorder,preOrder_index , inOrder_start,position-1,size);
        root->right = solve(preorder,inorder,preOrder_index , position+1 ,inOrder_end,size);
        return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preOrder_index=0;
        int inOrder_start=0;
        int inOrder_end = size-1;
        TreeNode* ans = solve(preorder,inorder,preOrder_index , inOrder_start,inOrder_end,size);
        return ans;
    }
};