class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>result;
        int to_remove=n-k;
        for(int i=0;i<n;i++){
            while(result.size()>0 && to_remove>0 && nums[i]<result.back()){
                result.pop_back();
                to_remove--;
            }
            result.push_back(nums[i]);
        }
        while(to_remove>0){
            result.pop_back();
            to_remove--;
        }
        
        return result;
    }
};