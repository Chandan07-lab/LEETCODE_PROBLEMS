class Solution {
public:
bool isvalid(vector<int>&nums,int x,int shops){
    for(int &prod:nums){
        shops-=(prod+x-1)/x;

        if(shops<0){
            return false;
        }
    }
return true;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        sort(quantities.begin(),quantities.end());
        int l=1;
        int r=*max_element(begin(quantities),end(quantities));
        int re=0;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(isvalid(quantities,mid,n)){
            re=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
        }
        return re;
        }
};