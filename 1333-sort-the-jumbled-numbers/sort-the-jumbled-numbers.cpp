class Solution {
public:
string gmn(string &n,vector<int>&mp){
    string m="";
    for(int i=0;i<n.length();i++){
        char ch=n[i];
        m+=to_string(mp[ch-'0']);
    }
    return m;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            string ns=to_string(nums[i]);
            string mapp=gmn(ns,mapping);;
            int mn=stoi(mapp);

            v.push_back({mn,i});
        }
        sort(begin(v),end(v));
        vector<int> r;
        for(auto &p: v){
            int ori=p.second;
            r.push_back(nums[ori]);
        }
        return r;
    }
};