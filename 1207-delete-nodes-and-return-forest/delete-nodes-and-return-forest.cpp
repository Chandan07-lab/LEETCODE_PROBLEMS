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
TreeNode*dele(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>&re){
    if(root==NULL){
        return NULL;
    }
    root->left=dele(root->left,st,re);
    root->right=dele(root->right,st,re);
if(st.find(root->val)!=st.end()){
    if(root->left!=NULL)
        re.push_back(root->left);
    if(root->right!=NULL)
    re.push_back(root->right);

    return NULL;
}else{
    return root;
}
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;
        unordered_set<int> st;
        for(int &num :to_delete){
            st.insert(num);
        }
        dele(root,st,result);
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};