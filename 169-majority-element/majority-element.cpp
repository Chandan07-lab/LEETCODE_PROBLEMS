class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

            int count=0;
            int el;
        for(int i=0;i<n;i++){
            if(count==0){
                el=nums[i];
                count++;
            }
            else if(el==nums[i]) count++;
            else count--;
        }

        int count1=0;
        for(int i=0;i<n;i++){
            if(el==nums[i]){
                count1++;
            }
        }

        if(count1>=(n/2)) return el;
        else return -1;
        
    }
};