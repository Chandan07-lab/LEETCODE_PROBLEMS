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
TreeNode*solve(vector<int>&ino,vector<int>&post,int start,int end,int&idx){
    if(start>end){
        return NULL;
    }

    int rootval=post[idx];
    int i=start;

    for(;i<=end;i++){
        if(ino[i]==rootval) break;
    }
    idx--;
    TreeNode* root=new TreeNode(rootval);
    root->right=solve(ino,post,i+1,end,idx);
    root->left=solve(ino,post,start,i-1,idx);

return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;
        return solve(inorder,postorder,0,n-1,idx);
        
    }
};