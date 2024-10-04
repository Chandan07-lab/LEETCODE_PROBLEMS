class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        // sort(skill.begin(),skill.end());
        // int i=0;
        // int j=n-1;
        // int s=skill[i]+skill[j];
        // long long chem=0;
        // while(i<j){
        //     int curskill=skill[i]+skill[j];
        //     if(curskill!=s){
        //         return -1;
        //     }
        //     chem+=(long long)skill[i]*(long long)skill[j];
        // i++;
        // j--;
        // }
        // return chem;
        vector<int>s(1001,0);
        int sum=0;
        for(int sk:skill){
            sum+=sk;
            s[sk]++;
        }
        int team=n/2;
        if(sum%team!=0){
            return -1;
        }
        int tar=sum/team;
        long long chem=0;

        for(int i=0;i<n;i++){
            int curskill=skill[i];
            int remain=tar-curskill;
            if(s[remain]<=0){
                return -1;
            }
            chem+=(long long)curskill*(long long)remain;
            s[remain]--;
        }

        return chem/2;
    }
};