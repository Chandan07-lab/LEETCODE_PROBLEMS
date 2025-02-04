class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxs=0;
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }else{
                maxs=max(sum,maxs);
                sum=nums[i];
            }
        }
        return max(maxs,sum);
    }
};