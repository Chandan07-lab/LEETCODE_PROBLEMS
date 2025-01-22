class Solution {
public:
void solve(vector<int>&nums,vector<vector<int>>&result,vector<int>&sub,int idx){
    result.push_back(sub);

    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]) continue;

        sub.push_back(nums[i]);
        solve(nums,result,sub,i+1);
        sub.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int>sub;
    sort(nums.begin(),nums.end());
    solve(nums,result,sub,0);
        return result;
    }
};