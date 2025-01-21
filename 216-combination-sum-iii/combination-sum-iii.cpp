class Solution {
public:
void solve(int i,vector<vector<int>>&result,vector<int>&temp,int k,int n){
    if(n==0 && temp.size()==k){
        result.push_back(temp);
        return;
    }
    if(i>=10||n<0){
        return;
    }
    
    for(int idx=i;idx<=9;idx++){
        temp.push_back(idx);
        solve(idx+1,result,temp,k,n-idx);
        temp.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>>result;
         vector<int>temp;
         solve(1,result,temp,k,n);

        return result;
    }
};