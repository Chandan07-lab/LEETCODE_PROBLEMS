class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(auto v: logs){
            if(v=="../"){
                depth=max(0,depth-1);
            }else if(v=="./"){
                continue;
            }else{
                depth++;
            }
        }
        return depth;
    }

};