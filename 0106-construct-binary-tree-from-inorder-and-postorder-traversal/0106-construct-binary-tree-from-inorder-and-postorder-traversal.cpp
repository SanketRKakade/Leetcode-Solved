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
    void createMapping(vector<int>& inorder , int size , map<int,int>&valueToIndexMap) {
        for(int i=0;i<size;i++){
            int element = inorder[i];
            int index = i;
            valueToIndexMap[element]=index;
        }
    }

    TreeNode* solve(map<int,int>&valueToIndexMap,vector<int>&postorder,vector<int>& inorder,int &postorderIndex , int inorderStart,int inorderEnd,int size){
        //base case
        if(postorderIndex<0 || inorderStart > inorderEnd){
            return NULL;

        }

        //1 case mein
        int element = postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root = new TreeNode(element);
        //search karo inorder me
        int position = valueToIndexMap[element];
        //recursion sambhal lega
        //pehle right wala part ala hein N se in LRN
        root->right = solve(valueToIndexMap,postorder,inorder,postorderIndex , position+1,inorderEnd,size);

        root->left = solve(valueToIndexMap,postorder,inorder,postorderIndex , inorderStart , position-1 , size);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        int postorderIndex = size-1;
        int inorderStart = 0;
        int inorderEnd = size-1;
        map<int,int>valueToIndexMap;
        createMapping(inorder,size,valueToIndexMap);
        TreeNode* ans = solve(valueToIndexMap,postorder,inorder,postorderIndex , inorderStart,inorderEnd,size);
        return ans;
    }
};