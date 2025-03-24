class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        multiset<int>mt;
        for(int i=0;i<k;i++){
            mt.insert(nums[i]);
        }
        ans.push_back(*(mt.rbegin()));
        for(int i=k;i<n;i++){
            mt.insert(nums[i]);
            auto it=mt.lower_bound(nums[i-k]);
            mt.erase(it);
            ans.push_back(*(mt.rbegin()));
        }
        return ans;
    }
};