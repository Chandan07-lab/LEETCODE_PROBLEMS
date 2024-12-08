class Solution {
public:
int n;
int t[100001][3];
int binarysearch(vector<vector<int>>&events,int endtime){
    int l=0;
    int r=n-1;
    int result=n;
    while(l<=r){
        int mid=l+(r-l)/2;

        if(events[mid][0]>endtime){
            result=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return result;
}
int solve(vector<vector<int>>&events,int i,int count){
    if(count==2 || i>=n){
        return 0;
    }
    if(t[i][count]!=-1){
        return t[i][count];
    }
    int nextvalid=binarysearch(events,events[i][1]);
    int take=events[i][2]+solve(events,nextvalid,count+1);
    int nottake=solve(events,i+1,count);

    return t[i][count]=max(take,nottake);
}
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        sort(events.begin(),events.end());
        memset(t,-1,sizeof(t));
        int count=0;

        return solve(events,0,count);
        
    }
};