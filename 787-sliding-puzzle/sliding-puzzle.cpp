class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=to_string(board[i][j]);
            }
        }
        string tar="123450";
        queue<string>que;
        que.push(start);
        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={2,4};

        unordered_set<string>vis;
        vis.insert(start);
        int lev=0;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();

                if(curr== tar){
                    return lev;
                }
                int indofz=curr.find('0');
                for(int swapidx:mp[indofz]){
                    string newstate=curr;
                    swap(newstate[indofz],newstate[swapidx]);
                    if(vis.find(newstate)==vis.end()){
                        que.push(newstate);
                        vis.insert(newstate);
                    }
                }
            }
            lev++;
        }
        return -1;
        
    }
};