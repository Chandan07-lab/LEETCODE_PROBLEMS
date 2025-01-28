class Solution {
public:
int N ,m,n;
int dp[101][101];
bool solve(int i,int j,string& s1,string& s2,string& s3){
    if(i==m && j==n && i+j==N){
        return true;
    }

    if(i+j>=N){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    bool result=false;

    if(i<m &&s1[i]==s3[i+j]){
        result=solve(i+1,j,s1,s2,s3);
    }

    if(result){
        return dp[i][j];
    }

    if(j<n &&s2[j]==s3[i+j]){
        result=solve(i,j+1,s1,s2,s3);
    }

return dp[i][j]=result;
}
    bool isInterleave(string s1, string s2, string s3) {
        m=s1.size();
        n=s2.size();
        N=s3.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2,s3);
        
    }
};