class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int increasing=1;
        int decreasing=1;
        int result=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                increasing++;
                decreasing=1;
                result=max(result,increasing);
            }else if(nums[i]<nums[i-1]){
                decreasing++;
                increasing=1;
                result=max(result,decreasing);
            }else{
                decreasing=1;
                increasing=1;
            }
        }
        
        return result;
    }
};