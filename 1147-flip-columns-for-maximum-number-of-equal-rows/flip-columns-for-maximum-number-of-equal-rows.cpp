class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<string,int>mp;
        for(auto&row:matrix){
            string rownature="";
            int first=row[0];
            for(int col=0;col<n;col++){
                rownature+=(row[col]==first)?"s":"b";
            }
            mp[rownature]++;
        }
        int mrow=0;
        for(auto&it:mp){
            mrow=max(mrow,it.second);
        }
        return mrow;
    }
};