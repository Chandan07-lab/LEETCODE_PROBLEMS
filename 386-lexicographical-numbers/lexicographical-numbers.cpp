class Solution {
public:
void solve(int curr,int n,vector<int>&r){
    if(curr>n){
     return;
    }
    r.push_back(curr);
    for(int nextdi=0;nextdi<=9;nextdi++){
        int nextnum=curr*10+nextdi;
        if(nextnum>n){
            return;
        }
        solve(nextnum,n,r);
    }



}
    vector<int> lexicalOrder(int n) {
        vector<int>result;

        for(int i=1;i<=9;i++){
            solve(i,n,result);
        }
        return result;
    }
};