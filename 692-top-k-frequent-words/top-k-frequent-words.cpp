class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> v;
        unordered_map<string,int> mp;
        for(auto & w:words){
            mp[w]++;
        }
        for(auto &it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),[&](pair<int,string>p1,pair<int,string>p2){
            if(p1.first==p2.first)
            return p1.second<p2.second;

            return p1.first>p2.first;

        });
        int i=0;
        vector<string> r(k);
        while(i<k){
            r[i]=v[i].second;
            i++;
        }
        return r;
    }
};