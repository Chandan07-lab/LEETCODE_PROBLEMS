class Solution {
public:
int t[1001][201];
int solve(int idx,vector<int>&nums,int tar){
    if(tar==0){
        return 1;
    }
    if(idx>=nums.size()||tar<0){
        return 0;
    }

    if(t[tar][idx]!=-1){
        return t[tar][idx];
    }

    int take=solve(0,nums,tar-nums[idx]);
    int not_take=solve(idx+1,nums,tar);
    
    return t[tar][idx]=take+not_take;
}
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(0,nums,target);
        
    }
};