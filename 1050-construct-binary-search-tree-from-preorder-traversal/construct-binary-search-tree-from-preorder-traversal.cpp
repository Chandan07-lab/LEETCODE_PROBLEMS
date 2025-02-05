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
TreeNode*solve(vector<int>&a,int& i,int bound){
    if(i==a.size()||a[i]>bound) return NULL;

    TreeNode* n=new TreeNode(a[i++]);
    n->left=solve(a,i,n->val);
    n->right=solve(a,i,bound);

    return n;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int bound=INT_MAX;
        return solve(preorder,i,bound);
        
    }
};