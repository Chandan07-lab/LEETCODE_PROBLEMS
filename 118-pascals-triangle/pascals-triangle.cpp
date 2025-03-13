class Solution {
public:
vector<int>generaterow(int row){
    long long ans=1;
    vector<int>a;
    a.push_back(1);
    for(int i=1;i<row;i++){
        ans=(ans*(row-i))/i;
        a.push_back(ans);
    }
    return a;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>an;
        for(int i=1;i<=numRows;i++){
            an.push_back(generaterow(i));
        }
        
        return an;
    }
};