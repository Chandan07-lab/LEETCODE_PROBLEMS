class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mp;
        long long result=0;
        for(int i=0;i<n;i++){
            int diff=nums[i]-i;
            
            int goodpair=mp[diff];
            
            int lastnumbers=i;
            
            result+=lastnumbers-goodpair;

            mp[diff]++;
        }

        return result;
    }
};