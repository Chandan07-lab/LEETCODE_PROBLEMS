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
bool findp(TreeNode* l,int t,string & path){
    if(l==NULL){
        return false;
    }
    if(l->val==t){
        return true;
    }
    path.push_back('L');
    if(findp(l->left,t,path)==true){
        return true;
    }
    path.pop_back();
     path.push_back('R');
        if(findp(l->right, t, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rtos="";
        string rtod="";
        findp(root,startValue,rtos);
        findp(root,destValue,rtod);
        int l=0;
        while(l<rtos.length() && l<rtod.length() && rtos[l]==rtod[l]){
            l++;
        }
        string r="";
        for(int i=0;i<rtos.length()-l;i++){
            r.push_back('U');
        }
        for(int i=l;i<rtod.length();i++){
            r.push_back(rtod[i]);
        }
        return r;
    }

};