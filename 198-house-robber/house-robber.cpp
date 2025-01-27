class Solution {
public:
int t[101];
int solve(int idx,vector<int>&nums){
    if(idx==0) return nums[idx];

    if(idx<0) return 0;

    if(t[idx]!=-1){
        return t[idx];
    }

    int take=nums[idx]+solve(idx-2,nums);
    int nottake=0+solve(idx-1,nums);

    return t[idx]=max(take,nottake);
}

    int rob(vector<int>& nums) {
    memset(t,-1,sizeof(t));
        int n=nums.size();
        return solve(n-1,nums);
        
    }
};