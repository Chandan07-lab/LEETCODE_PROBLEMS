class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;

        int a=-1;
        int b=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }

        int N=n*n;

        for(int i=1;i<=N;i++){
            if(!mp.count(i)){
                b=i;
            }else if(mp[i]==2){
                a=i;
            }
        }

        if(a==-1 || b==-1){
            return {};
        }
        
        return {a,b};
    }
};