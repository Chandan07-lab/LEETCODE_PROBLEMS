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
vector<int>re;
void dfs(TreeNode*root,int depth){
    if(!root){
        return ;
    }
    if(depth==re.size()){
        re.push_back(root->val);
    }else{
        re[depth]=max(re[depth],root->val);
    }
    dfs(root->left,depth+1);
    dfs(root->right,depth+1);

}

    vector<int> largestValues(TreeNode* root) {
        // if(!root){
        //     return {};
        // }
        // queue<TreeNode*>que;
        // que.push(root);
        // vector<int>re;
        // while(!que.empty()){
        //     int n=que.size();
        //     int maxel=INT_MIN;
        //     while(n--){
        //         TreeNode* node=que.front();
        //         que.pop();
        //         maxel=max(node->val,maxel);
        //         if(node->left){
        //             que.push(node->left);
        //         }

        //         if(node->right){
        //             que.push(node->right);
        //         }
        //     }
        //     re.push_back(maxel);
        // }
        // return re;
        dfs(root,0);
        return re;

    }
};