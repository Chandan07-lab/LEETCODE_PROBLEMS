class Solution {
public:
void solve(vector<int>&candidates,int t,vector<int>c,vector<vector<int>>&r,int id){
    if(t<0)
    return;

    if(t==0){
        r.push_back(c);
        return;
    }
    for(int i=id;i<candidates.size();i++){
        if(i>id && candidates[i]==candidates[i-1])
        continue;

        c.push_back(candidates[i]);
        solve(candidates,t-candidates[i],c,r,i+1);
        c.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> r;
        vector<int> c;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,c,r,0);

        return r;
    }
};