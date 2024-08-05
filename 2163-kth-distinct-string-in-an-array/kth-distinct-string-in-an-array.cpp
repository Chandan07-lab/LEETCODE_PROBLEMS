class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(auto& v:arr){
            if(m[v]==1)
                k--;

            if(k==0) return v;
        }
        return "";
    }
};