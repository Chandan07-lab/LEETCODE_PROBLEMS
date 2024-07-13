class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);//This will fill the array as -> 0, 1, 2, 3, 4, n-1
        stack<int> st;
        auto lambda=[&](int i,int j){
            return positions[i]<positions[j];
        };
        sort(begin(indices),end(indices),lambda);
        vector<int> result;
        for(int curind:indices){
            if(directions[curind]=='R'){
                st.push(curind);
            }else{
                while(!st.empty() && healths[curind]>0){
                    int topind=st.top();
                    st.pop();
                    if(healths[topind]>healths[curind]){
                        healths[topind]-=1;
                        healths[curind]=0;
                        st.push(topind);
                    }else if(healths[topind]<healths[curind]){
                        healths[curind]-=1;
                        healths[topind]=0;
                    }else{
                        healths[curind]=0;
                        healths[topind]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }
        return result;

    }
};