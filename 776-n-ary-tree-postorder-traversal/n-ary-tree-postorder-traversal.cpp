/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void tra(Node* root,vector<int> &p){
    if(root== NULL){
        return;
    }
for(int i=0;i<root->children.size();i++){
    tra(root->children[i],p);
}
    p.push_back(root->val);
}
    vector<int> postorder(Node* root) {
        vector<int>p;
        tra(root,p);
        return p;
    }
};