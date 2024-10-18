class Solution {
public:
int csubset(int idx,int cor,vector<int>&nums,int maxor,vector<vector<int>>&t){
    if(idx==nums.size()){
        if(cor==maxor){
        return t[idx][cor]=1;
        }
        return t[idx][cor]=0;
    }
    if(t[idx][cor]!=-1){
        return t[idx][cor];
    }
    int tcount=csubset(idx+1,cor|nums[idx],nums,maxor,t);

    int ntcount=csubset(idx+1,cor,nums,maxor,t);

    return t[idx][cor]=tcount+ntcount;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(int&num:nums){
            maxor|=num;
        }
        int n=nums.size();
        vector<vector<int>>t(n+1,vector<int>(maxor+1,-1));
        int curror=0;
        return csubset(0,curror,nums,maxor,t);
        
    }
};