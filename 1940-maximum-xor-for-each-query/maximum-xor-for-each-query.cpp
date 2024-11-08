class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>re(n);
        int x=0;

        for(int i=0;i<n;i++){
            x^=nums[i];
        }

        int mask=(1<<maximumBit)-1;
        for(int i=0;i<n;i++){
            int k=x^mask;
            re[i]=k;
            x=x^nums[n-i-1];
        }
         return re;
    }
};