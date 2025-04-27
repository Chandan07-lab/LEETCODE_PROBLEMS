class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
        deque<int>de;

        for(int i=0;i<n;i++){
            while(!de.empty() && de.front()<=i-k){
                de.pop_front();
            }

            while(!de.empty() && nums[i]>nums[de.back()]){
                de.pop_back();
            }
            de.push_back(i);
            if(i>=k-1){
                result.push_back(nums[de.front()]);
            }

        }
        return result;
    }
};