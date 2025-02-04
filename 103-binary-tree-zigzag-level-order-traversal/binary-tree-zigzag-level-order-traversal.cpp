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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>val;
        queue<TreeNode*>q;
        if(root==NULL){
            return val;
        }
         q.push(root);

         bool ltr=true;

         while(!q.empty()){
            int n=q.size();

            vector<int>vec(n);
            int i=0;
            while(i<n){
                TreeNode* node=q.front();
                q.pop();
                int index=ltr? i:(n-1-i);
                vec[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                i++;
            }
            ltr=!ltr;
            val.push_back(vec);

         }

         return val;
    }
};