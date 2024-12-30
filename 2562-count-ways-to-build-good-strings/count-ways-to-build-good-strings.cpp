class Solution {
public:
int L,h,z,o;
const int M=1e9+7;
int solve(int l,vector<int>&t){
    if(l>h){
        return 0;
    }
    if(t[l]!=-1){
        return t[l];
    }

    bool addone=false;
    if(l>=L && l<=h){
        addone=true;
    }

    int takezero=solve(l+z,t);
    int takeone=solve(l+o,t);

    return t[l]=(addone+takezero+takeone)%M;

}

    int countGoodStrings(int low, int high, int zero, int one) {
        L=low,h=high,z=zero,o=one;
        vector<int>t(high+1,-1);
        return solve(0,t);
    }
};