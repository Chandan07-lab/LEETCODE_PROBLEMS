class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        if(k>=n){
            return n;
        }

        int result=0;
        int count=0;
        
        int i=0,j=0;

        while(i<n){
            if(nums[i]==0){
                count++;
            }

            if(count>k){
                count-=nums[j]==0?1:0;
                j++;
            }
            result=max(result,i-j+1);

            i++;
        }
        return result;
    }
};