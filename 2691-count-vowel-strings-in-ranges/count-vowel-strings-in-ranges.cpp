class Solution {
public:
bool isvowel(char &ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;

    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q= queries.size();
        int n= words.size();
        vector<int>re(q);
        vector<int>cusum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(isvowel(words[i][0])&& isvowel(words[i].back())){
                sum++;
            }
            cusum[i]=sum;
        }

        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            re[i]=cusum[r]-((l>0)?cusum[l-1]:0);
        }

        return re;
    }
};