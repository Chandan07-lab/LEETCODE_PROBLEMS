class Solution {
public:
int solve(int j,int k,unordered_map<int,int>&mp,vector<vector<int>>&dp,vector<int>&arr){
if(dp[j][k]!=-1){
    return dp[j][k];
}
int target=arr[k]-arr[j];
if(mp.count(target) && mp.at(target)<j){
    int i=mp.at(target);
    dp[j][k]=solve(i,j,mp,dp,arr)+1;
    return dp[j][k];
}

return dp[j][k]=2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }

        int maxi=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int length=solve(j,k,mp,dp,arr);
                if(length>=3){
                    maxi=max(maxi,length);

                }
            }
        }
        return maxi >= 3?maxi:0;
    }
};