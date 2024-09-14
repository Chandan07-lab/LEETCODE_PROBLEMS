class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv=0;
        int streak=0;
        int result=0;
        for(int &n:nums){
            if(n>maxv){
                maxv=n;
                result=0;
                streak=0;
            }
            if(n==maxv){
                streak++;
            }else{
                streak=0;
            }
            result=max(result,streak);
        }
    return result;
    }
};