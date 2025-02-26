class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int cursumax=nums[0];
        int cursumin=nums[0];
        int maxsum=nums[0];
        int minsum=nums[0];

        for(int i=1;i<n;i++){
            cursumax=max(nums[i],cursumax+nums[i]);
            maxsum=max(maxsum,cursumax);

            cursumin=min(nums[i],cursumin+nums[i]);
            minsum=min(minsum,cursumin);

        }
        
        return max(maxsum,abs(minsum));
    }
};