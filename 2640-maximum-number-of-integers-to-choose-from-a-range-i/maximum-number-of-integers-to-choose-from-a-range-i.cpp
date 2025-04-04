class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(banned.begin(),banned.end());
        int countt=0;
        int sum=0;

        for(int i=1;i<=n;i++){
            if(st.count(i)){
                continue;
            }

            if(sum+i<=maxSum){
                countt++;
                sum+=i;
            }else{
                break;
            }
        }
        return countt;
    }
};