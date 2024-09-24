class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int& n:arr1){
            while(!st.count(n)&& n>0){
                st.insert(n);
                n/=10;
            }
        }
        int result=0;
        for(int &m:arr2){
            while(!st.count(m)&& m>0){
                m/=10;
            }
            if(m>0){
                result=max(result,static_cast<int>(log10(m))+1);

            }
        }
return result;
    }
};