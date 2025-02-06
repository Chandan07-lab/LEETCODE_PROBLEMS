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
TreeNode*solve(vector<int>&pre,vector<int>&ino,int start,int end,int&idx){
    if(start>end){
    return NULL;
    }

    int rootval=pre[idx];
    int found=start;
    
    for(int i=start;i<=end;i++){
        if(rootval==ino[i]){
            found=i;
            break;
        }
    }
    idx++;
    TreeNode* root=new TreeNode(rootval);
    root->left=solve(pre,ino,start,found-1,idx);
    root->right=solve(pre,ino,found+1,end,idx);

return root; 

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);
        
    }
};