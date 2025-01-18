class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int M=1e9+7;
        long long result=0;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%M;
        }
        for(int i=0;i<n;i++){
            result=(result +(long long) nums[i] *(power[i]-power[n-i-1]))%M;
        }

        return result;
    }
};