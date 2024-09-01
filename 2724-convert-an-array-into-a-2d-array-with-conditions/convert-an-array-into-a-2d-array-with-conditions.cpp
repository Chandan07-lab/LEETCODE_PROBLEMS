class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
int n=nums.size();
vector<int>mp(n+1);
vector<vector<int>>re;
for(int &num:nums){
    int freq=mp[num];
    if(freq==re.size()){
        re.push_back({});
    }
    re[freq].push_back(num);
    mp[num]++;
}
return re;
        
    }
};