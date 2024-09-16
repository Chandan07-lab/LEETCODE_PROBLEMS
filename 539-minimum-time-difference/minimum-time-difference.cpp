class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> mi(n);
        for(int i=0;i<n;i++){
            string t=timePoints[i];
            
            int hour=stoi(t.substr(0,2));
            int m=stoi(t.substr(3));
            mi[i]=(hour*60)+m;

        }
        sort(mi.begin(),mi.end());
        int result=INT_MAX;
        for(int i=1;i<n;i++){
            result=min(result,mi[i]-mi[i-1]);
        }
        return min(result,(24*60-mi[n-1])+mi[0]);
        
    }
};