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
    vector<int> postorderTraversal(TreeNode* root) {
                stack<TreeNode*>st;
        vector<int>preorder;
        if(!root){
            return preorder;
        }
        st.push(root);
        while(!st.empty()){
            root=st.top();
            preorder.push_back(root->val);
            st.pop();
            if(root->left!=NULL){
                st.push(root->left);
            }
            if(root->right!=NULL){
                st.push(root->right);
            }

            
        }
        reverse(preorder.begin(),preorder.end());
      return preorder;
        
        
    }
};