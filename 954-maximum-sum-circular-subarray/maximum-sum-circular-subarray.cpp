class Solution {
public:
int solvemax(vector<int>&nums,int n){
    int currsum=nums[0];
    int sum=nums[0];
    for(int i=1;i<n;i++){
        currsum=max(nums[i],nums[i]+currsum);
        sum=max(sum,currsum);
    }

    return sum;
}

int solvemin(vector<int>&nums,int n){
    int currsum=nums[0];
    int sum=nums[0];
    for(int i=1;i<n;i++){
        currsum=min(nums[i],nums[i]+currsum);
        sum=min(sum,currsum);
    }

    return sum;
}

    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int maxsum=solvemax(nums,n);
        int minsum=solvemin(nums,n);

        int cirsum=sum-minsum;

        if(maxsum>0){
            return max(maxsum,cirsum);
        }

        return maxsum;
    }
};