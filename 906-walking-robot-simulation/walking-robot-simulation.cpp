class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>s;
        for(vector<int> &obs:obstacles){
            string key=to_string(obs[0])+"_"+to_string(obs[1]);
            s.insert(key);
        }
int x=0;
int y=0;
int maxd=0;
pair<int,int>dir{0,1};

for(int i=0;i<commands.size();i++){
    if(commands[i] == -2){
        dir={-dir.second,dir.first};
    }else if(commands[i]== -1){
        dir={dir.second,-dir.first};
    }else{
        for(int steps=0;steps<commands[i];steps++){
            int newx = x +dir.first;
            int newy= y +dir.second;

            string nextkey=to_string(newx)+"_"+to_string(newy);

            if(s.find(nextkey)!=s.end()){
                break;
            }
            x=newx;
            y=newy;
        }

    }
    maxd=max(maxd,x*x+y*y);
}
return maxd;
        
    }
};