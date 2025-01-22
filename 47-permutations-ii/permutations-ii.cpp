class Solution {
public:
vector<vector<int>>result;
int n;

void solve(unordered_map<int,int>&mp,vector<int>&temp){
    if(temp.size()==n){
        result.push_back(temp);
        return;
    }

    for(auto &[num,count]:mp){
        if(count==0){
            continue;
        }
        temp.push_back(num);
        mp[num]--;

        solve(mp,temp);

        temp.pop_back();
        mp[num]++;
    }

}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>temp;
        n=nums.size();

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        solve(mp,temp);
        return result;
    }
};