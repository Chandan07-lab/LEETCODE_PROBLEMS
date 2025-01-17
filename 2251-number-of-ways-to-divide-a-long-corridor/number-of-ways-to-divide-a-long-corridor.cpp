class Solution {
public:
 const int M=1e9+7;
    int numberOfWays(string corridor) {
        vector<int>seatpos;
        int n=corridor.size();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                seatpos.push_back(i);
            }
        }

        if(seatpos.size()%2!=0 || seatpos.size()==0){
            return 0;
        }

        long long result=1;

        int prevseat=seatpos[1];
        for(int i=2;i<seatpos.size();i+=2){
            int l=seatpos[i]-prevseat;
            result=(result*l)%M;
            prevseat=seatpos[i+1];
        }
    return result;
    }
};