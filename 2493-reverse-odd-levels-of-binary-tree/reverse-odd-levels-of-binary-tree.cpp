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
void solve(TreeNode*l,TreeNode*r,int level){
    if(l==NULL||r==NULL){
        return;
    }
    if(level%2==1){
        int temp=l->val;
        l->val=r->val;
        r->val=temp;
    }
    solve(l->left,r->right,level+1);
    solve(l->right,r->left,level+1);
}
    TreeNode* reverseOddLevels(TreeNode* root) {
    //     queue<TreeNode*>que;
    //     que.push(root);
    //     int level=0;
    //     while(!que.empty()){
    //         int n=que.size();
    //         vector<TreeNode*>levnode;
    //         while(n--){
    //             TreeNode*temp= que.front();
    //             que.pop();
    //             levnode.push_back(temp);

    //             if(temp->left){
    //                 que.push(temp->left);
    //             }        
    //             if(temp->right){
    //                 que.push(temp->right);
    //             }

    //         }
    //         if(level%2 == 1){
    //             int l=0,r=levnode.size()-1;
    //             while(l<r){
    //                 int tempval=levnode[l]->val;
    //                 levnode[l]->val=levnode[r]->val;
    //                 levnode[r]->val=tempval;
    //                 l++;
    //                 r--;
    //             }
    //         }
    //         level++;
    //     }
    // return root;
    solve(root->left,root->right,1);
    return root;    
    }
};