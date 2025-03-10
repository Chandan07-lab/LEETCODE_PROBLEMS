class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=0;

        unordered_set<int>st(nums.begin(),nums.end());

        for(auto num:st){
            if(st.find(num-1)==st.end()){
                int cnt=1;
                int x=num;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x+=1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};