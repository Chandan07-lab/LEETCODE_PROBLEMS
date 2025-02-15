class Solution {
public:
bool check(string &s,vector<vector<int>>&dp,int i,int num,int n){
    if(i==s.length()){
        return n==num;
    }

    if(num>n){
        return false;
    }
    if(dp[i][num]!=-1){
        return dp[i][num];
    }

    bool possible=false;

    for(int j=i;j<s.length();j++){
        string currstring=s.substr(i,j-i+1);
        int addnum=stoi(currstring);
        possible=possible || check(s,dp,j+1,num+addnum,n);
        if(possible){
            return true;
        }
    }
    return dp[i][num]=possible;
}


    int punishmentNumber(int n) {
        int punishmentno=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            vector<vector<int>>dp(s.size(),vector<int>(i+1,-1));
            if(check(s,dp,0,0,i)){
                punishmentno+=sq;
            }
        }
        return punishmentno;
    }
};