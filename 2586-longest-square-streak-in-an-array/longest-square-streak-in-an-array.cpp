class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mstreax=0;
        for(int &num:nums){
            int streax=0;
            long long curr=num;
            while(st.find(curr)!=st.end()){
                streax++;

                if(curr*curr>1e5){
                    break;
                }
                curr=curr*curr;
            }
            mstreax=max(mstreax,streax);
        }
        return mstreax < 2?-1:mstreax;
    }
};