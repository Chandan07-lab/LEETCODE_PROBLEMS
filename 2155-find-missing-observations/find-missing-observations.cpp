class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int m) {
        int n=rolls.size();
        int totalsum=(n+m)*mean;
        int currentsum=accumulate(rolls.begin(),rolls.end(),0);
        int missing=totalsum-currentsum;

        if(missing<m || missing>6*m){
            return {};
        }
vector<int> re(m,1);
missing-=m;
for(int i=0;i<m && missing>0;i++){
    int add=min(5,missing);
    re[i]+=add;
    missing-=add;
}
return re;
    }
};