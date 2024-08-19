class Solution {
public:
int t[1001][1001];
int solve(int cura,int pca,int n){
    if(cura == n){
        return 0;
    }
    if(cura > n){
        return 1000;
    }
    if(t[cura][pca]!=-1){
        return t[cura][pca];
    }
    int cop=1+1+solve(cura+cura,cura,n);
    int p=1+solve(cura+pca,pca,n);

    return t[cura][pca]=min(cop,p);
}
    int minSteps(int n) {
        if(n==1)
        return 0;
        memset(t,-1,sizeof(t));

        return 1+solve(1,1,n);
    }
};

// int minSteps(int n){
//     if(n==1)
//     return 0;

//     if(n==2)
//     return 2;

// vector<int> t(n+1,0);
// t[o]=0;
// t[1]=0;
// t[2]=2;

// for(int i=3;i<=3;i++){
//     int factor=i/2;
//     while(factor>=1){
//         if(i%factor==0){
//             int strf=t[factor];
//             int ctf=1;
//             int pf=(i/factor)-1;

//             t[i]=t[factor] + ctf+pf;
//             break;
//         }
//         factor--;
//     }
// }
// return t[n];
// }
//Approach-3 (Greedy)
//T.C : O(n)
//S.C : O(1)
// class Solution {
// public:
//     int minSteps(int n) {
//         if(n == 1)
//             return 0;
// int remaining = n; //initially
//         int buffer    = 0;
//         int count_A   = 1; //initially we have 1 'A'
//         int steps     = 0;
// while (count_A < n) {
//             remaining = n - count_A;
//             if (remaining % count_A == 0) {
//                 buffer = count_A;
//                 count_A *= 2;
//                 steps += 2; // copy + paste
//             } else {
//                 count_A += buffer;
//                 steps++;
//             }
//         }
        
//         return steps;
//     }
// }







