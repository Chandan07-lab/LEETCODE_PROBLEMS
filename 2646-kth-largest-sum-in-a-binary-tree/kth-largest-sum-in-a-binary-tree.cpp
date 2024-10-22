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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long,vector<long>,greater<long>>pq;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            long levelsum=0;
            while(n--){
                TreeNode*pope=que.front();
                que.pop();
                levelsum+=pope->val;
                if(pope->left!=NULL){
                    que.push(pope->left);
                }
                if(pope->right!=NULL){
                    que.push(pope->right);
                }
            }
        
        pq.push(levelsum);

        if(pq.size()>k){
            pq.pop();
        }

        }
        return pq.size()<k?-1:pq.top()
 ;   }
};