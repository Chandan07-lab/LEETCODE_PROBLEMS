class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi=arrays[0].front();
        int ma=arrays[0].back();
        int r=0;
        for(int i=1;i<arrays.size();i++){
            int cmin=arrays[i].front();
            int cmax=arrays[i].back();
            r=max({r,abs(cmin-ma),abs(cmax-mi)});

            ma=max(ma,cmax);
            mi=min(mi,cmin);
        }
        return r;
    }
};