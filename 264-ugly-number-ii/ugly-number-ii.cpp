class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>t(n+1);
        t[1]=1 ;
        int i2;
        int i3;
        int i5;

        i2=i3=i5=1;

        for(int i=2;i<=n;i++){
            int i2thu=t[i2]*2;
            int i3rdu=t[i3]*3;
            int i5thu=t[i5]*5;

            t[i]=min({i2thu,i3rdu,i5thu});

            if(t[i] == i2thu)
            i2++;

            if(t[i] == i3rdu)
            i3++;

            if(t[i] == i5thu)
            i5++;
        }  
        return t[n];
     }
};

// unordered_map<int,bool> mp;
// bool isu(int n){
//     if(n<=0)
//     return false;

//     if(n==1)
//     return true;

//     if(mp.find(n)!=mp.end())
//     return mp[n];

//     if(n%2==0 && isu(n/2))
//     return mp[n]= true;

//     else if((n%3 && isu(n/3)))
//     return mp[n]=true;

//     else if((n%5 && isu(n/5)))
//     return mp[n]=true;


//     return mp[n]=false;
// }
// int nthUglyNumber(int n){
//     mp.clear();
//     int num=1;
//     while(n>0){
//         if(isUgly(num)){
//             n--;
//         }
//         num++;
//     }
//     return num-1;
// }


