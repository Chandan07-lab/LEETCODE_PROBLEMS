class Solution {
public:
typedef pair<int,int>p;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<p,vector<p>,greater<p>>occu;
        priority_queue<int,vector<int>,greater<int>> free;
        int  targetfriendarrival=times[targetFriend][0];

        sort(times.begin(),times.end());
        int chairno=0;

        for(int i=0;i<n;i++){
            int arrival=times[i][0];
            int depart=times[i][1];

            while(!occu.empty() && occu.top().first<=arrival){
                free.push(occu.top().second);
                occu.pop();
            }
            if(free.empty()){
                occu.push({depart,chairno});
            
            if(arrival == targetfriendarrival)
            return chairno;

            chairno++;
       } else{
            int least=free.top();
            free.pop();
            if(arrival == targetfriendarrival){
                return least;
            }
            occu.push({depart,least});
        }
        }

return -1;
    }
};