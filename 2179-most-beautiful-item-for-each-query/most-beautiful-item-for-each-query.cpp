class Solution {
public:
    int binary(vector<vector<int>>& it, int qp){
        int l=0;
        int r=it.size()-1;
        int mid;
        int mb=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(it[mid][0]>qp){
                r=mid-1;
            }else{
                mb=max(mb,it[mid][1]);
                l=mid+1;
            }
        }
        return mb;
    }


    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int>re(m);

        sort(items.begin(),items.end());

        int mbeauty=items[0][1];

        for(int i=1;i<n;i++){
            mbeauty=max(mbeauty,items[i][1]);
            items[i][1]=mbeauty;
        }
        for(int i=0;i<m;i++){
            int query=queries[i];
            re[i]=binary(items,query);

        }
        return re;
    }
};