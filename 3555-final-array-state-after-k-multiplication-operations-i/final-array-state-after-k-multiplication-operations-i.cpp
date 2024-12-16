class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();

        vector<pair<int,int>>vec;

        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        make_heap(vec.begin(),vec.end(),greater<>());

        while(k--){
            pop_heap(vec.begin(),vec.end(),greater<>());
            auto temp=vec.back();
            vec.pop_back();

            int ele=temp.first;
            int ind=temp.second;

            nums[ind]=ele*multiplier;

            vec.push_back({nums[ind],ind});

            push_heap(vec.begin(),vec.end(),greater<>());

        }
return nums;
        
    }
};