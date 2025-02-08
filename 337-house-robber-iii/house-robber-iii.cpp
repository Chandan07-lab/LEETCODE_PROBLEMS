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
pair<int,int>solve(TreeNode * root){
    if(!root){
        return {0,0};
    }

    auto l=solve(root->left);
    auto r=solve(root->right);

    pair<int,int>result;

    result.first=root->val+l.second+r.second;

    result.second=max(l.first,l.second)+max(r.first,r.second);

return result;

}

    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }

        pair<int,int>result=solve(root);

        return max(result.first,result.second);
    }
};