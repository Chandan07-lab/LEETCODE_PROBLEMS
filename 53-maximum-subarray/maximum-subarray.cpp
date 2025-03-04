class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            currsum=max(nums[i],nums[i]+currsum);
            sum=max(currsum,sum);
        }
        return sum;
    }
};