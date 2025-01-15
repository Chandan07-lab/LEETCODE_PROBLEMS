class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        vector<int>peaks;
     for(int i=1;i<n-1;i++){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            peaks.push_back(i);
        }
     }
        return peaks;
    }
};