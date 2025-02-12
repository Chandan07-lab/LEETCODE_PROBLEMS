class Solution {
public:
int getsum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }

    return sum;
}
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int result=-1;

        int mp[82]={0};
        for(int i=0;i<n;i++){
            int digitsum=getsum(nums[i]);
            if(mp[digitsum]>0){
                result=max(result,nums[i]+mp[digitsum]);
            }

            mp[digitsum]=max(mp[digitsum],nums[i]);

        }

        return result;
    }
};