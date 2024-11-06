class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int numsetbits=__builtin_popcount(nums[0]);
        int maxoffsegment=nums[0];
        int minoffsegment=nums[0];

        int maxprevsegment=INT_MIN;

        for(int i=1;i<nums.size();i++){
            if(__builtin_popcount(nums[i])==numsetbits){
                maxoffsegment=max(maxoffsegment,nums[i]);
                minoffsegment=min(minoffsegment,nums[i]);

            }else{
                if(minoffsegment<maxprevsegment){
                    return false;
                }
                maxprevsegment=maxoffsegment;
                maxoffsegment=nums[i];
                minoffsegment=nums[i];
                numsetbits=__builtin_popcount(nums[i]);
            }
        }
        if( minoffsegment<maxprevsegment){
            return false;
        }
        return true;
    }
};