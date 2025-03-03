class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>result(n);

        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;

            if(st.empty()){
                result[idx]=-1;
            }else{
                while(!st.empty() && st.top()<=nums[idx]){
                    st.pop();
                }
                result[idx]=st.empty()?-1:st.top();
            }
            st.push(nums[idx]);
        }

        return result;
    }
};