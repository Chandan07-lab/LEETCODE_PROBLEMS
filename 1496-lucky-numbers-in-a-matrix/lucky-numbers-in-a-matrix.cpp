class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int rminmax=INT_MIN;
        for(int row=0;row<m;row++){
            int rmin=INT_MAX;
            for(int col=0;col<n;col++){
                rmin=min(rmin,matrix[row][col]);
            }
            rminmax=max(rminmax,rmin);
        }
        int cminmax=INT_MAX;
        for(int col=0;col<n;col++){
            int cmax=INT_MIN;
            for(int row=0;row<m;row++){
                cmax=max(cmax,matrix[row][col]);
            }
            cminmax=min(cmax,cminmax);
        }
        if(rminmax==cminmax){
            return {rminmax};
        }
        return {};
    }
};