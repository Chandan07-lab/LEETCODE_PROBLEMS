class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();

        vector<int>lesspivot;
        vector<int>equalpivot;
        vector<int>greaterpivot;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                lesspivot.push_back(nums[i]);
            }else if(nums[i]==pivot){
                equalpivot.push_back(nums[i]);
            }else{
                greaterpivot.push_back(nums[i]);
            }
        }
        
        for(auto a:equalpivot){
            lesspivot.push_back(a);
        }
    
    for(auto a:greaterpivot){
        lesspivot.push_back(a);
    }

return lesspivot;
    }
};