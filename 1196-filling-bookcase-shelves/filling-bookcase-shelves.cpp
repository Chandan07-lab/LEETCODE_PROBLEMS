// class Solution {
// public:
// int dp[1001][1001];
// int helper(vector<vector<int>>& b,int s,int i,int cw,int ch){
//     if(i>=b.size()){
//         return ch;
//     }
//     if(dp[i][cw]!=-1){
//         return dp[i][cw];
//     }
//     //new shelf
//     int ns=ch+helper(b,s,i+1,b[i][0],b[i][1]);
//     int ss=INT_MAX;
//     if(cw+b[i][0]<=s){
//         ss=helper(b,s,i+1,cw+b[i][0],max(ch,b[i][1]));
//     }
//     dp[i][cw]=min(ns,ss);
//     return dp[i][cw];
// }
//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
//         memset(dp,-1,sizeof(dp));
//         return helper(books,shelfWidth,0,0,0);
//     }
// };
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // Base case: no books, no height

        for (int i = 1; i <= n; ++i) {
            int width = 0, height = 0;
            for (int j = i - 1; j >= 0; --j) {
                width += books[j][0];
                if (width > shelf_width) break;
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + height);
            }
        }

        return dp[n];
    }
};