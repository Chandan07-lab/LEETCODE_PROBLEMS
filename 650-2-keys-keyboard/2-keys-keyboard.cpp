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