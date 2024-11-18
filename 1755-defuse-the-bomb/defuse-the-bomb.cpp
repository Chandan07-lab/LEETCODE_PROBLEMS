class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>result(n,0);
        if(k==0){
            return result;
        }
        int i=-1;
        int j=-1;
        if(k>0){
            i=1;
            j=k;
        }else{
            i=n-abs(k);
            j=n-1;
            
        }
        int windowsum=0;
        for(int point=i;point<=j;point++){
            windowsum+=code[point];
        }
        for(int k=0;k<n;k++){
            result[k]=windowsum;

            windowsum-=code[i%n];
            i++;
            windowsum+=code[(j+1)%n];
            j++;
        }
        return result;
    }
};