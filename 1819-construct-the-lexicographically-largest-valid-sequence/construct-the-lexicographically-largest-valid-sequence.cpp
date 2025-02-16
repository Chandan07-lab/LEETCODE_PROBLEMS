class Solution {
public:
bool solve(int i,int n,vector<int>&result,vector<int>&used){
        if(i>=result.size()){
            return true;
        }
        if(result[i]!=-1){
           return solve(i+1,n,result,used);
        }

        for(int s=n;s>=0;s--){
           if(used[s]){
            continue;
           }
           result[i]=s;
           used[s]=true;
           if(s==1){
            if(solve(i+1,n,result,used)){
                return true;
            }
        }else{
            int j=result[i]+i;
            if(j<result.size() && result[j]==-1){
                result[j]=s;
                if(solve(i+1,n,result,used)){
                    return true;
                }
                result[j]=-1;
            }
        }
            result[i]=-1;
            used[s]=false;

        }
return false;
}
    vector<int> constructDistancedSequence(int n) {
        vector<int>result(2*n-1,-1);
        vector<int>used(n+1,false);
        solve(0,n,result,used);
    return result;
    }
};